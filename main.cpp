/*
 * Hack Assembler
 * Created by Francois W. Nel on 27 Jun 2016.
 *
 * Description:
 *  The assembler converts Hack assembly instructions
 *  into machine code for the Hack computer architecture.
 *  Assembly instructions should be provided in a .asm source file,
 *  and the machine code will be stored in a .hack file
 *  with either the same filename, or using the provided
 *  filename and extension.
 *
 * Usage:
 *  $ chasm <inputfilename.asm> <(optional) outputfilename.hack>
 *
 * Limitations:
 *  Please ensure that there is a blank line at the end
 *  of your .asm source file.
 */

#include <iostream>
#include <fstream>
#include <bitset>
#include "Parser.h"
#include "CodeTranslator.h"
#include "SymbolTable.h"

using namespace std;

int main(int argc, char *argv[]) {
    string inputFileName, outputFileName;
    ofstream fout;
    int lineNumberROM, newAddress;
    unsigned long lineNumberSource;

    // Get the input and output file names, and provide usage instructions
    //  if too few or too many arguments are provided.
    if (argc < 2 || argc > 3) {
        cout << "Usage: " << argv[0] << " <inputfilename.asm> <(optional) outputfilename.hack>" << endl;
        exit(1);
    }
    else {
        inputFileName = argv[1];
        outputFileName = inputFileName.substr(0, inputFileName.length() - 4) + ".hack";
        if (argc == 3) {
            outputFileName = argv[2];
        }
    }

    // Create the output file
    fout.open(outputFileName);
    if (fout.fail()) {
        cout << "Failed to create output file." << endl;
        exit(1);
    }

    /*
     * First pass: Generate symbol table
     *  This is done by reading the input file line by line using the symbolSource parser,
     *  and looking for pseudo instructions. If an a-instruction or c-instruction is encountered,
     *  lineNumberROM is incremented, which ultimately corresponds to the program counter address
     *  of the instructions in the ROM / .hack output file. If an l-instruction is encountered
     *  and it does not already exist in the symbol table, the symbol and the current
     *  program counter address is stored in the symbol table.
     */

    Parser symbolSource(inputFileName);
    SymbolTable symbolTable;

    lineNumberSource = 0;
    lineNumberROM = 0;

    while (true) {
        symbolSource.advance(lineNumberSource);

        if (!symbolSource.hasMoreCommands()) {
            break;
        }

        if (symbolSource.commandType() == 'A' || symbolSource.commandType() == 'C') {
            lineNumberROM++;
        }

        if (symbolSource.commandType() == 'L' && !symbolTable.contains(symbolSource.symbol())) {
            symbolTable.addEntry(symbolSource.symbol(), lineNumberROM);
        }
    }

    /*
     * Second pass: Assemble machine code
     *  With the symbol table generated, we read the file line by line once more,
     *  this time using the assemblySource parser. Since the l-instructions have been dealt with,
     *  we are only looking for a-instructions and c-instructions.
     *
     *  If an a-instruction is encountered, the address can either be a number,
     *  a predefined symbol, or a user defined variable. If the address is a number,
     *  the string is converted to its numeric representation in decimal,
     *  which is then converted to binary and output to the file.
     *  If the address is a symbol, the corresponding address is either
     *  retrieved if it is a predefined symbol, or generated if it is a user defined variable,
     *  and this address is then converted into binary and output to the file.
     *
     *  If a c-instruction is encountered, the destination, computation and jump mnemonics
     *  are converted into binary code using the translator, and the resulting bit string
     *  is output to the file.
     */

    Parser assemblySource(inputFileName);
    CodeTranslator translator;

    lineNumberSource = 0; // Reset the line number for the error handling.
    newAddress = 16;    // Predefined symbols occupy addresses 0-15.

    while (true) {
        assemblySource.advance(lineNumberSource);

        if (!assemblySource.hasMoreCommands()) {
            break;
        }

        if (assemblySource.commandType() == 'A') {
            fout << '0';    // a-instructions always start with '0'.

            // Check if the symbol is a number.
            if (assemblySource.symbol().find_first_not_of("0123456789") == string::npos) {
                // Convert the string to a decimal number, convert the decimal number to a binary number.
                fout << bitset<15>(stoull(assemblySource.symbol(), nullptr)).to_string();
            }
            else {
                // Check if the symbol is a variable.
                if (!symbolTable.contains(assemblySource.symbol())) {
                    symbolTable.addEntry(assemblySource.symbol(), newAddress++);
                }
                // Retrieve the address, and convert the decimal number to a binary number.
                fout << bitset<15>(static_cast<unsigned long long>(symbolTable.getAddress(assemblySource.symbol()))).to_string();
            }
            fout << endl;
        }
        else if (assemblySource.commandType() == 'C') {
            fout << "111";  // c-instructions always start with "111".
            fout << translator.comp(assemblySource.compM(), lineNumberSource);
            fout << translator.dest(assemblySource.destM());
            fout << translator.jump(assemblySource.jumpM());
            fout << endl;
        }
    }

    fout.close();
    return 0;
}

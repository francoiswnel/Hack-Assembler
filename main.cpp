/*
 * Hack Assembler
 * Created by Francois W. Nel on 27 Jun 2016.
 * TODO: Documentation
 */

#include <iostream>
#include <fstream>
#include <bitset>
#include "Parser.h"
#include "CodeTranslator.h"
#include "SymbolTable.h"

using namespace std;

int main(int argc, char *argv[]) {
    string inputFileName, outputFileName, previousSymbol;
    ofstream fout;
    int lineNumberROM, newAddress;
    unsigned long lineNumberSource;

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

    fout.open(outputFileName);
    if (fout.fail()) {
        cout << "Failed to create output file." << endl;
        exit(1);
    }

    // First pass: Generate symbol table
    Parser symbolSource(inputFileName);
    SymbolTable symbolTable;

    lineNumberSource = 0;
    lineNumberROM = 0;
    newAddress = 16;

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

    // Second pass: Assemble machine code
    Parser assemblySource(inputFileName);
    CodeTranslator translator;

    lineNumberSource = 0;

    while (true) {
        assemblySource.advance(lineNumberSource);

        if (!assemblySource.hasMoreCommands()) {
            break;
        }

        if (assemblySource.commandType() == 'A') {
            fout << "0";
            if (assemblySource.symbol().find_first_not_of("0123456789") == string::npos) {
                fout << bitset<15>(stoull(assemblySource.symbol(), nullptr)).to_string();
            }
            else {
                if (!symbolTable.contains(assemblySource.symbol())) {
                    symbolTable.addEntry(assemblySource.symbol(), newAddress++);
                }
                fout << bitset<15>(static_cast<unsigned long long>(symbolTable.getAddress(assemblySource.symbol()))).to_string();
            }
            fout << endl;
        }
        else if (assemblySource.commandType() == 'C') {
            fout << "111";
            fout << translator.comp(assemblySource.compM(), lineNumberSource);
            fout << translator.dest(assemblySource.destM());
            fout << translator.jump(assemblySource.jumpM());
            fout << endl;
        }
    }

    fout.close();
    return 0;
}

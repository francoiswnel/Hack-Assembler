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
    string inputFileName, outputFileName, currentOutput;
    ofstream fout;

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

    Parser assemblySource(inputFileName);
    CodeTranslator translator;

    while (true) {
        assemblySource.advance();

        if (!assemblySource.hasMoreCommands()) {
            break;
        }

        if (assemblySource.commandType() == 'A') {
            fout << "0";
            fout << bitset<15>(stoull(assemblySource.symbol(), nullptr)).to_string();
            fout << endl;
        }
        else if (assemblySource.commandType() == 'C') {
            fout << "111";
            fout << translator.comp(assemblySource.compM());
            fout << translator.dest(assemblySource.destM());
            fout << translator.jump(assemblySource.jumpM());
            fout << endl;
        }
    }

    fout.close();
    return 0;
}

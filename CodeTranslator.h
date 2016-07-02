/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_CODE_H
#define HACK_ASSEMBLER_CODE_H

#include <iostream>
#include <map>

using namespace std;

class CodeTranslator {
public:
    CodeTranslator();
    // Populates the code translation map tables
    //  with the language specification.

    string dest(string destMnemonic, unsigned long& lineNr);
    // Returns the binary code of the destination mnemonic
    //  as a string containing 3 bits.
    // Line number is passed for use in an error message.

    string comp(string compMnemonic, unsigned long& lineNr);
    // Returns the binary code of the computation mnemonic
    //  as a string containing 7 bits.
    // Line number is passed for use in an error message.

    string jump(string jumpMnemonic, unsigned long& lineNr);
    // Returns the binary code of the jump mnemonic
    //  as a string containing 3 bits.
    // Line number is passed for use in an error message.
private:
    map<string, string> destTable;
    map<string, string> compTable;
    map<string, string> jumpTable;
};

#endif //HACK_ASSEMBLER_CODE_H

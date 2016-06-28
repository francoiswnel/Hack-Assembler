/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_CODE_H
#define HACK_ASSEMBLER_CODE_H

#include <iostream>

using namespace std;

class CodeTranslator {
public:
    string dest(string destMnemonic);
    // Returns the binary code of the destination mnemonic
    // as a string containing 3 bits.

    string comp(string compMnemonic);
    // Returns the binary code of the computation mnemonic
    // as a string containing 7 bits.


    string jump(string jumpMnemonic);
    // Returns the binary code of the jump mnemonic
    // as a string containing 3 bits.
};

#endif //HACK_ASSEMBLER_CODE_H

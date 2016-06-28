/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_CODE_H
#define HACK_ASSEMBLER_CODE_H

#include <iostream>

using namespace std;

class Code {
public:
    string dest(string destMnemonic);
    string comp(string compMnemonic);
    string jump(string jumpMnemonic);
};

#endif //HACK_ASSEMBLER_CODE_H

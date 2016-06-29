/*
 * Created by Francois W. Nel on 29 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_SYMBOLADDRESSPAIR_H
#define HACK_ASSEMBLER_SYMBOLADDRESSPAIR_H

#include <iostream>

using namespace std;

class SymbolAddressPair {
public:
    SymbolAddressPair(string sym, int add);
    string getSymbol();
    int getAddress();
private:
    string symbol;
    int address;
};

#endif //HACK_ASSEMBLER_SYMBOLADDRESSPAIR_H

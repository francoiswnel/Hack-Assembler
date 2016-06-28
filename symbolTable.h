/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_SYMBOLTABLE_H
#define HACK_ASSEMBLER_SYMBOLTABLE_H

#include <iostream>

using namespace std;

class SymbolTable {
public:
    SymbolTable();
    void addEntry(string symbol, int address);
    bool contains(string symbol);
    int getAddress(string symbol);
};

#endif //HACK_ASSEMBLER_SYMBOLTABLE_H

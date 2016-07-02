/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_SYMBOLTABLE_H
#define HACK_ASSEMBLER_SYMBOLTABLE_H

#include <iostream>
#include <functional>
#include "SymbolAddressPair.h"

using namespace std;

class SymbolTable {
public:
    SymbolTable();
    // Creates a new empty symbol table,
    //  and initialises it with the predefined symbols.
    // The amount of symbols available is limited to 1000
    // entries for practical reasons.

    void addEntry(string symbol, int address);
    // Adds the pair (symbol, address) to the table.

    bool contains(string symbol);
    // Returns true if the symbol table contains the given symbol,
    //  returns false otherwise.

    int getAddress(string symbol);
    // Returns the address associated with the given symbol.
private:
    SymbolAddressPair **table;
    hash<string> getHash;
};

#endif //HACK_ASSEMBLER_SYMBOLTABLE_H

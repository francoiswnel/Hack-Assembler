/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_SYMBOLTABLE_H
#define HACK_ASSEMBLER_SYMBOLTABLE_H

#include <iostream>
#include <map>

using namespace std;

class SymbolTable {
public:
    SymbolTable();
    // Initialise the symbol address map table
    //  with the predefined symbols.

    void addEntry(string symbol, int address);
    // Adds the pair (symbol, address) to the table.

    bool contains(string symbol);
    // Returns true if the symbol table contains the given symbol,
    //  returns false otherwise.

    int getAddress(string symbol);
    // Returns the address associated with the given symbol.
private:
    map<string, int> symbolAddressTable;
};

#endif //HACK_ASSEMBLER_SYMBOLTABLE_H

/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#include "SymbolTable.h"

const int SYMBOL_LIMIT = 1000;

using namespace std;

SymbolTable::SymbolTable() {
    table = new SymbolAddressPair*[SYMBOL_LIMIT];

    for (int i = 0; i < SYMBOL_LIMIT; i++) {
        table[i] = NULL;
    }

    addEntry("SP", 0);
    addEntry("LCL", 1);
    addEntry("ARG", 2);
    addEntry("THIS", 3);
    addEntry("THAT", 4);
    addEntry("R0", 0);
    addEntry("R1", 1);
    addEntry("R2", 2);
    addEntry("R3", 3);
    addEntry("R4", 4);
    addEntry("R5", 5);
    addEntry("R6", 6);
    addEntry("R7", 7);
    addEntry("R8", 8);
    addEntry("R9", 9);
    addEntry("R10", 10);
    addEntry("R11", 11);
    addEntry("R12", 12);
    addEntry("R13", 13);
    addEntry("R14", 14);
    addEntry("R15", 15);
    addEntry("SCREEN", 16384);
    addEntry("KBD", 24576);
}

void SymbolTable::addEntry(string symbol, int address) {
    int hashValue;

    hashValue = abs(int(getHash(symbol)) % SYMBOL_LIMIT);

    while(table[hashValue] != NULL) {
        hashValue = (hashValue + 1) % SYMBOL_LIMIT;
    }

    table[hashValue] = new SymbolAddressPair(symbol, address);
}

bool SymbolTable::contains(string symbol) {
    int hashValue, iterator;

    hashValue = abs(int(getHash(symbol)) % SYMBOL_LIMIT);
    iterator = 0;

    while(table[hashValue] != NULL && table[hashValue]->getSymbol().compare(symbol) != 0 && iterator < SYMBOL_LIMIT) {
        hashValue = (hashValue + 1) % SYMBOL_LIMIT;
        iterator++;
    }

    return table[hashValue] != NULL && table[hashValue]->getSymbol().compare(symbol) == 0;
}

int SymbolTable::getAddress(string symbol) {
    int hashValue;

    hashValue = abs(int(getHash(symbol)) % SYMBOL_LIMIT);

    while(table[hashValue] != NULL && table[hashValue]->getSymbol().compare(symbol) != 0) {
        hashValue = (hashValue + 1) % SYMBOL_LIMIT;
    }

    return table[hashValue]->getAddress();
}

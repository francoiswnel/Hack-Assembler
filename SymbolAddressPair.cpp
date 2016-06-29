//
// Created by Francois on 29 Jun 2016.
//

#include "SymbolAddressPair.h"

SymbolAddressPair::SymbolAddressPair(string sym, int add) {
    this->symbol = sym;
    this->address = add;
}

string SymbolAddressPair::getSymbol() {
    return symbol;
}

int SymbolAddressPair::getAddress() {
    return address;
}

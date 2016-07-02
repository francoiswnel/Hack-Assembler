/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_PARSER_H
#define HACK_ASSEMBLER_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Parser {
public:
    Parser(string& fileName);
    // Opens input file.
    // File is closed implicitly.

    bool hasMoreCommands();
    // Returns true if the file contains commands that still need to be parsed,
    //  returns false otherwise.

    void advance(unsigned long& lineNr);
    // Reads the next command to be parsed and sets it as the current command.
    // Should only be called if hasMoreCommands() returns true.
    // Line number is incremented for each line read,
    //  and is used for error information.

    char commandType(unsigned long& lineNr);
    // Returns the type of the current command.
    // Returns 'A' for an A-instruction.
    // Returns 'C' for a C-instruction.
    // Returns 'L' for a label.
    // Line number is used for error information.

    string symbol();
    // Returns the symbol or decimal value of the current command.
    // Should only be called if commandType() returns 'A' or 'L'.

    string destM();
    // Returns the destination mnemonic of the current command.
    // Should only be called if commandType() returns 'C'.

    string compM();
    // Returns the computation mnemonic of the current command.
    // Should only be called if commandType() returns 'C'.

    string jumpM();
    // Returns the jump mnemonic of the current command.
    // Should only be called if commandType() returns 'C'.
private:
    ifstream fin;
    string currentCommand;
    map<char, char> commandTable;
};

#endif //HACK_ASSEMBLER_PARSER_H

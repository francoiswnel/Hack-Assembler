/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#ifndef HACK_ASSEMBLER_PARSER_H
#define HACK_ASSEMBLER_PARSER_H

#include <iostream>
#include <fstream>

using namespace std;

class Parser {
public:
    Parser(ifstream& fin);
    bool hasMoreCommands();
    void advance();
    char commandType();
    string symbol();
    string destM();
    string compM();
    string jumpM();
};

#endif //HACK_ASSEMBLER_PARSER_H

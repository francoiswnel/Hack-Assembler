/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#include "Parser.h"

using namespace std;

Parser::Parser(ifstream& fin) {

}

bool Parser::hasMoreCommands() {
    return false;
}

void Parser::advance() {

}

char Parser::commandType() {
    return 0;
}

string Parser::symbol() {
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}

string Parser::destM() {
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}

string Parser::compM() {
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}

string Parser::jumpM() {
    return std::basic_string<char, char_traits<char>, allocator<char>>();
}
















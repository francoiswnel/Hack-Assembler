/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#include "Parser.h"

using namespace std;

Parser::Parser(string& fileName) {
    fin.open(fileName);
    if (fin.fail()) {
        cout << fileName << " not found." << endl;
        exit(1);
    }
}

bool Parser::hasMoreCommands() {
    return !fin.eof();
}

void Parser::advance(unsigned long& lineNr) {
    string currentLine;
    unsigned long commentPos;
    bool commandFound;

    commandFound = false;

    while (!commandFound && getline(fin, currentLine)) {
        lineNr++;

        // Remove whitespace
        currentLine.erase(remove_if(currentLine.begin(), currentLine.end(), ::isspace), currentLine.end());

        // Remove comments
        commentPos = currentLine.find("//");
        if (commentPos != string::npos) {
            currentLine.erase(commentPos, currentLine.length() - commentPos);
        }

        commandFound = !currentLine.empty();
    }

    currentCommand = currentLine;
}

char Parser::commandType() {
    switch(toupper(currentCommand[0])) {
        case '@':
            return 'A';
        case 'A':
        case 'D':
        case 'M':
        case '0':
        case '1':
        case '-':
        case '!':
            return 'C';
        default:
            return 'L';
    }
}

string Parser::symbol() {
    unsigned long openBracketPos, closeBracketPos;

    openBracketPos = currentCommand.find('(');
    closeBracketPos = currentCommand.find(')');

    if (commandType() == 'A') {
        return currentCommand.substr(1, currentCommand.length() - 1);
    }
    else if (openBracketPos != string::npos && closeBracketPos != string::npos) {
        return currentCommand.substr(openBracketPos + 1, closeBracketPos - openBracketPos - 1);
    }

    return "";
}

string Parser::destM() {
    unsigned long equalSignPos;

    equalSignPos = currentCommand.find('=');

    if (equalSignPos != string::npos) {
        return currentCommand.substr(0, equalSignPos);
    }

    return "";
}

string Parser::compM() {
    unsigned long equalSignPos, semiColonPos;

    equalSignPos = currentCommand.find('=');
    semiColonPos = currentCommand.find(';');

    if (equalSignPos != string::npos) {
        if (semiColonPos != string::npos) {
            // Case 1: dest = comp ; jump
            return currentCommand.substr(equalSignPos + 1, semiColonPos - equalSignPos - 1);
        }
        // Case 2: dest = comp
        return currentCommand.substr(equalSignPos + 1, currentCommand.length() - equalSignPos - 1);
    }
    else if (semiColonPos != string::npos) {
        // Case 3: comp ; jump
        return currentCommand.substr(0, semiColonPos);
    }

    return "";
}

string Parser::jumpM() {
    unsigned long semiColonPos;

    semiColonPos = currentCommand.find(';');

    if (semiColonPos != string::npos) {
        return currentCommand.substr(semiColonPos + 1, currentCommand.length() - semiColonPos - 1);
    }

    return "";
}

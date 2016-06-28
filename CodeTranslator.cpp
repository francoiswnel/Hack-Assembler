/*
 * Created by Francois W. Nel on 27 Jun 2016.
 */

#include "CodeTranslator.h"

using namespace std;

string CodeTranslator::dest(string destMnemonic) {
    if (destMnemonic.compare("M") == 0) {
        return "001";
    }
    else if (destMnemonic.compare("D") == 0) {
        return "010";
    }
    else if (destMnemonic.compare("MD") == 0) {
        return "011";
    }
    else if (destMnemonic.compare("A") == 0) {
        return "100";
    }
    else if (destMnemonic.compare("AM") == 0) {
        return "101";
    }
    else if (destMnemonic.compare("AD") == 0) {
        return "110";
    }
    else if (destMnemonic.compare("AMD") == 0) {
        return "111";
    }
    return "000";
}

string CodeTranslator::comp(string compMnemonic, unsigned long& lineNr) {
    if (compMnemonic.compare("0") == 0) {
        return "0101010";
    }
    else if (compMnemonic.compare("1") == 0) {
        return "0111111";
    }
    else if (compMnemonic.compare("-1") == 0) {
        return "0111010";
    }
    else if (compMnemonic.compare("D") == 0) {
        return "0001100";
    }
    else if (compMnemonic.compare("A") == 0) {
        return "0110000";
    }
    else if (compMnemonic.compare("!D") == 0) {
        return "0001101";
    }
    else if (compMnemonic.compare("!A") == 0) {
        return "0110001";
    }
    else if (compMnemonic.compare("-D") == 0) {
        return "0001111";
    }
    else if (compMnemonic.compare("-A") == 0) {
        return "0110011";
    }
    else if (compMnemonic.compare("D+1") == 0) {
        return "0011111";
    }
    else if (compMnemonic.compare("A+1") == 0) {
        return "0110111";
    }
    else if (compMnemonic.compare("D-1") == 0) {
        return "0001110";
    }
    else if (compMnemonic.compare("A-1") == 0) {
        return "0110010";
    }
    else if (compMnemonic.compare("D+A") == 0) {
        return "0000010";
    }
    else if (compMnemonic.compare("D-A") == 0) {
        return "0010011";
    }
    else if (compMnemonic.compare("A-D") == 0) {
        return "0000111";
    }
    else if (compMnemonic.compare("D&A") == 0) {
        return "0000000";
    }
    else if (compMnemonic.compare("D|A") == 0) {
        return "0010101";
    }
    else if (compMnemonic.compare("M") == 0) {
        return "1110000";
    }
    else if (compMnemonic.compare("!M") == 0) {
        return "1110001";
    }
    else if (compMnemonic.compare("-M") == 0) {
        return "1110011";
    }
    else if (compMnemonic.compare("M+1") == 0) {
        return "1110111";
    }
    else if (compMnemonic.compare("M-1") == 0) {
        return "1110010";
    }
    else if (compMnemonic.compare("D+M") == 0) {
        return "1000010";
    }
    else if (compMnemonic.compare("D-M") == 0) {
        return "1010011";
    }
    else if (compMnemonic.compare("M-D") == 0) {
        return "1000111";
    }
    else if (compMnemonic.compare("D&M") == 0) {
        return "1000000";
    }
    else if (compMnemonic.compare("D|M") == 0) {
        return "1010101";
    }

    cout << "Invalid syntax in computation statement at line: " << lineNr << endl;
    exit(1);
}

string CodeTranslator::jump(string jumpMnemonic) {
    if (jumpMnemonic.compare("JGT") == 0) {
        return "001";
    }
    else if (jumpMnemonic.compare("JEQ") == 0) {
        return "010";
    }
    else if (jumpMnemonic.compare("JGE") == 0) {
        return "011";
    }
    else if (jumpMnemonic.compare("JLT") == 0) {
        return "100";
    }
    else if (jumpMnemonic.compare("JNE") == 0) {
        return "101";
    }
    else if (jumpMnemonic.compare("JLE") == 0) {
        return "110";
    }
    else if (jumpMnemonic.compare("JMP") == 0) {
        return "111";
    }
    return "000";
}

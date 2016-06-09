//
// Created by joakim on 6/9/16.
//

#include "lexer.h"

void run_lexer(ifstream & file) {
    char ch;
    while (file.get(ch)) {
        cout << tokenMatch(ch, file).toString() + " ";
    }
}

Token tokenMatch(char & ch, ifstream & file) {
    while( (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') && file.get(ch)) {

    }

    switch (ch) {


        default: return findID(ch, file);
    }
}

Token findID(char & ch, ifstream & file) {
    if(isalpha(ch)) {
        string b;
        while(isalpha(ch) || isdigit(ch)) {
            b += ch;
            file.get(ch);
        }
        auto found = keywords.find(b);
        if(found != keywords.end()) {
            return Token(found->second);
        }
    }
    return Token(BAD);
}
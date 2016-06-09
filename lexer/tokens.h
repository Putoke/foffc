//
// Created by joakim on 6/9/16.
//

#ifndef FOFFC_TOKENS_H
#define FOFFC_TOKENS_H

#include <string>
#include <ostream>

using namespace std;

enum TokenKind {
    METHOD,
    BAD,
    ENOF
};

string tokenKindToString(TokenKind kind);

class Token {
public:
    Token(TokenKind k) {kind = k;};
    TokenKind kind;
    string toString() {return tokenKindToString(kind);};
};

#endif //FOFFC_TOKENS_H

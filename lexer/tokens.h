//
// Created by joakim on 6/9/16.
//

#ifndef FOFFC_TOKENS_H
#define FOFFC_TOKENS_H

#include <string>
#include <ostream>

using namespace std;

enum TokenKind {
    BAD,
    ENOF,
    COLON,
    SEMICOLON,
    DOT,
    COMMA,
    EQSIGN,
    EQUALS,
    BANG,
    LPAREN,
    RPAREN,
    LBRACKET,
    RBRACKET,
    LBRACE,
    RBRACE,
    AND,
    OR,
    LESSTHAN,
    PLUS,
    MINUS,
    TIMES,
    DIV,
    CLASS,
    METHOD,
    VAR,
    UNIT,
    STRING,
    EXTENDS,
    INT,
    BOOLEAN,
    WHILE,
    IF,
    ELSE,
    LENGTH,
    TRUE,
    FALSE,
    SELF,
    NEW,
    PRINTLN,
    STROF,
    FOREIGN,
    AS,
    IDKIND
};

string tokenKindToString(TokenKind kind);

class Token {
public:
    TokenKind kind;
    Token(TokenKind k) {kind = k;};
    virtual ~Token() {};
    virtual string toString() {return tokenKindToString(kind);};
};

class ID : public Token {
public:
    string value;
    ID(string v) : Token(IDKIND) {value = v;};
    virtual string toString() {return "ID("+value+")";};
};

#endif //FOFFC_TOKENS_H

//
// Created by joakim on 6/9/16.
//

#ifndef FOFFC_LEXER_H
#define FOFFC_LEXER_H

#include "tokens.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<string, TokenKind> keywords = {{"class", CLASS}, {"method", METHOD}, {"var", VAR}, {"unit", UNIT},
                                         {"String", STRING}, {"extends", EXTENDS}, {"int", INT}, {"bool", BOOLEAN},
                                         {"while", WHILE}, {"if", IF}, {"else", ELSE}, {"length", LENGTH},
                                         {"true", TRUE}, {"false", FALSE}, {"self", SELF}, {"new", NEW},
                                         {"println", PRINTLN}, {"strof", STROF}, {"foreign", FOREIGN}, {"as", AS}};

void run_lexer(ifstream & file);
Token * tokenMatch(char & ch, ifstream & file);
Token * findID(char & ch, ifstream & file);

#endif //FOFFC_LEXER_H

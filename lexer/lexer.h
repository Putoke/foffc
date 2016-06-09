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

const map<string, TokenKind> keywords = {{"method", METHOD}};

void run_lexer(ifstream & file);
Token tokenMatch(char & ch, ifstream & file);
Token findID(char & ch, ifstream & file);

#endif //FOFFC_LEXER_H

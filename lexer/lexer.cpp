//
// Created by joakim on 6/9/16.
//

#include "lexer.h"

void run_lexer(ifstream & file) {
    char ch;
    while (file.get(ch)) {
        Token * token = tokenMatch(ch, file);
        cout << token->toString() + " ";
        delete token;
    }
}

Token * tokenMatch(char & ch, ifstream & file) {
    while ((ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') && !file.eof()) {
        file.get(ch);
    }

    switch (ch) {
        case ':':       return new Token(COLON) ;
        case ';':       return new Token(SEMICOLON);
        case '.':       return new Token(DOT);
        case ',':       return new Token(COMMA);
        case '!':       return new Token(BANG);
        case '(':       return new Token(LPAREN);
        case ')':       return new Token(RPAREN);
        case '[':       return new Token(LBRACKET);
        case ']':       return new Token(RBRACKET);
        case '{':       return new Token(LBRACE);
        case '}':       return new Token(RBRACE);
        case '<':       return new Token(LESSTHAN);
        case '+':       return new Token(PLUS);
        case '-':       return new Token(MINUS);
        case '*':       return new Token(TIMES);

        case '/':
            file.get(ch);
            if (ch == '/') {
                while (file.peek() != '\n') {
                    file.get(ch);
                }
                file.get(ch); //One extra time to skip the newline
                return tokenMatch(ch, file);
            } else if (ch == '*') {
                while (file.get(ch)) {
                    if (ch == '*') {
                        file.get(ch);
                        if (ch == '/') {
                            file.get(ch);
                            return tokenMatch(ch, file);
                        }
                    }
                }
            }
            return new Token(DIV);

        case '=':
            file.get(ch);
            if (ch == '=')
                return new Token(EQUALS);
            file.seekg (-1, file.cur); //Move file pointer back one step so the loop won't miss a char
            return new Token(EQSIGN);

        case '&':
            file.get(ch);
            if (ch == '&')
                return new Token(AND);
            file.seekg (-1, file.cur); //Move file pointer back one step so the loop won't miss a char
            return new Token(BAD);

        case '|':
            file.get(ch);
            if (ch == '|')
                return new Token(OR);
            file.seekg (-1, file.cur); //Move file pointer back one step so the loop won't miss a char
            return new Token(BAD);

        default: return findID(ch, file);
    }
}

Token * findID (char & ch, ifstream & file) {
    if (isalpha (ch)) {
        string b;
        while (isalpha (ch) || isdigit (ch) || ch == '_') {
            b += ch;
            file.get(ch);
        }
        auto found = keywords.find(b);
        file.seekg (-1, file.cur); //Move file pointer back one step so the loop won't miss a char
        if (found != keywords.end()) {
            return new Token (found->second);
        } else {
            return new ID (b);
        }
    }
    if (isdigit (ch)) {
        string b;
        while (isdigit (ch)) {
            b += ch;
            file.get (ch);
        }
        return new INTLIT (atoi (b.c_str ()));
    }
    if (ch == '"') {
        string b;
        file.get (ch);
        while (ch != '"') {
            b += ch;
            file.get (ch);
        }
        return new STRLIT (b);
    }
    if (file.eof ())
        return new Token(ENOF);
    return new Token(BAD);
}
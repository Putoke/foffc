//
// Created by joakim on 6/9/16.
//

#include "tokens.h"

string tokenKindToString(TokenKind kind) {
    switch (kind) {
        case BAD:       return "bad";
        case ENOF:      return "eof";
        case COLON:     return "colon";
        case SEMICOLON: return "semicolon";
        case DOT:       return "dot";
        case COMMA:     return "comma";
        case EQSIGN:    return "eqsign";
        case EQUALS:    return "equals";
        case BANG:      return "bang";
        case LPAREN:    return "lparen";
        case RPAREN:    return "rparen";
        case LBRACKET:  return "lbracket";
        case RBRACKET:  return "rbracket";
        case LBRACE:    return "lbrace";
        case RBRACE:    return "rbrace";
        case AND:       return "and";
        case OR:        return "or";
        case LESSTHAN:  return "lessthan";
        case PLUS:      return "plus";
        case MINUS:     return "minus";
        case TIMES:     return "times";
        case DIV:       return "div";
        case CLASS:     return "class";
        case METHOD:    return "method";
        case VAR:       return "var";
        case UNIT:      return "unit";
        case STRING:    return "string";
        case EXTENDS:   return "extends";
        case INT:       return "int";
        case BOOLEAN:   return "boolean";
        case WHILE:     return "while";
        case IF:        return "if";
        case ELSE:      return "else";
        case LENGTH:    return "length";
        case TRUE:      return "true";
        case FALSE:     return "false";
        case SELF:      return "self";
        case NEW:       return "new";
        case PRINTLN:   return "println";
        case STROF:     return "strof";
        case FOREIGN:   return "foreign";
        case AS:        return "as";
        case IDKIND:    return "idkind";
        case INTLITKIND:return "intlitkind";
        case STRLITKIND:return "strlitkind";
        default:        return "";
    }
}
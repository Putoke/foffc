//
// Created by joakim on 6/9/16.
//

#include "tokens.h"

string tokenKindToString(TokenKind kind) {
    switch (kind) {
        case METHOD:    return "method";
        case BAD:       return "bad";
        case ENOF:      return "eof";
        default:        return "";
    }
}
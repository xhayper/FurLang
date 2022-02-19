#include "token.hpp"

Token::Token(TokenType type, char *value) {
    this->type = type;
    this->value = value;
}
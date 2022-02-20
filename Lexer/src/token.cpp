#include "token.hpp"

Token::Token(TokenType type, std::string value) {
    this->type = type;
    this->value = value;
}
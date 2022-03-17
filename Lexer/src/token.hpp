#pragma once

#include "string"

enum TokenType
{
    IDENTIFIER,
    KEYWORD,
    SEPERATOR,
    OPERATOR,
    LITERAL,
    COMMENT,
    UNKNOWN,
};

class Token
{
public:
    Token(TokenType type, std::string value);
    TokenType type;
    std::string value;
};
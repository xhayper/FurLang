#include "string"
#ifndef TOKEN_H

enum TokenType
{
    IDENTIFIER,
    KEYWORD,
    SEPERATOR,
    OPERATOR,
    LITERAL,
    COMMENT
};

class Token
{
public:
    Token(TokenType type, std::string value);
    TokenType type;
    std::string value;
};
#endif
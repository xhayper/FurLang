#ifndef TOKEN_H
#define TOKEN_H

enum TokenType {
    IDENTIFIER,
    KEYWORD,
    SEPERATOR,
    OPERATOR,
    LITERAL,
    COMMENT
};

class Token {
    public:
        Token(TokenType type, char* value);
        TokenType type;
        char* value;
};

#endif
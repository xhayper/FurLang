#include <map>
#include "string"
#include "token.hpp"
#ifndef LEXER_H

using namespace std;

class Lexer
{
public:
    void scan(string line, Token *out[]);

private:
    bool isIdentifier(char word[]);
    bool isKeyword(char word[]);
    bool isSeperator(char word[]);
    bool isOperator(char word[]);
    bool isLiteral(char word[]);
    bool isComment(char word[]);
    TokenType getTokenType(char word[]);
};
#endif
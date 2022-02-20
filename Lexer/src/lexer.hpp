#include "map"
#include "string"
#include "cstring"
#include "iostream"
#include "regex"

#include "token.hpp"
#ifndef LEXER_H

using namespace std;

class Lexer
{
public:
    void scan(string line, vector<Token> &out);

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
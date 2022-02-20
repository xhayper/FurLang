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
    bool isIdentifier(string word);
    bool isKeyword(string word);
    bool isSeperator(string word);
    bool isOperator(string word);
    bool isLiteral(string word);
    bool isComment(string word);
    TokenType getTokenType(string word);
};
#endif
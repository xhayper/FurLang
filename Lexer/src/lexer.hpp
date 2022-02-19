#include <map>
#include "token.hpp"
#ifndef LEXER_H

using namespace std;

class Lexer
{
public:
    void scan(char *line, Token *& out);
private:
    bool isIdentifier();
    bool isKeyword();
    bool isSeperator();
    bool isOperator();
    bool isLiteral();
    bool isComment();
};
#endif
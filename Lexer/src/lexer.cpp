#include "lexer.hpp"

using namespace std;

void Lexer::scan(char line[], Token *out[])
{
    Token tokenList[] = {Token(TokenType::COMMENT, line)};
    *out = tokenList;
};
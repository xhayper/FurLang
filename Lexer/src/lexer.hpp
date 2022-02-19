#ifndef LEXER_H
#include <map>
#include "token.hpp"

using namespace std;

typedef bool Scanner(char *line, char *word);

class Lexer
{
public:
    Lexer();

    void addScanner(TokenType tokenType, Scanner scanner);

    Token *scan(char *line);

private:
    map<TokenType, Scanner *> scannerMap;
};
#endif
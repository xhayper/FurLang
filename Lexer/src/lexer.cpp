#include <map>
#include "lexer.hpp"

using namespace std;

Lexer::Lexer() {};

void Lexer::addScanner(TokenType tokenType, Scanner scanner)
{
    this->scannerMap.insert_or_assign(tokenType, scanner);
};

Token *Lexer::scan(char *line)
{
    return new Token(TokenType::COMMENT, line);
};
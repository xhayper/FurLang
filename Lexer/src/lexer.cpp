#include <iostream>
#include "lexer.hpp"

using namespace std;

void Lexer::addScanner(TokenType tokenType, Scanner scanner) {
    this->scannerMap.insert_or_assign(tokenType, scanner);
}

Token* scan(char line[]) {
    return new Token(TokenType::COMMENT, line);
};
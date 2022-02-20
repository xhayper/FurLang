#include "lexer.hpp"
#include "iostream"
#include "cstring"

using namespace std;

TokenType Lexer::getTokenType(char word[])
{
    if (this->isIdentifier(word))
        return TokenType::IDENTIFIER;
    if (this->isKeyword(word))
        return TokenType::KEYWORD;
    if (this->isSeperator(word))
        return TokenType::SEPERATOR;
    if (this->isOperator(word))
        return TokenType::OPERATOR;
    if (this->isLiteral(word))
        return TokenType::LITERAL;
    if (this->isComment(word))
        return TokenType::COMMENT;
    throw invalid_argument("Invalid token caught!");
}

void Lexer::scan(string line, Token *out[])
{
    char charArray[line.length() + 1];
    strcpy(charArray, line.c_str());
    Token tokenList[] = {};
    char word[256];
    int index = 0;
    int wordIndex = 0;
    while (1)
    {
        if (index >= sizeof(charArray))
            break;
        while (charArray[index] != '\n' && charArray[index] != ' ' && charArray[index] != '\0')
        {
            word[wordIndex++] = charArray[index++];
        }
        word[wordIndex] = '\0';
        // Start
        TokenType tokenType = this->getTokenType(word);
        // End
        *word = {};
        wordIndex = 0;
        index++;
    }
    *out = tokenList;
};

// Tester

bool Lexer::isIdentifier(char word[])
{
    return false;
}

bool Lexer::isKeyword(char word[])
{
    return false;
}

bool Lexer::isSeperator(char word[])
{
    return false;
}

bool Lexer::isOperator(char word[])
{
    return false;
}

bool Lexer::isLiteral(char word[])
{
    return false;
}

bool Lexer::isComment(char word[])
{
    return false;
}
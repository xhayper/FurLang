#include "lexer.hpp"

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

void Lexer::scan(string source, vector<Token> &out)
{
    char charArray[source.length() + 1];
    strcpy(charArray, source.c_str());
    vector<Token> tokenVector;
    string word;
    int index = 0;
    int wordIndex = 0;
    while (1)
    {
        if (index >= sizeof(charArray))
            break;
        vector<char> tempWordList;
        while (charArray[index] != '\n' && charArray[index] != ' ' && charArray[index] != '\0')
        {
            tempWordList.push_back(charArray[index++]);
        }
        tempWordList.push_back('\0');
        word = string(tempWordList.data());
        char wordChar[word.length()+1];
        strcpy(wordChar, word.c_str());

        TokenType tokenType = this->getTokenType(wordChar);
        tokenVector.push_back(Token(tokenType, word));

        word = "";
        wordIndex = 0;
        index++;
    }
    out = tokenVector;
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
    return regex_match(word, regex("\\d")) >= 1;
}

bool Lexer::isComment(char word[])
{
    return false;
}
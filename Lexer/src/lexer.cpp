#include "lexer.hpp"

TokenType Lexer::getTokenType(string word)
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
    int line = 1;
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
        tempWordList.clear();

        TokenType tokenType = this->getTokenType(word);
        tokenVector.push_back(Token(tokenType, word));

        if (charArray[index] == '\n')
            line++;
        word = "";
        wordIndex = 0;
        index++;
    }
    out = tokenVector;
};

bool stringStartsWith(string in, string find)
{
    return in.substr(0, find.size()) == find;
}

bool Lexer::isIdentifier(string word)
{
    return false;
}

bool Lexer::isKeyword(string word)
{
    return false;
}

bool Lexer::isSeperator(string word)
{
    return false;
}

bool Lexer::isOperator(string word)
{
    return false;
}

bool Lexer::isLiteral(string word)
{
    return regex_match(word, regex("\\d")) >= 1;
}

bool Lexer::isComment(string word)
{
    cout << word << endl;
    return stringStartsWith(string(word), "~blep~");
}
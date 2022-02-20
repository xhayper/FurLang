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
    return TokenType::UNKNOWN;
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
        cout << tempWordList.data();
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

bool stringEndsWith(string in, string find)
{
    if (find.size() > in.size()) return false;
    return in.substr(in.size()-find.size(), find.size()) == find;
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
    return regex_match(word, regex("[\\[\\]{}]+"));
}

bool Lexer::isOperator(string word)
{
    if (regex_match(word, regex("[+/\\-*%]"))) return true; // Math operator
    if (regex_match(word, regex("="))) return true; // Assignment operator
    if (regex_match(word, regex("([!><=]=|[><])"))) return true; // Relational operator
    if (regex_match(word, regex("((&&)|(\\|\\|))"))) return true; // Logical operator
    return false;
}

bool Lexer::isLiteral(string word)
{
    if (regex_match(word, regex("^\"([^\"]|(\\\"))*\"$"))) return true; // Check for string
    if (regex_match(word, regex("\\d")) >= 1) return true; // Check for number
    return false;
}

bool Lexer::isComment(string word)
{
    if (regex_match(word, regex("^(~blep~)[\\s\\S]*"))) return true; // Single line comment
    if (regex_match(word, regex("^()"))) return true; // Multiline comment
    return false;
}
#include "parser.hpp"

TokenType Parser::getTokenType(string word)
{
    if (this->isComment(word))
        return TokenType::COMMENT;
    if (this->isKeyword(word))
        return TokenType::KEYWORD;
    if (this->isSeperator(word))
        return TokenType::SEPERATOR;
    if (this->isOperator(word))
        return TokenType::OPERATOR;
    if (this->isLiteral(word))
        return TokenType::LITERAL;
    if (this->isIdentifier(word))
        return TokenType::IDENTIFIER;
    return TokenType::UNKNOWN;
}

bool isOnlyComment(string word)
{
    return regex_match(word, regex("^(~blep~)[\\s\\S]*"));
}

bool isCommentStart(string word)
{
    return regex_match(word, regex("^(~owo~).*"));
}

bool isCommentEnd(string word)
{
    return regex_match(word, regex(".*(~uwu~)$"));
}

void Parser::scan(string source, vector<Token> &out)
{
    char *charArray = new char[source.length() + 1];
    strcpy(charArray, source.c_str());
    vector<Token> tokenVector;
    string word;
    int line = 1;
    int index = 0;
    int wordIndex = 0;

    bool inSingleLineComment = false;
    bool inMultiLineComment = false;
    while (strlen(charArray) > index)
    {
        vector<char> tempWordList;

        while (charArray[index] != '\n' && charArray[index] != ' ' && charArray[index] != '\0')
            tempWordList.push_back(charArray[index++]);
        tempWordList.push_back('\0');
        word = string(tempWordList.data());
        tempWordList.clear();

        if (word != "")
        {
            TokenType tokenType = this->getTokenType(word);
            tokenVector.push_back(Token(inSingleLineComment == true || inMultiLineComment == true ? COMMENT : tokenType, word));

            if (tokenType == COMMENT)
            {
                if (isCommentStart(word))
                    inMultiLineComment = true;
                else if (isCommentEnd(word))
                    inMultiLineComment = false;
                else if (isOnlyComment(word))
                    inSingleLineComment = true;
            }

            if (charArray[index] == '\n')
            {
                inSingleLineComment = false;
                line++;
            }
        }
        word = "";
        wordIndex = 0;
        index++;
    }
    out = tokenVector;
    delete[] charArray;
};

bool Parser::isIdentifier(string word)
{
    return !(regex_match(word, regex("[0-9]{0,1}[^a-zA-Z0-9_]*")));
}

bool Parser::isKeyword(string word)
{
    return false;
}

bool Parser::isSeperator(string word)
{
    return regex_match(word, regex("[\\[\\]{}]+"));
}

bool Parser::isOperator(string word)
{
    if (regex_match(word, regex("[+/\\-*%]")))
        return true; // Math operator
    if (regex_match(word, regex("=")))
        return true; // Assignment operator
    if (regex_match(word, regex("([!><=]=|[><])")))
        return true; // Relational operator
    if (regex_match(word, regex("((&&)|(\\|\\|))")))
        return true; // Logical operator
    return false;
}

bool Parser::isLiteral(string word)
{
    if (regex_match(word, regex("^\"([^\"]|(\\\"))*\"$")))
        return true; // Check for string
    if (regex_match(word, regex("\\d")))
        return true; // Check for number
    return false;
}

bool Parser::isComment(string word)
{
    return isOnlyComment(word) || isCommentStart(word) || isCommentEnd(word);
}

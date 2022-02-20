#include <Lexer/src/lexer.hpp>

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream t(argv[1]);
    stringstream buffer;
    buffer << t.rdbuf();

    string source = buffer.str();
    char charArray[source.length() + 1];

    strcpy(charArray, source.c_str());

    Lexer lexer = Lexer();

    Token *currentTokenList[] = {};
    lexer.scan(source, currentTokenList);
    return 0;
}
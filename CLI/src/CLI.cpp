#include <Lexer/src/lexer.hpp>

#include "iostream"
#include "fstream"
#include "cstring"
#include "sstream"

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

    vector<Token> tokenList;
    lexer.scan(source, tokenList);
    cout << tokenList[0].value << endl;
    return 0;
}
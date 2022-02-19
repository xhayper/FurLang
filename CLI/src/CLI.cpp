#include <iostream>
#include <fstream>
#include <string>
#include <Lexer/src/lexer.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string line;
    Lexer lexer = Lexer();
    while (getline(file, line))
    {
        Token *currentToken[] = {};
        lexer.scan((char*) line.c_str(), currentToken);
        cout << currentToken[0]->type << endl;
    }
    file.close();
    return 0;
}
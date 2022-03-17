#include "CLI.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream t(argv[1]);
    stringstream buffer;
    buffer << t.rdbuf();

    string source = buffer.str();
    Lexer lexer = Lexer();

    vector<Token> tokenList;
    lexer.scan(source, tokenList);
    for (int i = 0; i < tokenList.size(); i++)
    {
        cout << "< Type: " << tokenList.at(i).type << ", Value: '" << tokenList.at(i).value << "' >" << endl;
    }
    return 0;
}
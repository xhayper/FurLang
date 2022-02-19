#include <iostream>
#include <fstream>
#include <string>
#include <lexer> 

using namespace std;

int main(int argc, char *argv[])
{
    ifstream file;
    file.open(argv[1]);
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
    return 0;
}
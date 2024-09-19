#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "lexer.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        string filePath = argv[1];

        string line;
        string text;

        ifstream file;
        file.open(filePath);

        while (getline(file, line))
        {
            text += line += "\n";
        };

        cout << text;
        vector<Token> TokensStream;

        TokensStream = lex(text);
    }

    return 0;
}

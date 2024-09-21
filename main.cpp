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

        ifstream file(filePath);
        

        while (getline(file, line))
        {
            text += line += "\n";
        };
        file.close();

        vector<Token> TokensStream;

        TokensStream = lex(text);
        cout << "Compiling success" << "\n";

        ofstream lexerOUT("lexer.out", std::ios::out | std::ios::trunc);

        for(auto& token : TokensStream)
        {          
            string tp = TokenTypeToString(token.type);
            lexerOUT << tp;
        };
    }

    return 0;
}

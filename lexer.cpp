#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum ExpectedToken
{
    INDENTIFIER,
    EXPECTING_SEMI,
};

enum TokenType
{
    _NULL,

    VAR_DEF,

    INT_LIT,
    INT_DEF,
    
    FUNC_DEF,
};

string TokenTypeToString(TokenType type)
{
    switch (type)
    {
    case _NULL:
        return "_NULL";
    case VAR_DEF:
        return "VAR_DEF";
    case INT_LIT:
        return "INT_LIT";
    case INT_DEF:
        return "INT_DEF";
    case FUNC_DEF:
        return "FUNC_DEF";
    break;
    }
}

struct Token
{
    TokenType type;
    string value;
};

vector<Token> lex(string text)
{
    vector<Token> TokensStream;
    Token TokenBuffer;
    TokenBuffer.type = _NULL;
    string StringBuffer;
    ExpectedToken expecting;

    for(char CURRENT_CHAR : text)
    {
        StringBuffer += CURRENT_CHAR;
        if(StringBuffer == "int")
        {
            TokenBuffer.type = INT_DEF;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            StringBuffer = "";
            expecting = INDENTIFIER;
        };

    };  

    return TokensStream;   
};

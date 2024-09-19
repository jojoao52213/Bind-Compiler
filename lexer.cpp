#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum class TokenType
{
    SEMI,

    VAR_NAME,

    INT_LIT,
    INT_DEF,

    FLOAT_LIT,
    FLOAT_DEF,

    CHAR_LIT,
    CHAR_DEF,

    BOOL_LIT,
    BOOL_DEF,

    RETURN,
    IF,
    WHILE,
    FOR,

    EQU,
    LESS_THAN,
    MORE_THAN,

};

struct Token
{
    TokenType type;
    string value;
};

vector<Token> lex(string text)
{
    vector<Token> TokensStream;

    return TokensStream;   
};

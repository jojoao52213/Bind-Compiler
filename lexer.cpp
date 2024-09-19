#include <iostream>
#include <vector>

enum class TokenType
{
    SEMI,

    VARNAME,

    INTLIT,
    INTDEF,

    FLOATLIT,
    FLOATDEF,

    CHARLIT,
    CHARDEF,

    BOOLLIT,
    BOOLDEF,

    RETURN,
    IF,
    WHILE,
    FOR,

    EQU,
    LESSTHAN,
    MORETHAN,



    
};

class Token
{
    TokenType type;
    int intValue;
    string stringValue;
};

class Lexer
{
    vector<Token> lex()
    {
        vector<Token> TokensStream;

        return TokensStream;   
    };
};

#include <iostream>

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



    
}

struct Token
{
    TokenType type;
    int intValue;
    String stringValue;
}

class Lexer
{

}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum ExpectedToken
{
    __NULL,

    _INDENTIFIER,

    _OPEN_PARENTHESES,
    _CLOSE_PARENTHESES,
    _EQU,
};

enum TokenType
{
    SEMI,

    OPEN_CURLY_BRACKETS,
    CLOSE_CURLY_BRACKETS,

    OPEN_PARENTHESES,
    CLOSE_PARENTHESES,

    EQU,

    _NULL,

    INDENTIFIER,

    RETURN,

    INT_LIT,
    INT_DEF,
};

bool IsInt(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
};

string TokenTypeToString(TokenType type)
{
    switch (type)
    {
    case _NULL:
        return "_NULL ";
    case INDENTIFIER:
        return "INDENTIFIER ";
    case INT_LIT:
        return "INT_LIT ";
    case INT_DEF:
        return "INT_DEF ";
    case EQU:
        return "EQU ";
    case OPEN_PARENTHESES:
        return "OPEN_PARENTHESES ";
    case CLOSE_PARENTHESES:
        return "CLOSE_PARENTHESES ";
    case OPEN_CURLY_BRACKETS:
        return "OPEN_CURLY_BRACKETS ";
    case CLOSE_CURLY_BRACKETS:
        return "CLOSE_CURLY_BRACKETS ";
    case SEMI:
        return "SEMI ";
    case RETURN:
        return "RETURN ";
    default:
        return "";
        break;
    }
    return "";
};

struct Token
{
    TokenType type;
    string value;
};

vector<Token> lex(string text)
{
    vector<Token> TokensStream;

    // Token Buffer initialization
    Token TokenBuffer;
    TokenBuffer.type = _NULL;

    string WithOutSpaceCode;

    for (char c : text)
    {
        if (c != '\t' && c != '\n' && c != ' ')
        {
            WithOutSpaceCode += c;
        }
    }

    // Lexer Main part initialization
    string StringBuffer;
    ExpectedToken expected;

    bool IndentifierInProgress = false;
    string IndentifierBuffer;

    string IntLitBuffer;
    bool IntLitInProgress = false;

    // Lexer Main part
    for (char CURRENT_CHAR : WithOutSpaceCode)
    {
        StringBuffer += CURRENT_CHAR;

        if (expected == _INDENTIFIER)
        {
            if (IndentifierInProgress && CURRENT_CHAR != '=' && CURRENT_CHAR != '(')
            {
                IndentifierBuffer += CURRENT_CHAR;
            }
            else
            {
                TokenBuffer.type = INDENTIFIER;
                TokenBuffer.value = IndentifierBuffer;
                TokensStream.push_back(TokenBuffer);
                TokenBuffer.type = _NULL;
                TokenBuffer.value = "";

                IndentifierBuffer = "";
                IndentifierInProgress = false;
                expected = __NULL;

                if (CURRENT_CHAR == '=')
                {
                    TokenBuffer.type = EQU;
                    TokensStream.push_back(TokenBuffer);
                    TokenBuffer.type = _NULL;
                }
                else if (CURRENT_CHAR == '(')
                {
                    TokenBuffer.type = OPEN_PARENTHESES;
                    TokensStream.push_back(TokenBuffer);
                    TokenBuffer.type = _NULL;
                }

                StringBuffer = "";
            }
        }

        if (StringBuffer == "int" && expected != _INDENTIFIER)
        {
            StringBuffer = "";
            TokenBuffer.type = INT_DEF;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            expected = _INDENTIFIER;
            IndentifierInProgress = true;
        }

        if (StringBuffer == ")")
        {
            TokenBuffer.type = CLOSE_PARENTHESES;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            StringBuffer = "";
        }

        if (StringBuffer == "{")
        {
            TokenBuffer.type = OPEN_CURLY_BRACKETS;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            StringBuffer = "";
        }

        if (StringBuffer == "}")
        {
            TokenBuffer.type = CLOSE_CURLY_BRACKETS;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            StringBuffer = "";
        }

        if (IsInt(CURRENT_CHAR))
        {
            IntLitInProgress = true;
            IntLitBuffer += CURRENT_CHAR;
            StringBuffer = "";
        }

        if (IntLitInProgress && !IsInt(CURRENT_CHAR))
        {
            TokenBuffer.type = INT_LIT;
            TokenBuffer.value = IntLitBuffer;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            TokenBuffer.value = "";

            IntLitInProgress = false;
            IntLitBuffer = "";
        }

        if (StringBuffer == ";")
        {
            TokenBuffer.type = SEMI;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            StringBuffer = "";
        }

        if (StringBuffer == "return")
        {
            TokenBuffer.type = RETURN;
            TokensStream.push_back(TokenBuffer);
            TokenBuffer.type = _NULL;
            StringBuffer = "";
        }

    }

    return TokensStream;
};

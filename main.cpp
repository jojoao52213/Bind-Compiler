#include <iostream>
#include <lexer.cpp>

using namespace std;

int main(int argc, char **argv)
{
    string filePath;

    if(argc > 0)
    {
        filePath = argv[1];
    }
    
    cout << filePath;

 return 0;
}

#pragma once

#include <vector>
#include <string>

using namespace std;

enum TokenType{
    WHITESPACE,
    IDENTIFIER,
    INTEGER_LITERAL,
    STRING_LITERAL,
    OPERATOR
};

class Token{
public:

    enum TokenType type;
    string text;
};

class Tokenizer{
public:
    vector<Token> list;
};
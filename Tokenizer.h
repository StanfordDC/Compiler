#pragma once

#include <vector>

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
};

class Tokenizer{
public:
    vector<Token> list;
};
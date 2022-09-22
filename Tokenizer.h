#pragma once

#include <vector>
#include <string>

using namespace std;

enum TokenType{
    WHITESPACE, // No token ever has this type.
    IDENTIFIER,
    INTEGER_LITERAL,
    DOUBLE_LITERAL,
    STRING_LITERAL,
    OPERATOR,
    STRING_ESCAPE_SEQUENCE,
};

class Token{
public:
    enum TokenType type;
    string text;
    size_t mStartOffset;
    size_t mEndOFFset;
    size_t mLineNumber;
};

class Tokenizer{
public:
    vector<Token> parse(const string &inProgram);
};
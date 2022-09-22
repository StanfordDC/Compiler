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
     enum TokenType mType{WHITESPACE};
    string mText;
    size_t mLineNumber{0};
    size_t mEndOFFset{0};
    size_t mLineNumber{0};
};

class Tokenizer{
public:
    vector<Token> parse(const string &inProgram);
};
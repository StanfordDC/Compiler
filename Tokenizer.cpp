#include <Tokenizer.h>

using namespace std;

vector<Token> Tokenizer::parse(const string &inProgram){
    vector<Token> tokens;
    Token currentToken;

    for(char c : inProgram){
        switch(c){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (currentToken.mType == WHITESPACE) {
                    currentToken.mType = INTEGER_LITERAL;
                    currentToken.mText.append(1, c);
                } else {
                    currentToken.mText.append(1, c);
                }
                break;
                
            case '{':
            case '}':
            case '(':
            case ')':
            case '=':
            case '+':
            case '-':
            case '*':
            case '<':
            case ';':
            case ',':
                if (currentToken.mType != STRING_LITERAL) {
                    endToken(currentToken, tokens);
                    currentToken.mType = OPERATOR;
                    currentToken.mText.append(1, currCh);
                    endToken(currentToken, tokens);
                } else {
                    currentToken.mText.append(1, currCh);
                }
                break;

        }
    }
}
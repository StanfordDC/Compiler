#pragma once

#include "Tokenizer.h"

#include <optional>
#include <string>
#include <map>
#include <vector>

namespace simpleparser {

    using namespace std;

    class Parser {
    public:
        Parser();

        void parse(vector<Token> &tokens);

        void debugPrint() const;

        map<string, FunctionDefinition> GetFunctions() const { return mFunctions; }

    private:
        optional<Type> expectType();

        //! Empty string means match any identifier.
        optional<Token> expectIdentifier(const string& name = string());

        //! Empty string means match any operator.
        optional<Token> expectOperator(const string& name = string());

        bool expectFunctionDefinition();

        vector<Token>::iterator mCurrentToken;
        vector<Token>::iterator mEndToken;
        map<string, Type> mTypes;
        map<string, FunctionDefinition> mFunctions;
    
    };
}

#include <iostream>
#include <Instructions.cpp>
#include <vector>

using namespace std;

int main(int, char**) {
    std::cout << "Bytecode interpreter\n";

    Instruction code[] = {
        Instruction{PUSH_INT, 0, 4000},
        Instruction{PUSH_INT, 0, 1042},
        Instruction{ADD_INT, 0, 0},
    };

    vector<uint16_t> stack;

    Instruction* currentInstruction = code;
}

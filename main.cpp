#include <iostream>
#include <Instructions.cpp>

int main(int, char**) {
    std::cout << "Bytecode interpreter\n";

    Instruction code[] = {
        Instruction{PUSH_INT, 0, 4000};
        Instruction{PUSH_INT, 0, 1042};
        Instruction{ADD_INT, 0, 0};
    }
}

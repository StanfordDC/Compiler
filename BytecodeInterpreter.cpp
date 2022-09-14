#include <Instructions.cpp>
#include <cstdint>
#include <vector>

struct InterpreterRegisters{
    vector<uint16_t> stack;
    Instruction* currentInstruction;
};
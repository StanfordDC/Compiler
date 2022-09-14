#include "Instructions.cpp"
#include <cstdint>
#include <vector>

namespace bytecodeInterpreter{

    using namespace std;

    struct InterpreterRegisters{
        vector<uint16_t> stack;
        Instruction* currentInstruction;
    };

    class BytecodeInterpreter{
    public:
        void run(Instruction* code);
    };
}
#include "Instructions.cpp"
#include <cstdint>
#include <vector>

namespace bytecodeInterpreter{

    using namespace std;

    struct InterpreterRegisters{
        vector<uint16_t> stack;
        Instruction* currentInstruction;
    };

    //comment
    typedef void (*InstructionFunction) (InterpreterRegisters& registers);

    void ExitInstruction(InterpreterRegisters& registers);

    void AddIntInstruction(InterpreterRegisters& registers);

    void PushIntInstruction(InterpreterRegisters& registers);

    void PrintIntInstruction(InterpreterRegisters& registers);
    
    extern InstructionFunction gInstructionFunctions[NUM_INSTRUCTIONS];

    class BytecodeInterpreter{
    public:
        void run(Instruction* code);
    };
}
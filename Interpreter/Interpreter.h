#include "Instructions.h"
#include <cstdint>
#include <vector>

namespace interpreter{

    using namespace std;

    struct InterpreterRegisters{
        vector<int16_t> stack;
        Instruction* currentInstruction;
        vector<Instruction*> returnAddressStack;
        size_t baseIndex;
    };

    typedef void (*InstructionFunction) (InterpreterRegisters& registers);

    void ExitInstruction(InterpreterRegisters& registers);

    void AddIntInstruction(InterpreterRegisters& registers);

    void PushIntInstruction(InterpreterRegisters& registers);

    void PrintIntInstruction(InterpreterRegisters& registers);

    void CompareIntLessThanInstruction(InterpreterRegisters& registers);

    void LoadIntInstruction(InterpreterRegisters& registers);

    void StoreIntInstruction(InterpreterRegisters& registers);

    void JumpByIfZeroInstruction(InterpreterRegisters& registers);

    void JumpByInstruction(InterpreterRegisters& registers);

    void LoadIntBasepointerRelativeInstruction(InterpreterRegisters& registers);

    void StoreIntBasepointerRelativeInstruction(InterpreterRegisters& registers);

    void CallInstruction(InterpreterRegisters& registers);

    void ReturnInstruction(InterpreterRegisters& registers);
    
    extern InstructionFunction gInstructionFunctions[NUM_INSTRUCTIONS];

    class Interpreter{
    public:
        static void run(Instruction* code, vector<int16_t> arguments, int16_t* result = nullptr);
    };
}

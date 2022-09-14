#include "BytecodeInterpreter.h"

namespace bytecodeInterpreter{

    extern InstructionFunction gInstructionFunctions[NUM_INSTRUCTIONS] = {
        ExitInstruction,
        AddIntInstruction,
        PushIntInstruction,
        PrintIntInstruction
    };

    void BytecodeInterpreter::run(Instruction* code){
        InterpreterRegisters registers;
        registers.currentInstruction = code;

        while(registers.currentInstruction != nullptr){
            gInstructionFunctions[registers.currentInstruction->opcode](registers);
        }
    }

    void ExitInstruction(InterpreterRegisters& registers){
        registers.currentInstruction = nullptr;
    }

    void AddIntInstruction(InterpreterRegisters& registers){
        int16_t rightHandSide = registers.stack.back();
        registers.stack.pop_back();
        int16_t leftHandSide = registers.stack.back();
        registers.stack.pop_back();
        registers.stack.push_back(leftHandSide + rightHandSide);
        ++registers.currentInstruction;
    }

    void PushIntInstruction(InterpreterRegisters& registers){
        
    }

    void PrintIntInstruction(InterpreterRegisters& registers){
        
    }
}

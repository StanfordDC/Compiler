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
        
    }

    void AddIntInstruction(InterpreterRegisters& registers){
        
    }

    void PushIntInstruction(InterpreterRegisters& registers){
        
    }

    void PrintIntInstruction(InterpreterRegisters& registers){
        
    }
}

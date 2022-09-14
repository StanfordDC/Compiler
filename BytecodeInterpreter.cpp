#include "BytecodeInterpreter.h"
#include <iostream>

namespace bytecodeInterpreter{

    using namespace std;

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
        registers.stack.push_back(registers.currentInstruction->p2);
        ++registers.currentInstruction;
    }

    void PrintIntInstruction(InterpreterRegisters& registers){
         int16_t number = registers.stack.back();
        registers.stack.pop_back();
        cout << "Number Printed: " << number << endl;
        ++registers.currentInstruction;
    }
}

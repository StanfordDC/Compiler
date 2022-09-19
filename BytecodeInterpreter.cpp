#include "BytecodeInterpreter.h"
#include <iostream>

namespace bytecodeInterpreter{

    using namespace std;

    extern InstructionFunction gInstructionFunctions[NUM_INSTRUCTIONS] = {
        ExitInstruction,
        AddIntInstruction,
        PushIntInstruction,
        PrintIntInstruction,
         CompareIntLessThanInstruction,
        LoadIntInstruction,
        StoreIntInstruction,
        JumpByIfZeroInstruction,
        JumpByInstruction
    };

    //Run the entire instructions
    void BytecodeInterpreter::run(Instruction* code){
        InterpreterRegisters registers;
        registers.currentInstruction = code;

        while(registers.currentInstruction != nullptr){
            gInstructionFunctions[registers.currentInstruction->opcode](registers);
        }
    }

    //Exit the loop
    void ExitInstruction(InterpreterRegisters& registers){
        registers.currentInstruction = nullptr;
    }

    //Add integer
    void AddIntInstruction(InterpreterRegisters& registers){
        int16_t rightHandSide = registers.stack.back();
        registers.stack.pop_back();
        int16_t leftHandSide = registers.stack.back();
        registers.stack.pop_back();
        registers.stack.push_back(leftHandSide + rightHandSide);
        ++registers.currentInstruction;
    }

    //Push integer
    void PushIntInstruction(InterpreterRegisters& registers){
        registers.stack.push_back(registers.currentInstruction->p2);
        ++registers.currentInstruction;
    }

    //Print result
    void PrintIntInstruction(InterpreterRegisters& registers){
         int16_t number = registers.stack.back();
        registers.stack.pop_back();
        cout << "Number Printed: " << number << endl;
        ++registers.currentInstruction;
    }

    //Compare integers
    void CompareIntLessThanInstruction(InterpreterRegisters& registers) {
        int16_t rightHandSide = registers.stack.back();
        registers.stack.pop_back();
        int16_t leftHandSide = registers.stack.back();
        registers.stack.pop_back();

        registers.stack.push_back(leftHandSide < rightHandSide);

        ++registers.currentInstruction;
    }

    //Load integers
    void LoadIntInstruction(InterpreterRegisters& registers) {
        registers.stack.push_back(registers.stack[registers.currentInstruction->p2]);
        ++registers.currentInstruction;
    }

    //Store integers
    void StoreIntInstruction(InterpreterRegisters& registers) {
        registers.stack[registers.currentInstruction->p2] = registers.stack.back();
        registers.stack.pop_back();
        ++registers.currentInstruction;
    }

    //Jump by if zero
    void JumpByIfZeroInstruction(InterpreterRegisters& registers) {
        int16_t condition = registers.stack.back();
        registers.stack.pop_back();
        if (condition == 0) {
            registers.currentInstruction += registers.currentInstruction->p2;
        } else {
            ++registers.currentInstruction; // no-op.
        }
    }

    //Jump by
    void JumpByInstruction(InterpreterRegisters& registers) {
        registers.currentInstruction += registers.currentInstruction->p2;
    }

     //Load int base pointer relative
    void LoadIntBasepointerRelativeInstruction(InterpreterRegisters &registers) {
        registers.stack.push_back(registers.stack[registers.currentInstruction->p2 + registers.baseIndex]);
        ++registers.currentInstruction;
    }

    //Store int base pointer relative
    void StoreIntBasepointerRelativeInstruction(InterpreterRegisters &registers) {
        registers.stack[registers.currentInstruction->p2 + registers.baseIndex] = registers.stack.back();
        registers.stack.pop_back();
        ++registers.currentInstruction;
    }

     //Call function
    void CallInstruction(InterpreterRegisters &registers) {
        registers.stack.push_back(int16_t(registers.baseIndex)); // DANGER! Saved base pointer is limited to 16 bits signed!
        registers.returnAddressStack.push_back(registers.currentInstruction + 1);
        registers.baseIndex = registers.stack.size();
        registers.currentInstruction += registers.currentInstruction->p2;
    }

     //Return function
    void ReturnInstruction(InterpreterRegisters &registers) {
        Instruction * returnAddress = registers.returnAddressStack.back();
        registers.returnAddressStack.pop_back();
        registers.baseIndex = registers.stack.back();
        registers.stack.pop_back();
        registers.currentInstruction = returnAddress;
    }

}

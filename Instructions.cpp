#include <cstdint>

enum Opcode: uint8_t{
    EXIT,
    ADD_INT,
    PUSH_INT,
    PRINT_INT,
    COMP_INT_LT,
    LOAD_INT,
    STORE_INT,
    NUM_INSTRUCTIONS
};

class Instruction{
public:
    Opcode opcode;
    uint8_t p1;
    uint16_t p2;
};

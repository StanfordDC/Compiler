#include <cstdint>

enum Opcode: uint8_t{
    ADD_INT,
    PUSH_INT,
    PRINT_INT,
    EXIT
};

class Instruction{
public:
    Opcode opcode;
    uint8_t p1;
    uint16_t p2;
};

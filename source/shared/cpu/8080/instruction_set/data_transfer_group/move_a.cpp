#include "data_transfer_group.h"

namespace move {
    void MOV_A_B(Registers& registers){ data_transfer::Move(registers.bc.d8.highByte, registers.a, registers.pc.d16, "MOV A, B"); }
    void MOV_A_C(Registers& registers){ data_transfer::Move(registers.bc.d8.lowByte, registers.a, registers.pc.d16, "MOV A, C"); }
    void MOV_A_D(Registers& registers){ data_transfer::Move(registers.de.d8.highByte, registers.a, registers.pc.d16, "MOV A, D"); }
    void MOV_A_E(Registers& registers){ data_transfer::Move(registers.de.d8.lowByte, registers.a, registers.pc.d16, "MOV A, E"); }
    void MOV_A_H(Registers& registers){ data_transfer::Move(registers.hl.d8.highByte, registers.a, registers.pc.d16, "MOV A, H"); }
    void MOV_A_L(Registers& registers){ data_transfer::Move(registers.hl.d8.lowByte, registers.a, registers.pc.d16, "MOV A, L"); }
    void MOV_A_A(Registers& registers){ data_transfer::Move(registers.a, registers.a, registers.pc.d16, "MOV A, A"); }

    void MOV_A_M(Registers& registers){ data_transfer::Move(registers.a, registers.a, registers.pc.d16, "MOV A, B"); }
}

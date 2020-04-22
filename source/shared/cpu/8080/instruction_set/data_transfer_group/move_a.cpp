#include "data_transfer_group.h"

namespace move {
    void MOV_A_B(Regs& registers){ data_transfer::Move(registers.bc.d8.highByte, registers.a, registers.pc.d16, "MOV A, B"); }
    void MOV_A_C(Regs& registers){ data_transfer::Move(registers.bc.d8.lowByte, registers.a, registers.pc.d16, "MOV A, C"); }
    void MOV_A_D(Regs& registers){ data_transfer::Move(registers.de.d8.highByte, registers.a, registers.pc.d16, "MOV A, D"); }
    void MOV_A_E(Regs& registers){ data_transfer::Move(registers.de.d8.lowByte, registers.a, registers.pc.d16, "MOV A, E"); }
    void MOV_A_H(Regs& registers){ data_transfer::Move(registers.hl.d8.highByte, registers.a, registers.pc.d16, "MOV A, H"); }
    void MOV_A_L(Regs& registers){ data_transfer::Move(registers.hl.d8.lowByte, registers.a, registers.pc.d16, "MOV A, L"); }
    void MOV_A_A(Regs& registers){ data_transfer::Move(registers.a, registers.a, registers.pc.d16, "MOV A, A"); }

    void MOV_A_M(Regs& registers){ data_transfer::Move(registers.a, registers.a, registers.pc.d16, "MOV A, B"); }
}

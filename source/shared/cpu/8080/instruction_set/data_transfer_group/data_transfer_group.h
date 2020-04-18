#ifndef EMULATOR_DATA_TRANSFER_GROUP_H
#define EMULATOR_DATA_TRANSFER_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace data_transfer {
    void MoveImmediateLow(pair& dst, Registers& regs, const char* instr);
    void MoveImmediateHigh(pair& dst, Registers& regs, const char* instr);

    void Move(uint8_t src, uint8_t& dst, uint16_t& pc, const char* instr);
    void LoadImmediate(Registers& registers, pair& reg, const char* instr);
}

namespace move {
    void MOV_B_B(Registers& registers);
    void MOV_B_C(Registers& registers);
    void MOV_B_D(Registers& registers);
    void MOV_B_E(Registers& registers);
    void MOV_B_H(Registers& registers);
    void MOV_B_L(Registers& registers);
    void MOV_B_M(Registers& registers);
    void MOV_B_A(Registers& registers);

    void MOV_C_B(Registers& registers);
    void MOV_C_C(Registers& registers);
    void MOV_C_D(Registers& registers);
    void MOV_C_E(Registers& registers);
    void MOV_C_H(Registers& registers);
    void MOV_C_L(Registers& registers);
    void MOV_C_M(Registers& registers);
    void MOV_C_A(Registers& registers);

    void MOV_D_B(Registers& registers);
    void MOV_D_C(Registers& registers);
    void MOV_D_D(Registers& registers);
    void MOV_D_E(Registers& registers);
    void MOV_D_H(Registers& registers);
    void MOV_D_L(Registers& registers);
    void MOV_D_M(Registers& registers);
    void MOV_D_A(Registers& registers);

    void MOV_E_B(Registers& registers);
    void MOV_E_C(Registers& registers);
    void MOV_E_D(Registers& registers);
    void MOV_E_E(Registers& registers);
    void MOV_E_H(Registers& registers);
    void MOV_E_L(Registers& registers);
    void MOV_E_M(Registers& registers);
    void MOV_E_A(Registers& registers);

    void MOV_H_B(Registers& registers);
    void MOV_H_C(Registers& registers);
    void MOV_H_D(Registers& registers);
    void MOV_H_E(Registers& registers);
    void MOV_H_H(Registers& registers);
    void MOV_H_L(Registers& registers);
    void MOV_H_M(Registers& registers);
    void MOV_H_A(Registers& registers);

    void MOV_L_B(Registers& registers);
    void MOV_L_C(Registers& registers);
    void MOV_L_D(Registers& registers);
    void MOV_L_E(Registers& registers);
    void MOV_L_H(Registers& registers);
    void MOV_L_L(Registers& registers);
    void MOV_L_M(Registers& registers);
    void MOV_L_A(Registers& registers);

    void MOV_M_B(Registers& registers);
    void MOV_M_C(Registers& registers);
    void MOV_M_D(Registers& registers);
    void MOV_M_E(Registers& registers);
    void MOV_M_H(Registers& registers);
    void MOV_M_L(Registers& registers);
    void MOV_M_A(Registers& registers);

    void MOV_A_B(Registers& registers);
    void MOV_A_C(Registers& registers);
    void MOV_A_D(Registers& registers);
    void MOV_A_E(Registers& registers);
    void MOV_A_H(Registers& registers);
    void MOV_A_L(Registers& registers);
    void MOV_A_M(Registers& registers);
    void MOV_A_A(Registers& registers);

    void MVI_A(Registers& registers);
    void MVI_B(Registers& registers);
    void MVI_C(Registers& registers);
    void MVI_D(Registers& registers);
    void MVI_E(Registers& registers);
    void MVI_H(Registers& registers);
    void MVI_L(Registers& registers);
    void MVI_M(Registers& registers);
}

namespace load {
    void LXI_B(Registers& registers);
    void LXI_D(Registers& registers);
    void LXI_H(Registers& registers);
    void LXI_SP(Registers& registers);

    void LDA(Registers& registers);
    void LHLD(Registers& registers);
    void LDAX_B(Registers& registers);
    void LDAX_D(Registers& registers);
}

namespace store {
    void STA(Registers& registers);
    void SHLD(Registers& registers);
    void STAX_B(Registers& registers);
    void STAX_D(Registers& registers);
    void XCHG(Registers& registers);
}
#endif

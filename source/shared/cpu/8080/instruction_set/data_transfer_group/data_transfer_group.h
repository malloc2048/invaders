#ifndef EMULATOR_DATA_TRANSFER_GROUP_H
#define EMULATOR_DATA_TRANSFER_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace data_transfer {
    void MoveImmediateLow(pair& dst, Regs& regs, const char* instr);
    void MoveImmediateHigh(pair& dst, Regs& regs, const char* instr);

    void Move(uint8_t src, uint8_t& dst, uint16_t& pc, const char* instr);
    void LoadImmediate(Regs& registers, pair& reg, const char* instr);

    bool MemCheck(uint16_t address);
}

namespace move {
    void MOV_B_B(Regs& registers);
    void MOV_B_C(Regs& registers);
    void MOV_B_D(Regs& registers);
    void MOV_B_E(Regs& registers);
    void MOV_B_H(Regs& registers);
    void MOV_B_L(Regs& registers);
    void MOV_B_M(Regs& registers);
    void MOV_B_A(Regs& registers);

    void MOV_C_B(Regs& registers);
    void MOV_C_C(Regs& registers);
    void MOV_C_D(Regs& registers);
    void MOV_C_E(Regs& registers);
    void MOV_C_H(Regs& registers);
    void MOV_C_L(Regs& registers);
    void MOV_C_M(Regs& registers);
    void MOV_C_A(Regs& registers);

    void MOV_D_B(Regs& registers);
    void MOV_D_C(Regs& registers);
    void MOV_D_D(Regs& registers);
    void MOV_D_E(Regs& registers);
    void MOV_D_H(Regs& registers);
    void MOV_D_L(Regs& registers);
    void MOV_D_M(Regs& registers);
    void MOV_D_A(Regs& registers);

    void MOV_E_B(Regs& registers);
    void MOV_E_C(Regs& registers);
    void MOV_E_D(Regs& registers);
    void MOV_E_E(Regs& registers);
    void MOV_E_H(Regs& registers);
    void MOV_E_L(Regs& registers);
    void MOV_E_M(Regs& registers);
    void MOV_E_A(Regs& registers);

    void MOV_H_B(Regs& registers);
    void MOV_H_C(Regs& registers);
    void MOV_H_D(Regs& registers);
    void MOV_H_E(Regs& registers);
    void MOV_H_H(Regs& registers);
    void MOV_H_L(Regs& registers);
    void MOV_H_M(Regs& registers);
    void MOV_H_A(Regs& registers);

    void MOV_L_B(Regs& registers);
    void MOV_L_C(Regs& registers);
    void MOV_L_D(Regs& registers);
    void MOV_L_E(Regs& registers);
    void MOV_L_H(Regs& registers);
    void MOV_L_L(Regs& registers);
    void MOV_L_M(Regs& registers);
    void MOV_L_A(Regs& registers);

    void MOV_M_B(Regs& registers);
    void MOV_M_C(Regs& registers);
    void MOV_M_D(Regs& registers);
    void MOV_M_E(Regs& registers);
    void MOV_M_H(Regs& registers);
    void MOV_M_L(Regs& registers);
    void MOV_M_A(Regs& registers);

    void MOV_A_B(Regs& registers);
    void MOV_A_C(Regs& registers);
    void MOV_A_D(Regs& registers);
    void MOV_A_E(Regs& registers);
    void MOV_A_H(Regs& registers);
    void MOV_A_L(Regs& registers);
    void MOV_A_M(Regs& registers);
    void MOV_A_A(Regs& registers);

    void MVI_A(Regs& registers);
    void MVI_B(Regs& registers);
    void MVI_C(Regs& registers);
    void MVI_D(Regs& registers);
    void MVI_E(Regs& registers);
    void MVI_H(Regs& registers);
    void MVI_L(Regs& registers);
    void MVI_M(Regs& registers);
}

namespace load {
    void LXI_B(Regs& registers);
    void LXI_D(Regs& registers);
    void LXI_H(Regs& registers);
    void LXI_SP(Regs& registers);

    void LDA(Regs& registers);
    void LHLD(Regs& registers);
    void LDAX_B(Regs& registers);
    void LDAX_D(Regs& registers);
}

namespace store {
    void STA(Regs& registers);
    void SHLD(Regs& registers);
    void STAX_B(Regs& registers);
    void STAX_D(Regs& registers);
    void XCHG(Regs& registers);
}
#endif

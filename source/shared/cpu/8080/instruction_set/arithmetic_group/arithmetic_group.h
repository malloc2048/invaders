#ifndef EMULATOR_ARITHMETIC_GROUP_H
#define EMULATOR_ARITHMETIC_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace arithmetic {
    void Add(Regs &registers, uint8_t src, const char* instr);
}

namespace addition {
    void ADD_A(Regs &registers);
    void ADD_B(Regs &registers);
    void ADD_C(Regs &registers);
    void ADD_D(Regs &registers);
    void ADD_E(Regs &registers);
    void ADD_H(Regs &registers);
    void ADD_L(Regs &registers);
    void ADD_M(Regs &registers);

    void ADI(Regs &registers);
    void ACI(Regs &registers);

    void ADC_A(Regs &registers);
    void ADC_B(Regs &registers);
    void ADC_C(Regs &registers);
    void ADC_D(Regs &registers);
    void ADC_E(Regs &registers);
    void ADC_H(Regs &registers);
    void ADC_L(Regs &registers);
    void ADC_M(Regs &registers);

//    void dad(uint16_t highByte, uint16_t lowByte, Regs& registers, const char* instr);
    void DAD(pair& value, Regs& registers, const char* instr);
    void DAD_B(Regs &registers);
    void DAD_D(Regs &registers);
    void DAD_H(Regs &registers);
    void DAD_SP(Regs &registers);

    void DAA(Regs &registers);
}

namespace subtraction {
    void SUB_A(Regs& registers);
    void SUB_B(Regs& registers);
    void SUB_C(Regs& registers);
    void SUB_D(Regs& registers);
    void SUB_E(Regs& registers);
    void SUB_H(Regs& registers);
    void SUB_L(Regs& registers);
    void SUB_M(Regs& registers);

    void SUI(Regs& registers);
    void SBI(Regs& registers);

    void SBB_A(Regs& registers);
    void SBB_B(Regs& registers);
    void SBB_C(Regs& registers);
    void SBB_D(Regs& registers);
    void SBB_E(Regs& registers);
    void SBB_H(Regs& registers);
    void SBB_L(Regs& registers);
    void SBB_M(Regs& registers);
}

namespace increment {
    void incrementReg(Regs& registers, uint8_t* reg, const char* instr);
    void INR_A(Regs& registers);
    void INR_B(Regs& registers);
    void INR_C(Regs& registers);
    void INR_D(Regs& registers);
    void INR_E(Regs& registers);
    void INR_H(Regs& registers);
    void INR_L(Regs& registers);
    void INR_M(Regs& registers);

    void incrementPair(pair& pc, pair& regPair, const char* instr);
    void INX_B(Regs &registers);
    void INX_D(Regs &registers);
    void INX_H(Regs &registers);
    void INX_SP(Regs &registers);
}

namespace decrement {
    uint8_t decrement(Regs& registers, uint8_t value, const char* instr);
    void DCR_A(Regs& registers);
    void DCR_B(Regs& registers);
    void DCR_C(Regs& registers);
    void DCR_D(Regs& registers);
    void DCR_E(Regs& registers);
    void DCR_H(Regs& registers);
    void DCR_L(Regs& registers);
    void DCR_M(Regs& registers);

    void DCX_B(Regs &registers);
    void DCX_D(Regs &registers);
    void DCX_H(Regs &registers);
    void DCX_SP(Regs &registers);
}
#endif

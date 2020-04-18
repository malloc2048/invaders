#ifndef EMULATOR_ARITHMETIC_GROUP_H
#define EMULATOR_ARITHMETIC_GROUP_H

#include "cpu/8080/instruction_set/registers.h"

namespace arithmetic {
    void Add(Registers &registers, uint8_t src, const char* instr);
}

namespace addition {
    void ADD_A(Registers &registers);
    void ADD_B(Registers &registers);
    void ADD_C(Registers &registers);
    void ADD_D(Registers &registers);
    void ADD_E(Registers &registers);
    void ADD_H(Registers &registers);
    void ADD_L(Registers &registers);
    void ADD_M(Registers &registers);

    void ADI(Registers &registers);
    void ACI(Registers &registers);

    void ADC_A(Registers &registers);
    void ADC_B(Registers &registers);
    void ADC_C(Registers &registers);
    void ADC_D(Registers &registers);
    void ADC_E(Registers &registers);
    void ADC_H(Registers &registers);
    void ADC_L(Registers &registers);
    void ADC_M(Registers &registers);

    void dad(uint16_t highByte, uint16_t lowByte, Registers& registers, const char* instr);
    void DAD_B(Registers &registers);
    void DAD_D(Registers &registers);
    void DAD_H(Registers &registers);
    void DAD_SP(Registers &registers);

    void DAA(Registers &registers);
}

namespace subtraction {
    void SUB_A(Registers& registers);
    void SUB_B(Registers& registers);
    void SUB_C(Registers& registers);
    void SUB_D(Registers& registers);
    void SUB_E(Registers& registers);
    void SUB_H(Registers& registers);
    void SUB_L(Registers& registers);
    void SUB_M(Registers& registers);

    void SUI(Registers& registers);
    void SBI(Registers& registers);

    void SBB_A(Registers& registers);
    void SBB_B(Registers& registers);
    void SBB_C(Registers& registers);
    void SBB_D(Registers& registers);
    void SBB_E(Registers& registers);
    void SBB_H(Registers& registers);
    void SBB_L(Registers& registers);
    void SBB_M(Registers& registers);
}

namespace increment {
    void incrementReg(Registers& registers, uint8_t* reg, const char* instr);
    void INR_A(Registers& registers);
    void INR_B(Registers& registers);
    void INR_C(Registers& registers);
    void INR_D(Registers& registers);
    void INR_E(Registers& registers);
    void INR_H(Registers& registers);
    void INR_L(Registers& registers);
    void INR_M(Registers& registers);

    void incrementPair(pair& pc, pair& regPair, const char* instr);
    void INX_B(Registers &registers);
    void INX_D(Registers &registers);
    void INX_H(Registers &registers);
    void INX_SP(Registers &registers);
}

namespace decrement {
    void decrement(Registers& registers, uint8_t* reg, const char* instr);
    void DCR_A(Registers& registers);
    void DCR_B(Registers& registers);
    void DCR_C(Registers& registers);
    void DCR_D(Registers& registers);
    void DCR_E(Registers& registers);
    void DCR_H(Registers& registers);
    void DCR_L(Registers& registers);
    void DCR_M(Registers& registers);

    void DCX_B(Registers &registers);
    void DCX_D(Registers &registers);
    void DCX_H(Registers &registers);
    void DCX_SP(Registers &registers);
}
#endif

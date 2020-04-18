#include "common/config.h"
#include "arithmetic_group.h"

namespace increment {
    void INR_A(Registers& registers) { registers.pc.d16 += 1; }
    void INR_B(Registers& registers) { registers.pc.d16 += 1; }
    void INR_C(Registers& registers) { registers.pc.d16 += 1; }
    void INR_D(Registers& registers) { registers.pc.d16 += 1; }
    void INR_E(Registers& registers) { registers.pc.d16 += 1; }
    void INR_H(Registers& registers) { registers.pc.d16 += 1; }
    void INR_L(Registers& registers) { registers.pc.d16 += 1; }
    void INR_M(Registers& registers) { registers.pc.d16 += 1; }

    void incrementPair(pair& pc, pair& regPair, const char* instr) {
        if(regPair.d8.lowByte == 0xff)
            regPair.d8.highByte += 1;
        regPair.d8.lowByte += 1;
        pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, regPair.d16);
    }

    void INX_B(Registers &registers) { incrementPair(registers.pc, registers.bc, "INX B"); }
    void INX_D(Registers &registers) { incrementPair(registers.pc, registers.de, "INX D"); }
    void INX_H(Registers &registers) { incrementPair(registers.pc, registers.hl, "INX H"); }
    void INX_SP(Registers &registers) { incrementPair(registers.pc, registers.sp, "INX SP"); }
}

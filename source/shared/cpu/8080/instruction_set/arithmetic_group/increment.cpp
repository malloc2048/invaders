#include "common/config.h"
#include "common/utilities.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace increment {
    uint8_t INR(Regs& registers, uint8_t reg, const char* instr) {
        registers.pc.d16 += 1;

        uint8_t value = reg + 1;
        registers.psw.flags.z = value == 0 ? 1 : 0;
        registers.psw.flags.s = value >= 0x80 ? 1 : 0;
        registers.psw.flags.p = Parity(value, 8);
        registers.psw.flags.ac = (value & 0x0fu) < (reg & 0x0fu) ? 1 : 0;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s", instr);

        return value;
    }

    void INR_A(Regs& registers) { registers.a = INR(registers, registers.a, "INR A"); }
    void INR_B(Regs& registers) { registers.bc.d8.highByte = INR(registers, registers.bc.d8.highByte, "INR B"); }
    void INR_C(Regs& registers) { registers.bc.d8.lowByte = INR(registers, registers.bc.d8.lowByte, "INR C"); }
    void INR_D(Regs& registers) { registers.de.d8.highByte = INR(registers, registers.de.d8.highByte, "INR D"); }
    void INR_E(Regs& registers) { registers.de.d8.lowByte = INR(registers, registers.de.d8.lowByte, "INR E"); }
    void INR_H(Regs& registers) { registers.hl.d8.highByte = INR(registers, registers.hl.d8.highByte, "INR H"); }
    void INR_L(Regs& registers) { registers.hl.d8.lowByte = INR(registers, registers.hl.d8.lowByte, "INR L"); }
    void INR_M(Regs& registers) {
        registers.memory[registers.hl.d16] = INR(registers, registers.memory[registers.hl.d16], "INR M");
    }

    void incrementPair(pair& pc, pair& regPair, const char* instr) {
        if(regPair.d8.lowByte == 0xff)
            regPair.d8.highByte += 1;
        regPair.d8.lowByte += 1;
        pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, regPair.d16);
    }

    void INX_B(Regs &registers) { incrementPair(registers.pc, registers.bc, "INX B"); }
    void INX_D(Regs &registers) { incrementPair(registers.pc, registers.de, "INX D"); }
    void INX_H(Regs &registers) { incrementPair(registers.pc, registers.hl, "INX H"); }
    void INX_SP(Regs &registers) { incrementPair(registers.pc, registers.sp, "INX SP"); }
}

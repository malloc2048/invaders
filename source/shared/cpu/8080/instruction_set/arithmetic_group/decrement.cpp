#include "common/config.h"
#include "common/utilities.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace decrement {
    uint8_t decrement(Regs& registers, uint8_t value, const char* instr) {
        value -= 1;
        registers.pc.d16 += 1;

        registers.psw.flags.z = value == 0 ? 1 : 0;
        registers.psw.flags.s = value >= 0x80 ? 1 : 0;
        registers.psw.flags.p = Parity(value, 8);
        registers.psw.flags.ac = (value & 0x0fu) == 0x0fu ? 1 : 0;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %02x", instr, value);

        return value;
    }

    void DCR_A(Regs& registers) { registers.a = decrement(registers, registers.a, "DCR A"); }
    void DCR_B(Regs& registers) { registers.bc.d8.highByte = decrement(registers, registers.bc.d8.highByte, "DCR B"); }
    void DCR_C(Regs& registers) { registers.bc.d8.lowByte = decrement(registers, registers.bc.d8.lowByte, "DCR C"); }
    void DCR_D(Regs& registers) { registers.de.d8.highByte = decrement(registers, registers.de.d8.highByte, "DCR D"); }
    void DCR_E(Regs& registers) { registers.de.d8.lowByte = decrement(registers, registers.de.d8.lowByte, "DCR E"); }
    void DCR_H(Regs& registers) { registers.hl.d8.highByte = decrement(registers, registers.hl.d8.highByte, "DCR H"); }
    void DCR_L(Regs& registers) { registers.hl.d8.lowByte = decrement(registers, registers.hl.d8.lowByte, "DCR L"); }
    void DCR_M(Regs& registers) { registers.memory[registers.hl.d16] = decrement(registers, registers.memory[registers.hl.d16], "DCR M"); }

    uint16_t DCX(Regs& registers, uint16_t value, const char* instr) {
        value -= 1;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s", instr);

        return value;
    }

    void DCX_B(Regs &registers) {
        registers.bc.d16 = DCX(registers, registers.bc.d16, "DCX B");
    }
    void DCX_D(Regs &registers) {
        registers.de.d16 = DCX(registers, registers.de.d16, "DCX D");
    }
    void DCX_H(Regs &registers) {
        registers.hl.d16 = DCX(registers, registers.hl.d16, "DCX H");
    }
    void DCX_SP(Regs &registers) {
        registers.sp.d16 = DCX(registers, registers.sp.d16, "DCX SP");
    }
}

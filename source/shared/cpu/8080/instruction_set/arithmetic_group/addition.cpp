#include "common/config.h"
#include "common/utilities.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace addition {
    void ADD_A_New(MemoryMap& mm) {

    }

    void ADD_A(Regs &registers) {
        arithmetic::Add(registers, registers.a, "ADD A");
    }

    void ADD_B(Regs &registers) {
        arithmetic::Add(registers, registers.bc.d8.highByte, "ADD B");
    }

    void ADD_C(Regs &registers) {
        arithmetic::Add(registers, registers.bc.d8.lowByte, "ADD C");
    }

    void ADD_D(Regs &registers) {
        arithmetic::Add(registers, registers.de.d8.highByte, "ADD D");
    }

    void ADD_E(Regs &registers) {
        arithmetic::Add(registers, registers.de.d8.lowByte, "ADD E");
    }

    void ADD_H(Regs &registers) {
        arithmetic::Add(registers, registers.hl.d8.highByte, "ADD H");
    }

    void ADD_L(Regs &registers) {
        arithmetic::Add(registers, registers.hl.d8.lowByte, "ADD L");
    }

    void ADD_M(Regs &registers) {
        arithmetic::Add(registers, registers.memory[registers.hl.d16], "ADD M");
    }

    void ADI(Regs &registers) {
        uint8_t value = registers.a + registers.memory[registers.pc.d16 + 1];

        registers.psw.flags.z = value == 0 ? 1 : 0;
        registers.psw.flags.s = (value & 0x80u) > 0 ? 1 : 0;
        registers.psw.flags.p = Parity(value, 8);
        registers.psw.flags.cy = registers.a > value;
        registers.psw.flags.ac = (registers.a & 0x00ffu) > (value & 0x00ffu);

        if (IsTraceOn())
            fprintf(TraceOut(), "ADI %02x", registers.memory[registers.pc.d16 + 1]);

        registers.a = value;
        registers.pc.d16 += 2;
    }
    void ACI(Regs &registers) {
        uint8_t value = registers.a + registers.memory[registers.pc.d16 + 1] + registers.psw.flags.cy;

        registers.psw.flags.z = value == 0 ? 1 : 0;
        registers.psw.flags.s = (value & 0x80u) > 0 ? 1 : 0;
        registers.psw.flags.p = Parity(value, 8);
        registers.psw.flags.cy = registers.a > value;
        registers.psw.flags.ac = (registers.a & 0x00ffu) > (value & 0x00ffu);

        if (IsTraceOn())
            fprintf(TraceOut(), "ACI %02x", registers.memory[registers.pc.d16 + 1]);

        registers.a = value;
        registers.pc.d16 += 2;
    }

    void ADC(uint8_t value, Regs& registers, const char* instr) {
        if (IsTraceOn())
            fprintf(TraceOut(), "%s %02x", instr, value);

        uint8_t sum = registers.a + value + registers.psw.flags.cy;
        registers.psw.flags.z = sum == 0 ? 1 : 0;
        registers.psw.flags.s = (sum & 0x80u) > 0 ? 1 : 0;
        registers.psw.flags.p = Parity(sum, 8);
        registers.psw.flags.cy = registers.a > sum;
        registers.psw.flags.ac = (registers.a & 0x00ffu) > (sum & 0x00ffu);

        registers.a = sum;
        registers.pc.d16 += 1;
    }

    void ADC_A(Regs &registers) { ADC(registers.a, registers, "ADC A"); }
    void ADC_B(Regs &registers) { ADC(registers.bc.d8.highByte, registers, "ADC B"); }
    void ADC_C(Regs &registers) { ADC(registers.bc.d8.lowByte, registers, "ADC C"); }
    void ADC_D(Regs &registers) { ADC(registers.de.d8.highByte, registers, "ADC D"); }
    void ADC_E(Regs &registers) { ADC(registers.de.d8.lowByte, registers, "ADC E"); }
    void ADC_H(Regs &registers) { ADC(registers.hl.d8.highByte, registers, "ADC H"); }
    void ADC_L(Regs &registers) { ADC(registers.hl.d8.lowByte, registers, "ADC L"); }
    void ADC_M(Regs &registers) { ADC(registers.memory[registers.hl.d16], registers, "ADC M"); }

    void DAD_B(Regs &registers) { addition::DAD(registers.bc, registers, "DAD B"); }
    void DAD_D(Regs &registers) { addition::DAD(registers.de, registers, "DAD D"); }
    void DAD_H(Regs &registers) { addition::DAD(registers.hl, registers, "DAD H"); }
    void DAD_SP(Regs &registers) { addition::DAD(registers.sp, registers, "DAD SP");
    }

    void DAD(pair& value, Regs& registers, const char* instr) {
        // (H)(L) = (H)(L) + (high)(low)
        uint16_t temp = value.d16;
        registers.hl.d16 += value.d16;
        registers.psw.flags.cy = registers.hl.d16 < temp;
        registers.pc.d16 += 1;

        if (IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, value.d16);
    }

    void DAA(Regs &registers) {
        uint8_t origValue = registers.a;
        if(((registers.a & 0x0fu) > 9) || registers.psw.flags.ac)
            registers.a += 6;
        if(((registers.a & 0xf0u) > 9) || registers.psw.flags.cy)
            registers.a += 0x60;

        registers.psw.flags.z = registers.a == 0 ? 1 : 0;
        registers.psw.flags.s = (registers.a & 0x80u) > 0 ? 1 : 0;
        registers.psw.flags.p = Parity(registers.a, 8);
        registers.psw.flags.cy = origValue > registers.a;
        registers.psw.flags.ac = (origValue & 0x00ffu) > (registers.a & 0x00ffu);
        registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "DAA %02x", registers.a);
    }
}

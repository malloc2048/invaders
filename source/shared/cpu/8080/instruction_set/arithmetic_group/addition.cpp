#include "common/config.h"
#include "arithmetic_group.h"



namespace addition {
    void ADD_A(Registers &registers) { registers.pc.d16 += 1; }

    void ADD_B(Registers &registers) {
        registers.pc.d16 += 1;

        if (IsTraceOn())
            fprintf(TraceOut(), "ADD B %04x %02x\n", registers.hl.d16, registers.psw.flags.cy);
    }

    void ADD_C(Registers &registers) { registers.pc.d16 += 1; }

    void ADD_D(Registers &registers) { registers.pc.d16 += 1; }

    void ADD_E(Registers &registers) { registers.pc.d16 += 1; }

    void ADD_H(Registers &registers) { registers.pc.d16 += 1; }

    void ADD_L(Registers &registers) { registers.pc.d16 += 1; }

    void ADD_M(Registers &registers) { registers.pc.d16 += 1; }

    void ADI(Registers &registers) { registers.pc.d16 += 2; }
    void ACI(Registers &registers) { registers.pc.d16 += 2; }

    void ADC_A(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_B(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_C(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_D(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_E(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_H(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_L(Registers &registers) { registers.pc.d16 += 1; }
    void ADC_M(Registers &registers) { registers.pc.d16 += 1; }

    void DAD_B(Registers &registers) { addition::dad(registers.bc.d8.highByte, registers.bc.d8.lowByte, registers, "DAD B"); }
    void DAD_D(Registers &registers) { addition::dad(registers.de.d8.highByte, registers.de.d8.lowByte, registers, "DAD D"); }
    void DAD_H(Registers &registers) { addition::dad(registers.hl.d8.highByte, registers.hl.d8.lowByte, registers, "DAD H"); }
    void DAD_SP(Registers &registers) {
        addition::dad(registers.sp.d8.highByte, registers.sp.d8.lowByte, registers, "DAD SP");
    }

    void dad(uint16_t highByte, uint16_t lowByte, Registers& registers, const char* instr) {
        lowByte += registers.hl.d8.lowByte;
        highByte += registers.hl.d8.highByte + ((lowByte & 0xff00u) >> 8u);

        registers.hl.d8.lowByte = lowByte & 0xffu;
        registers.hl.d8.highByte = highByte & 0xffu;
        registers.psw.flags.cy = (highByte & 0xff00u) >> 8u;
        registers.pc.d16 += 1;

        if (IsTraceOn())
            fprintf(TraceOut(), "%s %04x %02x", instr, registers.hl.d16, registers.psw.flags.cy);
    }

    void DAA(Registers &registers) { registers.pc.d16 += 1; }
}

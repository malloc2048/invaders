#include "common/config.h"
#include "arithmetic_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace addition {
    void ADD_A(Registers &registers) {
        arithmetic::Add(registers, registers.a, "ADD A");
    }

    void ADD_B(Registers &registers) {
        arithmetic::Add(registers, registers.bc.d8.highByte, "ADD B");
    }

    void ADD_C(Registers &registers) {
        arithmetic::Add(registers, registers.bc.d8.lowByte, "ADD C");
    }

    void ADD_D(Registers &registers) {
        arithmetic::Add(registers, registers.de.d8.highByte, "ADD D");
    }

    void ADD_E(Registers &registers) {
        arithmetic::Add(registers, registers.de.d8.lowByte, "ADD E");
    }

    void ADD_H(Registers &registers) {
        arithmetic::Add(registers, registers.hl.d8.highByte, "ADD H");
    }

    void ADD_L(Registers &registers) {
        arithmetic::Add(registers, registers.hl.d8.lowByte, "ADD L");
    }

    void ADD_M(Registers &registers) {
        arithmetic::Add(registers, registers.memory[registers.hl.d16], "ADD M");
    }

    void ADI(Registers &registers) { machine::Unimplemented(registers); }
    void ACI(Registers &registers) { machine::Unimplemented(registers); }

    void ADC_A(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_B(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_C(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_D(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_E(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_H(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_L(Registers &registers) { machine::Unimplemented(registers); }
    void ADC_M(Registers &registers) { machine::Unimplemented(registers); }

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

    void DAA(Registers &registers) { machine::Unimplemented(registers); }
}

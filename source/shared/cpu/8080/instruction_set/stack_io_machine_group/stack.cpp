#include "common/config.h"
#include "stack_io_machine_group.h"

namespace stack {
    void PUSH_B(Regs& registers) {
        registers.memory[registers.sp.d16 - 2] = registers.bc.d8.lowByte;
        registers.memory[registers.sp.d16 - 1] = registers.bc.d8.highByte;
        registers.sp.d16 -= 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(),
                "PUSH B %02x%02x", registers.memory[registers.sp.d16 + 1], registers.memory[registers.sp.d16]);
    }

    void PUSH_D(Regs& registers) {
        registers.memory[registers.sp.d16 - 2] = registers.de.d8.lowByte;
        registers.memory[registers.sp.d16 - 1] = registers.de.d8.highByte;
        registers.sp.d16 -= 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(),
                    "PUSH D %02x%02x", registers.memory[registers.sp.d16 + 1], registers.memory[registers.sp.d16]);
    }

    void PUSH_H(Regs& registers) {
        registers.memory[registers.sp.d16 - 2] = registers.hl.d8.lowByte;
        registers.memory[registers.sp.d16 - 1] = registers.hl.d8.highByte;
        registers.sp.d16 -= 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(),
                    "PUSH H %02x%02x", registers.memory[registers.sp.d16 + 1], registers.memory[registers.sp.d16]);
    }

    void PUSH_PSW(Regs& registers) {
        registers.memory[registers.sp.d16 - 1] = registers.a;
        registers.memory[registers.sp.d16 - 2] = registers.psw.psw;
        registers.sp.d16 -= 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(),
                    "PUSH PSW %02x%02x", registers.memory[registers.sp.d16 + 1], registers.memory[registers.sp.d16]);
    }

    void POP_B(Regs& registers) {
        registers.bc.d8.lowByte = registers.memory[registers.sp.d16];
        registers.bc.d8.highByte = registers.memory[registers.sp.d16 + 1];
        registers.sp.d16 += 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "POP B %04x", registers.bc.d16);
    }

    void POP_D(Regs& registers) {
        registers.de.d8.lowByte = registers.memory[registers.sp.d16];
        registers.de.d8.highByte = registers.memory[registers.sp.d16 + 1];
        registers.sp.d16 += 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "POP D %04x", registers.de.d16);
    }

    void POP_H(Regs& registers) {
        registers.hl.d8.lowByte = registers.memory[registers.sp.d16];
        registers.hl.d8.highByte = registers.memory[registers.sp.d16 + 1];
        registers.sp.d16 += 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "POP H %04x", registers.hl.d16);
    }

    void POP_PSW(Regs& registers) {
        registers.psw.psw = registers.memory[registers.sp.d16];
        registers.a = registers.memory[registers.sp.d16 + 1];

        registers.sp.d16 += 2;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "POP PSW %02x %02x", registers.a, registers.psw.psw);
    }

    void XTHL(Regs& registers) { machine::Unimplemented(registers); }
    void SPHL(Regs& registers) { machine::Unimplemented(registers); }
}
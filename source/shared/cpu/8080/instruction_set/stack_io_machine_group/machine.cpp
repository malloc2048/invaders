#include <cstdio>
#include <cstdlib>
#include "common/config.h"
#include "stack_io_machine_group.h"

namespace machine {
    void EI(Regs& registers) {
        registers.int_enable = 1;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "EI");
    }

    void DI(Regs& registers) {
        registers.int_enable = 0;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "DI");
    }

    void HLT(Regs& registers) { machine::Unimplemented(registers); }

    void NOP(Regs &registers) {
        registers.pc.d16 += 1;
        if(IsTraceOn())
            fprintf(TraceOut(), "NOP");
    }

    void Unimplemented(Regs &registers) {
//        if(IsTraceOn())
            printf("Unimplemented instruction %02x", registers.memory[registers.pc.d16]);
        exit(-1);
    }
}

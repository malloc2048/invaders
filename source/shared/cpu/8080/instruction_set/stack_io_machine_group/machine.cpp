#include <cstdio>
#include <cstdlib>
#include "common/config.h"
#include "stack_io_machine_group.h"

namespace machine {
    void EI(Registers& registers) { registers.pc.d16 += 1; }
    void DI(Registers& registers) { registers.pc.d16 += 1; }
    void HLT(Registers& registers) { registers.pc.d16 += 1; }

    void NOP(Registers &registers) {
        registers.pc.d16 += 1;
        if(IsTraceOn())
            fprintf(TraceOut(), "NOP");
    }

    void Unimplemented(Registers &registers) {
        if(IsTraceOn())
            fprintf(TraceOut(),"Unimplemented instruction %02x", registers.memory[registers.pc.d16]);
        exit(-1);
    }
}

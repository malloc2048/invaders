#include "common/config.h"
#include "data_transfer_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace store {
    void STA(Regs& registers){
        pair address {};
        address.d8.lowByte = registers.memory[registers.pc.d16 + 1];
        address.d8.highByte = registers.memory[registers.pc.d16 + 2];

        registers.memory[address.d16] = registers.a;
        registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(),
                    "STA %04x", address.d16);
    }

    void SHLD(Regs& registers){
        pair address {};
        address.d8.lowByte = registers.pc.d16 + 1;
        address.d8.highByte = registers.pc.d16 + 2;
        registers.memory[address.d16] = registers.hl.d8.lowByte;

        address.d16 += 1;
        registers.memory[address.d16] = registers.hl.d8.highByte;

        registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "SHLD %04x", address.d16);
    }

    void STAX_B(Regs& registers){
        registers.memory[registers.bc.d16] = registers.a;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "STAX B %02x", registers.a);
    }

    void STAX_D(Regs& registers) {
        registers.memory[registers.de.d16] = registers.a;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "STAX D %02x", registers.a);

    }

    void XCHG(Regs& registers){
        registers.hl.d16 ^= registers.de.d16;
        registers.de.d16 ^= registers.hl.d16;
        registers.hl.d16 ^= registers.de.d16;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(),
                "XCHG %04x %04x", registers.hl.d16, registers.de.d16);
    }
}

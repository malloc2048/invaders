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

    void SHLD(Regs& registers){ machine::Unimplemented(registers); }
    void STAX_B(Regs& registers){ machine::Unimplemented(registers); }
    void STAX_D(Regs& registers){ machine::Unimplemented(registers); }
    
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

#include "common/config.h"
#include "data_transfer_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace store {
    void STA(Registers& registers){ machine::Unimplemented(registers); }
    void SHLD(Registers& registers){ machine::Unimplemented(registers); }
    void STAX_B(Registers& registers){ machine::Unimplemented(registers); }
    void STAX_D(Registers& registers){ machine::Unimplemented(registers); }
    
    void XCHG(Registers& registers){
        registers.hl.d16 ^= registers.de.d16;
        registers.de.d16 ^= registers.hl.d16;
        registers.hl.d16 ^= registers.de.d16;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(),
                "XCHG %04x %04x", registers.hl.d16, registers.de.d16);
    }
}

#include "common/config.h"
#include "data_transfer_group.h"

namespace store {
    void STA(Registers& registers){ registers.pc.d16 += 3; }
    void SHLD(Registers& registers){ registers.pc.d16 += 3; }
    void STAX_B(Registers& registers){ registers.pc.d16 += 1; }
    void STAX_D(Registers& registers){ registers.pc.d16 += 1; }
    
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

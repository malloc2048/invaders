#include "common/config.h"
#include "logical_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace compliment {
    void CMA(Regs& registers) { machine::Unimplemented(registers); }
    void CMC(Regs& registers) { machine::Unimplemented(registers); }
    void STC(Regs& registers) {
        registers.psw.flags.cy = 0x01;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "STC");
    }
}

#include "common/config.h"
#include "stack_io_machine_group.h"

namespace io {
    void IN(Regs& registers) {
        uint8_t inVal = registers.memory[registers.pc.d16 + 1];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "IN %02x", inVal);
    }

    void OUT(Regs& registers) {
        uint8_t outVal = registers.memory[registers.pc.d16 + 1];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "OUT %02x", outVal);
    }
}

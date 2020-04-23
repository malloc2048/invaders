#include "common/config.h"
#include "stack_io_machine_group.h"

namespace io {
    void IN(Regs& registers) {
        uint8_t value = registers.memory[registers.pc.d16 + 1];
        registers.a = registers.ioMemory[value];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "IN %02x", registers.ioMemory[registers.pc.d16 + 1]);
    }

    void OUT(Regs& registers) {
        uint8_t value = registers.memory[registers.pc.d16 + 1];
        registers.ioMemory[value] = registers.memory[registers.a];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "OUT %02x", registers.a);
    }
}

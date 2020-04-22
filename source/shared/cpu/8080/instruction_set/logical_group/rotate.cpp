#include "common/config.h"
#include "logical_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace rotate {
    void RLC(Regs& registers) { machine::Unimplemented(registers); }

    void RRC(Regs& registers) {
        uint8_t lowOrderBit = registers.a & 0x01u;
        registers.a >> 0x01u;
        registers.a &= lowOrderBit << 7u;
        registers.psw.flags.cy = lowOrderBit;

        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RRC");
    }

    void RAL(Regs& registers) { machine::Unimplemented(registers); }
    void RAR(Regs& registers) { machine::Unimplemented(registers); }
}

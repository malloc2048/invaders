#include "common/config.h"
#include "common/utilities.h"
#include "arithmetic_group.h"

namespace arithmetic {
    void Add(Registers &registers, uint8_t src, const char* instr) {
        registers.pc.d16 += 1;
        uint8_t previousA = registers.a;
        registers.a += src;

        registers.psw.flags.z = registers.a == 0x00;
        registers.psw.flags.s = (registers.a & 0x80u) > 0x00 ? 1 : 0;
        registers.psw.flags.p = Parity(registers.a, 8);
        registers.psw.flags.cy = previousA > registers.a ? 1 : 0;
        registers.psw.flags.ac = (previousA & 0x0fu) > (registers.a & 0x0fu) ? 1 : 0;

        if (IsTraceOn())
            fprintf(TraceOut(), "%s %04x %02x", instr, registers.a, registers.psw.flags.cy);
    }
}

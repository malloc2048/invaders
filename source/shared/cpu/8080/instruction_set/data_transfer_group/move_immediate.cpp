#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MVI_C(Regs& registers){ data_transfer::MoveImmediateLow(registers.bc, registers, "MVI C"); }
    void MVI_E(Regs& registers){ data_transfer::MoveImmediateLow(registers.de, registers, "MVI E"); }
    void MVI_L(Regs& registers){ data_transfer::MoveImmediateLow(registers.hl, registers, "MVI L"); }

    void MVI_B(Regs& registers){ data_transfer::MoveImmediateHigh(registers.bc, registers, "MVI B"); }
    void MVI_D(Regs& registers){ data_transfer::MoveImmediateHigh(registers.de, registers, "MVI D"); }
    void MVI_H(Regs& registers){ data_transfer::MoveImmediateHigh(registers.hl, registers, "MVI H"); }

    void MVI_M(Regs& registers){
        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.memory[registers.pc.d16 + 1];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "MVI M %02x", registers.memory[registers.hl.d16]);
    }

    void MVI_A(Regs& registers){
        registers.a = registers.memory[registers.pc.d16 + 1];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "MVI A %02x", registers.a);
    }
}

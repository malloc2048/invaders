#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MVI_C(Registers& registers){ data_transfer::MoveImmediateLow(registers.bc, registers, "MVI C"); }
    void MVI_E(Registers& registers){ data_transfer::MoveImmediateLow(registers.de, registers, "MVI E"); }
    void MVI_L(Registers& registers){ data_transfer::MoveImmediateLow(registers.hl, registers, "MVI L"); }

    void MVI_B(Registers& registers){ data_transfer::MoveImmediateHigh(registers.bc, registers, "MVI B"); }
    void MVI_D(Registers& registers){ data_transfer::MoveImmediateHigh(registers.de, registers, "MVI D"); }
    void MVI_H(Registers& registers){ data_transfer::MoveImmediateHigh(registers.hl, registers, "MVI H"); }

    void MVI_M(Registers& registers){
        registers.memory[registers.hl.d16] = registers.memory[registers.pc.d16 + 1];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "MVI M %02x", registers.memory[registers.hl.d16]);
    }

    void MVI_A(Registers& registers){
        registers.a = registers.memory[registers.pc.d16 + 1];
        registers.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "MVI A %02x", registers.a);
    }
}

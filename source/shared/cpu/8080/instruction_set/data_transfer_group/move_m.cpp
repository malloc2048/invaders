#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MOV_M_B(Regs& registers){
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);

        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.bc.d8.highByte;

        registers.pc.d16 += 1;
    }

    void MOV_M_C(Regs& registers){
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);

        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.bc.d8.lowByte;

        registers.pc.d16 += 1;
    }

    void MOV_M_D(Regs& registers){
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);

        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.de.d8.highByte;

        registers.pc.d16 += 1;
    }

    void MOV_M_E(Regs& registers){
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);

        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.de.d8.lowByte;
        registers.pc.d16 += 1;
    }

    void MOV_M_H(Regs& registers){
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);

        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.hl.d8.highByte;

        registers.pc.d16 += 1;

    }

    void MOV_M_L(Regs& registers){
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.hl.d8.lowByte;

        registers.pc.d16 += 1;
    }

    void MOV_M_A(Regs& registers) {
        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x : %02x", registers.memory[registers.hl.d16], registers.a);

        if(data_transfer::MemCheck(registers.hl.d16))
            registers.memory[registers.hl.d16] = registers.a;

        registers.pc.d16 += 1;
    }
}

#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MOV_M_B(Registers& registers){
        registers.memory[registers.hl.d16] = registers.bc.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }

    void MOV_M_C(Registers& registers){
        registers.memory[registers.hl.d16] = registers.bc.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }

    void MOV_M_D(Registers& registers){
        registers.memory[registers.hl.d16] = registers.de.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }

    void MOV_M_E(Registers& registers){
        registers.memory[registers.hl.d16] = registers.de.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }

    void MOV_M_H(Registers& registers){
        registers.memory[registers.hl.d16] = registers.hl.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }

    void MOV_M_L(Registers& registers){
        registers.memory[registers.hl.d16] = registers.hl.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }

    void MOV_M_A(Registers& registers) {
//        registers.Dump();
        registers.memory[registers.hl.d16] = registers.a;
        registers.pc.d16 += 1;
//        registers.Dump();

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV M, A %02x", registers.memory[registers.hl.d16]);
    }
}

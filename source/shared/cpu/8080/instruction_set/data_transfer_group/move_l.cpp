#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MOV_L_B(Regs& registers){
        registers.hl.d8.lowByte = registers.bc.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, B %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_C(Regs& registers){
        registers.hl.d8.lowByte = registers.bc.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, C %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_D(Regs& registers){
        registers.hl.d8.lowByte = registers.de.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, D %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_E(Regs& registers){
        registers.hl.d8.lowByte = registers.de.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, E %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_H(Regs& registers){
        registers.hl.d8.lowByte = registers.hl.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, H %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_L(Regs& registers){
        registers.hl.d8.lowByte = registers.hl.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, L %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_M(Regs& registers){
        registers.hl.d8.lowByte = registers.memory[registers.hl.d16];
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, M %02x", registers.hl.d8.lowByte);
    }

    void MOV_L_A(Regs& registers) {
        registers.hl.d8.lowByte = registers.a;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV L, A %02x", registers.hl.d8.lowByte);
    }
}

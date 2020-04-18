#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MOV_D_B(Registers& registers){
        registers.de.d8.highByte = registers.bc.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, B %02x", registers.de.d8.highByte);
    }

    void MOV_D_C(Registers& registers){
        registers.de.d8.highByte = registers.bc.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, C %02x", registers.de.d8.highByte);
    }

    void MOV_D_D(Registers& registers){
        registers.de.d8.highByte = registers.de.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B. D %02x", registers.de.d8.highByte);
    }

    void MOV_D_E(Registers& registers){
        registers.de.d8.highByte = registers.de.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, E %02x", registers.de.d8.highByte);
    }

    void MOV_D_H(Registers& registers){
        registers.de.d8.highByte = registers.hl.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, H %02x", registers.de.d8.highByte);
    }

    void MOV_D_L(Registers& registers){
        registers.de.d8.highByte = registers.hl.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, L %02x", registers.de.d8.highByte);
    }

    void MOV_D_M(Registers& registers){
        registers.de.d8.highByte = registers.memory[registers.hl.d16];
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B. M %02x", registers.de.d8.highByte);
    }

    void MOV_D_A(Registers& registers){
        registers.de.d8.highByte = registers.a;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, A %02x", registers.de.d8.highByte);
    }
}

#include "common/config.h"
#include "data_transfer_group.h"

namespace move {
    void MOV_E_B(Regs& registers){
        registers.de.d8.lowByte = registers.bc.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, B %02x", registers.de.d8.lowByte);
    }

    void MOV_E_C(Regs& registers){
        registers.de.d8.lowByte = registers.bc.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, C %02x", registers.de.d8.lowByte);
    }

    void MOV_E_D(Regs& registers){
        registers.de.d8.lowByte = registers.de.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B. D %02x", registers.de.d8.lowByte);
    }

    void MOV_E_E(Regs& registers){
        registers.de.d8.lowByte = registers.de.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, E %02x", registers.de.d8.lowByte);
    }

    void MOV_E_H(Regs& registers){
        registers.de.d8.lowByte = registers.hl.d8.highByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, H %02x", registers.de.d8.lowByte);
    }

    void MOV_E_L(Regs& registers){
        registers.de.d8.lowByte = registers.hl.d8.lowByte;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, L %02x", registers.de.d8.lowByte);
    }

    void MOV_E_M(Regs& registers){
        registers.de.d8.lowByte = registers.memory[registers.hl.d16];
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B. M %02x", registers.de.d8.lowByte);
    }

    void MOV_E_A(Regs& registers){
        registers.de.d8.lowByte = registers.a;
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "MOV B, A %02x", registers.de.d8.lowByte);
    }
}

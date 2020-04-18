#include "common/config.h"
#include "data_transfer_group.h"

namespace load {
    void LXI_B(Registers& registers) { data_transfer::LoadImmediate(registers, registers.bc, "LXI B"); }
    void LXI_D(Registers& registers) { data_transfer::LoadImmediate(registers, registers.de, "LXI D"); }
    void LXI_H(Registers& registers) { data_transfer::LoadImmediate(registers, registers.hl, "LXI H"); }
    void LXI_SP(Registers& registers) { data_transfer::LoadImmediate(registers, registers.sp, "LXI SP"); }

    void LDA(Registers& registers){
        uint16_t address = (registers.memory[registers.pc.d16 + 2] << 8) | registers.memory[registers.pc.d16 + 1];
        registers.a = registers.memory[address];
        registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "LDA %02x", registers.a);
    }
    
    void LHLD(Registers& registers){
        pair address;
        address.d8.highByte = registers.memory[registers.pc.d16 + 2];
        address.d8.lowByte = registers.memory[registers.pc.d16 + 1];
        registers.hl.d8.lowByte = registers.memory[address.d16];
        registers.hl.d8.highByte = registers.memory[address.d16 + 1];
        registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "LHLD %04x", registers.hl);
    }
    
    void LDAX_B(Registers& registers){
        registers.a = registers.memory[registers.bc.d16];
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "LDAX B %02x", registers.a);
    }
    
    void LDAX_D(Registers& registers){
        registers.a = registers.memory[registers.de.d16];
        registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "LDAX D %02x", registers.a);
    }
}

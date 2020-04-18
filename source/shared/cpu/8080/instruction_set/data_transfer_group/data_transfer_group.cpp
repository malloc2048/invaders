#include "common/config.h"
#include "data_transfer_group.h"

namespace data_transfer {
    void MoveImmediateLow(pair& dst, Registers& regs, const char* instr) {
        dst.d8.lowByte = regs.memory[regs.pc.d16 + 1];
        regs.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, dst.d8.lowByte);
    }

    void MoveImmediateHigh(pair& dst, Registers& regs, const char* instr) {
        dst.d8.highByte = regs.memory[regs.pc.d16 + 1];
        regs.pc.d16 += 2;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, dst.d8.lowByte);
    }

    void Move(uint8_t src, uint8_t& dst, uint16_t& pc, const char* instr) {
        dst = src;
        pc += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %02x", instr, dst);
    }

    void LoadImmediate(Registers& registers, pair& reg, const char* instr) {
        reg.d8.lowByte = registers.memory[registers.pc.d16 + 1];
        reg.d8.highByte = registers.memory[registers.pc.d16 + 2];
        registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "%s %04x", instr, reg.d16);
    }
}

#include "branch_group.h"
#include "common/config.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace jump {
    void JMP(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(), "JMP 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);
        branch::Jump(registers);
    }

    void JNZ(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(), "JNZ 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.z == 0) {
            branch::Jump(registers);
        }
        else {
            registers.pc.d16 += 3;
        }
    }

    void JZ(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JZ 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.z == 1) {
            branch::Jump(registers);
        }
        else {
            registers.pc.d16 += 3;
        }
    }

    void JNC(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JNC 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.cy == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;
    }

    void JC(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JC 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.cy == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;
    }

    void JPO(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JPO 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.p == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;
    }

    void JPE(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JPE 0x%02x%02x\n", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.p == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;
    }

    void JP(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JP 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.s == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;
    }

    void JM(Regs& registers) {
        if (IsTraceOn())
            fprintf(TraceOut(),"JM 0x%02x%02x", registers.memory[registers.pc.d16 + 2], registers.memory[registers.pc.d16 + 1]);

        if(registers.psw.flags.s == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;
    }

    void PCHL(Regs& registers) { machine::Unimplemented(registers); }
}

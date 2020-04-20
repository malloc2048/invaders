#include "branch_group.h"
#include "common/config.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace jump {
    void JMP(Registers& registers) {
        branch::Jump(registers);

        if (IsTraceOn())
            fprintf(TraceOut(), "JMP %04x", registers.pc.d16);
    }

    void JNZ(Registers& registers) {
        if(registers.psw.flags.z == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JNZ %04x", registers.pc.d16);

    }

    void JZ(Registers& registers) {
        if(registers.psw.flags.z == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JZ %04x", registers.pc.d16);
    }

    void JNC(Registers& registers) {
        if(registers.psw.flags.cy == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JNC %04x", registers.pc.d16);
    }

    void JC(Registers& registers) {
        if(registers.psw.flags.cy == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JC %04x", registers.pc.d16);
    }

    void JPO(Registers& registers) {
        if(registers.psw.flags.p == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JPO %04x", registers.pc.d16);
    }

    void JPE(Registers& registers) {
        if(registers.psw.flags.p == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JPE %04x", registers.pc.d16);
    }

    void JP(Registers& registers) {
        if(registers.psw.flags.s == 0)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JP %04x", registers.pc.d16);
    }

    void JM(Registers& registers) {
        if(registers.psw.flags.s == 1)
            branch::Jump(registers);
        else
            registers.pc.d16 += 3;

        if (IsTraceOn())
            fprintf(TraceOut(), "JM %04x", registers.pc.d16);
    }

    void PCHL(Registers& registers) { machine::Unimplemented(registers); }
}

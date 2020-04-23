#include "branch_group.h"
#include "common/config.h"

namespace call {
    void CALL(Regs& registers) {
        branch::Call(registers);

        if(IsTraceOn())
            fprintf(TraceOut(), "CALL %04x", registers.pc.d16);
    }

    void RET(Regs& registers) {
        branch::Return(registers);

        if(IsTraceOn())
            fprintf(TraceOut(), "RET %04x", registers.pc.d16);
    }

    void CNZ(Regs& registers) {
        if(registers.psw.flags.z == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CNZ %04x", registers.pc.d16);
    }
    void CZ(Regs& registers) {
        if(registers.psw.flags.z == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CZ %04x", registers.pc.d16);
    }
    void CNC(Regs& registers) {
        if(registers.psw.flags.cy == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CNC %04x", registers.pc.d16);
    }
    void CC(Regs& registers) {
        if(registers.psw.flags.cy == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CC %04x", registers.pc.d16);
    }
    void CPO(Regs& registers) {
        if(registers.psw.flags.p == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CPO %04x", registers.pc.d16);
    }
    void CPE(Regs& registers) {
        if(registers.psw.flags.p == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CPE %04x", registers.pc.d16);
    }
    void CP(Regs& registers) {
        if(registers.psw.flags.s == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CP %04x", registers.pc.d16);
    }
    void CM(Regs& registers) {
        if(registers.psw.flags.s == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CM %04x", registers.pc.d16);
    }

    void RNZ(Regs& registers) {
        if(registers.psw.flags.z == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RNZ %04x", registers.pc.d16);
    }
    void RZ(Regs& registers) {
        if(registers.psw.flags.z == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RZ %04x", registers.pc.d16);
    }
    void RNC(Regs& registers) {
        if(registers.psw.flags.cy == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RNC %04x", registers.pc.d16);
    }
    void RC(Regs& registers) {
        if(registers.psw.flags.cy == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RC %04x", registers.pc.d16);
    }
    void RPO(Regs& registers) {
        if(registers.psw.flags.p == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RPO %04x", registers.pc.d16);
    }
    void RPE(Regs& registers) {
        if(registers.psw.flags.p == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RPE %04x", registers.pc.d16);
    }
    void RP(Regs& registers) {
        if(registers.psw.flags.s == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RP %04x", registers.pc.d16);
    }
    void RM(Regs& registers) {
        if(registers.psw.flags.s == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 1;

        if(IsTraceOn())
            fprintf(TraceOut(), "RM %04x", registers.pc.d16);
    }
}

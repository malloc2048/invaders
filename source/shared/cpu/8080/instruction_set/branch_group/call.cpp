#include "branch_group.h"
#include "common/config.h"

namespace call {
    void CALL(Registers& registers) { 
        branch::Call(registers);

        if(IsTraceOn())
            fprintf(TraceOut(), "CALL %04x", registers.pc.d16);
    }

    void RET(Registers& registers) { 
        branch::Return(registers);

        if(IsTraceOn())
            fprintf(TraceOut(), "RET %04x", registers.pc.d16);
    }

    void CNZ(Registers& registers) {
        if(registers.psw.flags.z == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CNZ %04x", registers.pc.d16);
    }
    void CZ(Registers& registers) {
        if(registers.psw.flags.z == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CZ %04x", registers.pc.d16);
    }
    void CNC(Registers& registers) {
        if(registers.psw.flags.cy == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CNC %04x", registers.pc.d16);
    }
    void CC(Registers& registers) {
        if(registers.psw.flags.cy == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CC %04x", registers.pc.d16);
    }
    void CPO(Registers& registers) {
        if(registers.psw.flags.p == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CPO %04x", registers.pc.d16);
    }
    void CPE(Registers& registers) {
        if(registers.psw.flags.p == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CPE %04x", registers.pc.d16);
    }
    void CP(Registers& registers) {
        if(registers.psw.flags.s == 0)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CP %04x", registers.pc.d16);
    }
    void CM(Registers& registers) {
        if(registers.psw.flags.s == 1)
            branch::Call(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "CM %04x", registers.pc.d16);
    }

    void RNZ(Registers& registers) {
        if(registers.psw.flags.z == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RNZ %04x", registers.pc.d16);
    }
    void RZ(Registers& registers) {
        if(registers.psw.flags.z == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RZ %04x", registers.pc.d16);
    }
    void RNC(Registers& registers) {
        if(registers.psw.flags.cy == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RNC %04x", registers.pc.d16);
    }
    void RC(Registers& registers) {
        if(registers.psw.flags.cy == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RC %04x", registers.pc.d16);
    }
    void RPO(Registers& registers) {
        if(registers.psw.flags.p == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RPO %04x", registers.pc.d16);
    }
    void RPE(Registers& registers) {
        if(registers.psw.flags.p == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RPE %04x", registers.pc.d16);
    }
    void RP(Registers& registers) {
        if(registers.psw.flags.s == 0)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RP %04x", registers.pc.d16);
    }
    void RM(Registers& registers) {
        if(registers.psw.flags.s == 1)
            branch::Return(registers);
        else
            registers.pc.d16 += 3;

        if(IsTraceOn())
            fprintf(TraceOut(), "RM %04x", registers.pc.d16);
    }
}

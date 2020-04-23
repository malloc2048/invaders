#include "branch_group.h"
#include "../stack_io_machine_group/stack_io_machine_group.h"

namespace restart {
    void PushPC(Regs& registers) {
        pair nextAddr = registers.pc;
//        nextAddr.d16 += 1;
        registers.memory[registers.sp.d16 - 1] = nextAddr.d8.highByte;
        registers.memory[registers.sp.d16 - 2] = nextAddr.d8.lowByte;
        registers.sp.d16 -= 2;
    }

    void RST_0(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x00 * 8;
    }

    void RST_1(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x01 * 8;
    }

    void RST_2(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x02 * 8;
    }

    void RST_3(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x03 * 8;
    }

    void RST_4(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x04 * 8;
    }

    void RST_5(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x05 * 8;
    }

    void RST_6(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x06 * 8;
    }

    void RST_7(Regs& registers) {
        PushPC(registers);
        registers.pc.d16 = 0x07 * 8;
    }
}

#include "common/config.h"
#include "branch_group.h"

namespace branch {
    void Jump(Regs &registers) {
        pair address {};
        address.d8.lowByte = registers.memory[registers.pc.d16 + 1];
        address.d8.highByte = registers.memory[registers.pc.d16 + 2];
        registers.pc.d16 = address.d16;
    }

    void Call(Regs& registers) {
        uint16_t retAddress = registers.pc.d16 + 3;
        registers.memory[registers.sp.d16 - 1] = (retAddress & 0xff00u) >> 8u;
        registers.memory[registers.sp.d16 - 2] = (retAddress & 0xffu);
        registers.sp.d16 -= 2;

        Jump(registers);
    }

    void Return(Regs& registers) {
        registers.pc.d8.lowByte = registers.memory[registers.sp.d16];
        registers.pc.d8.highByte = registers.memory[registers.sp.d16 + 1];
        registers.sp.d16 += 2;
    }
}

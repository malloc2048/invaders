#include "hardware/i8080/operations/data_transfer.h"

hardware::DataTransfer::DataTransfer(hardware::Flags &flags, hardware::Memory &memory, hardware::Registers &registers)
    : Operation(flags, memory, registers) {}

void hardware::DataTransfer::execute(byte opcode) {
    byte src = opcode & 0x07u;
    byte dst = (opcode & 0x38u) >> 0x03u;
    byte regPair = ((opcode & 0x30u) >> 0x04u) + BC;

    if(opcode >= 0x40u && opcode <= 0x7f)   // MOV
        setData(dst, getData(src));
    else if((opcode & 0xc7u) == 0x06u)      // MVI
        setData(dst, nextByte());
    else if((opcode & 0xcfu) == 0x01) {     // LXI
        word data = nextWord();
        setData(regPair, data);
    }
    else if(opcode == 0x3a)     // LDA
        registers.accumulator = memory.read_byte(nextWord());
    else if(opcode == 0x32) {    // STA
        memory.write(nextWord(), registers.accumulator);
    } else if(opcode == 0x2a) {   // LHLD
        auto address = nextWord();
        registers.l = memory.read_byte(address);
        registers.h = memory.read_byte(address + 1);
    } else if(opcode == 0x22) { // SHLD
        auto address = nextWord();
        memory.write(address, getData(L));
        memory.write(address + 1, getData(H));
    } else if((opcode & 0xcfu) == 0x0a) { // LDAX
        word address = getData(regPair);
        registers.accumulator = memory.read_byte(address);
    } else if(opcode == 0x02 || opcode == 0x12) // STAX
        memory.write(getData(regPair), registers.accumulator);
    else if(opcode == 0xeb) {
        auto temp = registers.h;
        registers.h = registers.d;
        registers.d = temp;

        temp = registers.l;
        registers.l = registers.e;
        registers.e = temp;
    }
}

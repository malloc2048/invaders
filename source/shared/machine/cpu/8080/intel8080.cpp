#include <bitset>
#include "intel8080.h"
#include "machine/cpu/8080/opcodes/opcodes.h"

void Intel8080::Disassemble() {
    auto opcode = memory->read(registers->pc.d16);
    out << std::hex << std::setw(4) << std::setfill('0') << registers->pc.d16 << "\t";
    opcodes[opcode]->Disassemble(out);
    out << std::endl;
}

void Intel8080::stop() {
    halted = false;
}

void Intel8080::Run(bool showStatus) {
    halted = true;
    while(halted) {
        tick(showStatus);
    }
}

void Intel8080::tick(bool showStatus) {
    if(registers->intEnabled == 1)
        registers->intEnabled = 2;

    auto opcode = memory->read(registers->pc.d16);
    registers->pc.d16 += opcodes[opcode]->Execute(opcode);

    if(showStatus) {
        std::cout << "status:\t";
        std::cout << "Instruction: " << std::hex << std::setfill('0') << std::setw(2) << (unsigned)opcode << "\t";
        std::cout << "A: " << std::hex << std::setfill('0') << std::setw(2) << (unsigned)registers->a << "\t";
        std::cout << "BC: " << std::hex << std::setfill('0') << std::setw(4)  << (unsigned)registers->bc.d16 << "\t";
        std::cout << "DE: " << std::hex << std::setfill('0') << std::setw(4) << (unsigned)registers->de.d16 << "\t";
        std::cout << "HL: " << std::hex << std::setfill('0') << std::setw(4) << (unsigned)registers->hl.d16 << "\t";
        std::cout << "SP: " << std::hex << std::setfill('0') << std::setw(4) << (unsigned)registers->sp.d16 << "\t";
        std::cout << "PC: " << std::hex << std::setfill('0') << std::setw(4) << (unsigned)registers->pc.d16 << "\t";
        std::cout << "INT: " << (unsigned)registers->intEnabled << "\t";

        std::bitset<8>psw(flags->d8);
        std::cout << "PSW: " << std::setfill('0') << std::setw(2) << psw;
        std::cout << std::endl;
    }

    if(registers->intEnabled == 2){
        // TODO: ?????????
    }
}

Intel8080::Intel8080(RAM* memory, Flags* flags, Registers* registers, std::ostream& outputStream):
    out(outputStream), opcodes(), memory(memory), flags(flags), registers(registers) {
    opcodes[0x00] = new NOP(memory, flags, registers);

    OpCode* unimplemented = new Unimplemented(memory, flags, registers);
    opcodes[0x08] = unimplemented;
    opcodes[0x10] = unimplemented;
    opcodes[0x18] = unimplemented;
    opcodes[0x20] = unimplemented;
    opcodes[0x28] = unimplemented;
    opcodes[0x30] = unimplemented;
    opcodes[0x38] = unimplemented;
    opcodes[0xcb] = unimplemented;
    opcodes[0xd9] = unimplemented;
    opcodes[0xdd] = unimplemented;
    opcodes[0xed] = unimplemented;
    opcodes[0xfd] = unimplemented;

    OpCode* lxi = new LXI(memory, flags, registers);
    opcodes[0x01] = lxi;
    opcodes[0x11] = lxi;
    opcodes[0x21] = lxi;
    opcodes[0x31] = lxi;

    OpCode* stax = new STAX(memory, flags, registers);
    opcodes[0x02] = stax;
    opcodes[0x12] = stax;

    OpCode* inx = new INX(memory, flags, registers);
    opcodes[0x03] = inx;
    opcodes[0x13] = inx;
    opcodes[0x23] = inx;
    opcodes[0x33] = inx;

    OpCode* inr = new INR(memory, flags, registers);
    opcodes[0x04] = inr;
    opcodes[0x0c] = inr;
    opcodes[0x14] = inr;
    opcodes[0x1c] = inr;
    opcodes[0x24] = inr;
    opcodes[0x2c] = inr;
    opcodes[0x34] = inr;
    opcodes[0x3c] = inr;

    OpCode* dcr = new DCR(memory, flags, registers);
    opcodes[0x05] = dcr;
    opcodes[0x0d] = dcr;
    opcodes[0x15] = dcr;
    opcodes[0x1d] = dcr;
    opcodes[0x25] = dcr;
    opcodes[0x2d] = dcr;
    opcodes[0x35] = dcr;
    opcodes[0x3d] = dcr;

    OpCode* mvi = new MVI(memory, flags, registers);
    opcodes[0x06] = mvi;
    opcodes[0x0e] = mvi;
    opcodes[0x16] = mvi;
    opcodes[0x1e] = mvi;
    opcodes[0x26] = mvi;
    opcodes[0x2e] = mvi;
    opcodes[0x36] = mvi;
    opcodes[0x3e] = mvi;

    OpCode* rotate = new Rotate(memory, flags, registers);
    opcodes[0x07] = rotate;
    opcodes[0x0f] = rotate;
    opcodes[0x17] = rotate;
    opcodes[0x1f] = rotate;

    OpCode* dad = new DAD(memory, flags, registers);
    opcodes[0x09] = dad;
    opcodes[0x19] = dad;
    opcodes[0x29] = dad;
    opcodes[0x39] = dad;

    OpCode* ldax = new LDAX(memory, flags, registers);
    opcodes[0x0a] = ldax;
    opcodes[0x1a] = ldax;

    OpCode* dcx = new DCX(memory, flags, registers);
    opcodes[0x0b] = dcx;
    opcodes[0x1b] = dcx;
    opcodes[0x2b] = dcx;
    opcodes[0x3b] = dcx;

    opcodes[0x22] = new SHLD(memory, flags, registers);
    opcodes[0x27] = new DAA(memory, flags, registers);
    opcodes[0x2a] = new LHLD(memory, flags, registers);
    opcodes[0x2f] = new CMA(memory, flags, registers);
    opcodes[0x32] = new STA(memory, flags, registers);
    opcodes[0x37] = new STC(memory, flags, registers);
    opcodes[0x3a] = new LDA(memory, flags, registers);
    opcodes[0x3f] = new CMC(memory, flags, registers);

    OpCode* mov = new MOV(memory, flags, registers);

    // MOV to B
    opcodes[0x40] = mov;
    opcodes[0x41] = mov;
    opcodes[0x42] = mov;
    opcodes[0x43] = mov;
    opcodes[0x44] = mov;
    opcodes[0x45] = mov;
    opcodes[0x46] = mov;
    opcodes[0x47] = mov;

    // MOV to C
    opcodes[0x48] = mov;
    opcodes[0x49] = mov;
    opcodes[0x4a] = mov;
    opcodes[0x4b] = mov;
    opcodes[0x4c] = mov;
    opcodes[0x4d] = mov;
    opcodes[0x4e] = mov;
    opcodes[0x4f] = mov;

    // MOV to D
    opcodes[0x50] = mov;
    opcodes[0x51] = mov;
    opcodes[0x52] = mov;
    opcodes[0x53] = mov;
    opcodes[0x54] = mov;
    opcodes[0x55] = mov;
    opcodes[0x56] = mov;
    opcodes[0x57] = mov;

    // MOV to E
    opcodes[0x58] = mov;
    opcodes[0x59] = mov;
    opcodes[0x5a] = mov;
    opcodes[0x5b] = mov;
    opcodes[0x5c] = mov;
    opcodes[0x5d] = mov;
    opcodes[0x5e] = mov;
    opcodes[0x5f] = mov;

    // MOV to H
    opcodes[0x60] = mov;
    opcodes[0x61] = mov;
    opcodes[0x62] = mov;
    opcodes[0x63] = mov;
    opcodes[0x64] = mov;
    opcodes[0x65] = mov;
    opcodes[0x66] = mov;
    opcodes[0x67] = mov;

    // MOV to L
    opcodes[0x68] = mov;
    opcodes[0x69] = mov;
    opcodes[0x6a] = mov;
    opcodes[0x6b] = mov;
    opcodes[0x6c] = mov;
    opcodes[0x6d] = mov;
    opcodes[0x6e] = mov;
    opcodes[0x6f] = mov;

    // MOV to Memory
    opcodes[0x70] = mov;
    opcodes[0x71] = mov;
    opcodes[0x72] = mov;
    opcodes[0x73] = mov;
    opcodes[0x74] = mov;
    opcodes[0x75] = mov;
    opcodes[0x77] = mov;

    // MOV to A
    opcodes[0x78] = mov;
    opcodes[0x79] = mov;
    opcodes[0x7a] = mov;
    opcodes[0x7b] = mov;
    opcodes[0x7c] = mov;
    opcodes[0x7d] = mov;
    opcodes[0x7e] = mov;
    opcodes[0x7f] = mov;

    opcodes[0x76] = new HLT(memory, flags, registers);

    OpCode* add = new ADD(memory, flags, registers);
    opcodes[0x80] = add;
    opcodes[0x81] = add;
    opcodes[0x82] = add;
    opcodes[0x83] = add;
    opcodes[0x84] = add;
    opcodes[0x85] = add;
    opcodes[0x86] = add;
    opcodes[0x87] = add;

    OpCode* adc = new ADC(memory, flags, registers);
    opcodes[0x88] = adc;
    opcodes[0x89] = adc;
    opcodes[0x8a] = adc;
    opcodes[0x8b] = adc;
    opcodes[0x8c] = adc;
    opcodes[0x8d] = adc;
    opcodes[0x8e] = adc;
    opcodes[0x8f] = adc;

    OpCode* sub = new SUB(memory, flags, registers);
    opcodes[0x90] = sub;
    opcodes[0x91] = sub;
    opcodes[0x92] = sub;
    opcodes[0x93] = sub;
    opcodes[0x94] = sub;
    opcodes[0x95] = sub;
    opcodes[0x96] = sub;
    opcodes[0x97] = sub;

    OpCode* sbb = new SBB(memory, flags, registers);
    opcodes[0x98] = sbb;
    opcodes[0x99] = sbb;
    opcodes[0x9a] = sbb;
    opcodes[0x9b] = sbb;
    opcodes[0x9c] = sbb;
    opcodes[0x9d] = sbb;
    opcodes[0x9e] = sbb;
    opcodes[0x9f] = sbb;

    OpCode* ana = new ANA(memory, flags, registers);
    opcodes[0xa0] = ana;
    opcodes[0xa1] = ana;
    opcodes[0xa2] = ana;
    opcodes[0xa3] = ana;
    opcodes[0xa4] = ana;
    opcodes[0xa5] = ana;
    opcodes[0xa6] = ana;
    opcodes[0xa7] = ana;

    OpCode* xra = new XRA(memory, flags, registers);
    opcodes[0xa8] = xra;
    opcodes[0xa9] = xra;
    opcodes[0xaa] = xra;
    opcodes[0xab] = xra;
    opcodes[0xac] = xra;
    opcodes[0xad] = xra;
    opcodes[0xae] = xra;
    opcodes[0xaf] = xra;

    OpCode* ora = new ORA(memory, flags, registers);
    opcodes[0xb0] = ora;
    opcodes[0xb1] = ora;
    opcodes[0xb2] = ora;
    opcodes[0xb3] = ora;
    opcodes[0xb4] = ora;
    opcodes[0xb5] = ora;
    opcodes[0xb6] = ora;
    opcodes[0xb7] = ora;

    OpCode* cmp = new CMP(memory, flags, registers);
    opcodes[0xb8] = cmp;
    opcodes[0xb9] = cmp;
    opcodes[0xba] = cmp;
    opcodes[0xbb] = cmp;
    opcodes[0xbc] = cmp;
    opcodes[0xbd] = cmp;
    opcodes[0xbe] = cmp;
    opcodes[0xbf] = cmp;

    OpCode* ret = new Return(memory, flags, registers);
    opcodes[0xc0] = ret;
    opcodes[0xc8] = ret;
    opcodes[0xc9] = ret;
    opcodes[0xd0] = ret;
    opcodes[0xd8] = ret;
    opcodes[0xe0] = ret;
    opcodes[0xe8] = ret;
    opcodes[0xf0] = ret;
    opcodes[0xf8] = ret;

    OpCode* pop = new POP(memory, flags, registers);
    opcodes[0xc1] = pop;
    opcodes[0xd1] = pop;
    opcodes[0xe1] = pop;
    opcodes[0xf1] = pop;

    OpCode* jump = new Jump(memory, flags, registers);
    opcodes[0xc2] = jump;
    opcodes[0xc3] = jump;
    opcodes[0xca] = jump;
    opcodes[0xd2] = jump;
    opcodes[0xda] = jump;
    opcodes[0xe2] = jump;
    opcodes[0xea] = jump;
    opcodes[0xf2] = jump;
    opcodes[0xfa] = jump;

    OpCode* call = new CALL(memory, flags, registers);
    opcodes[0xc4] = call;
    opcodes[0xcc] = call;
    opcodes[0xcd] = call;
    opcodes[0xd4] = call;
    opcodes[0xdc] = call;
    opcodes[0xe4] = call;
    opcodes[0xec] = call;
    opcodes[0xf4] = call;
    opcodes[0xfc] = call;

    OpCode* push = new PUSH(memory, flags, registers);
    opcodes[0xc5] = push;
    opcodes[0xd5] = push;
    opcodes[0xe5] = push;
    opcodes[0xf5] = push;

    OpCode* rst = new RST(memory, flags, registers);
    opcodes[0xc7] = rst;
    opcodes[0xcf] = rst;
    opcodes[0xd7] = rst;
    opcodes[0xdf] = rst;
    opcodes[0xe7] = rst;
    opcodes[0xef] = rst;
    opcodes[0xf7] = rst;
    opcodes[0xff] = rst;

    opcodes[0xc6] = new ADI(memory, flags, registers);
    opcodes[0xce] = new ACI(memory, flags, registers);
    opcodes[0xd3] = new OUT(memory, flags, registers);
    opcodes[0xd6] = new SUI(memory, flags, registers);
    opcodes[0xdb] = new IN(memory, flags, registers);
    opcodes[0xde] = new SBI(memory, flags, registers);
    opcodes[0xe3] = new XTHL(memory, flags, registers);
    opcodes[0xe6] = new ANI(memory, flags, registers);
    opcodes[0xe9] = new PCHL(memory, flags, registers);
    opcodes[0xeb] = new XCHG(memory, flags, registers);
    opcodes[0xee] = new XRI(memory, flags, registers);
    opcodes[0xf3] = new DI(memory, flags, registers);
    opcodes[0xf6] = new ORI(memory, flags, registers);
    opcodes[0xf9] = new SPHL(memory, flags, registers);
    opcodes[0xfb] = new EI(memory, flags, registers);
    opcodes[0xfe] = new CPI(memory, flags, registers);
}

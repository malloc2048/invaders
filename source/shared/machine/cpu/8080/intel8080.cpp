#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#include <bitset>
#include <fstream>
#include "constants.h"
#include "intel8080.h"
#include "machine/cpu/8080/opcodes/opcodes.h"

void Intel8080::Disassemble() {
    auto opcode = memory->read(registers->pc.d16);

    out << std::hex << std::setw(4) << std::setfill('0') << registers->pc.d16 << "\t";
    opcodes[opcode]->Disassemble(out);
    out << std::endl;
}

void Intel8080::stop() {
    halted = true;
}

void Intel8080::Run(bool showStatus) {
    debug_output.open("../../../roms/debug.out");;

    halted = false;
    while(!halted) {
        tick(showStatus);
    }
}

void Intel8080::tick(bool showStatus) {
    if(registers->interruptPending && registers->intEnabled && registers->interruptDelay == 0) {
        registers->interruptPending = false;
        registers->intEnabled = 0;
        registers->halted = false;
        registers->pc.d16 += opcodes[registers->interruptVector]->Execute(registers->interruptVector, out);

    } else {
        auto opcode = memory->read(registers->pc.d16);
        cycles += OPCODES_CYCLES[opcode];
        registers->pc.d16 += opcodes[opcode]->Execute(opcode, out);
    }
}

void Intel8080::interrupt(uint8_t interruptNumber) {
    registers->interruptPending = true;
    registers->interruptVector = interruptNumber << 3 & 0xffu;
}

Intel8080::Intel8080(Memory* memory, Flags* flags, Registers* registers, std::ostream& outputStream):
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

const std::string Intel8080::Nemonics[256] = {
    "00 NOP        ",
    "01 LXI B, D16 ",
    "02 STAX B     ",
    "03 INX B      ",
    "04 INR B      ",
    "05 DCR B      ",
    "06 MVI B, D8  ",
    "07 RLC        ",
    "08 UNIMPLEMENTED",
    "09 DAD B      ",
    "0A LDAX B     ",
    "0B DCX B      ",
    "0C INR C      ",
    "0D DCR C      ",
    "0E MVI C, D8  ",
    "0F RRC        ",
    "10 UNIMPLEMENTED",
    "11 LXI D, D16 ",
    "12 STAX D     ",
    "13 INX D      ",
    "14 INR D      ",
    "15 DCR D      ",
    "16 MVI D, D8  ",
    "17 RAL        ",
    "18 UNIMPLEMENTED",
    "19 DAD D      ",
    "1A LDAX D     ",
    "1B DCX D      ",
    "1C INR E      ",
    "1D DCR E      ",
    "1E MVI E, D8  ",
    "1F RAR        ",
    "20 UNIMPLEMENTED",
    "21 LXI H, D16 ",
    "22 SHLD adr   ",
    "23 INX H      ",
    "24 INR H      ",
    "25 DCR H      ",
    "26 MVI H, D8  ",
    "27 DAA        ",
    "28 UNIMPLEMENTED",
    "29 DAD H      ",
    "2A LHLD adr   ",
    "2B DCX H      ",
    "2C INR L      ",
    "2D DCR L      ",
    "2E MVI L, D8  ",
    "2F CMA        ",
    "30 UNIMPLEMENTED",
    "31 LXI SP, D16",
    "32 STA adr    ",
    "33 INX SP     ",
    "34 INR M      ",
    "35 DCR M      ",
    "36 MVI M, D8  ",
    "37 STC        ",
    "38 UNIMPLEMENTED",
    "39 DAD SP     ",
    "3A LDA adr    ",
    "3B DCX SP     ",
    "3C INR A      ",
    "3D DCR A      ",
    "3E MVI A, D8  ",
    "3F CMC        ",
    "40 MOV B, B   ",
    "41 MOV B, C   ",
    "42 MOV B, D   ",
    "43 MOV B, E   ",
    "44 MOV B, H   ",
    "45 MOV B, L   ",
    "46 MOV B, M   ",
    "47 MOV B, A   ",
    "48 MOV C, B   ",
    "49 MOV C, C   ",
    "4A MOV C, D   ",
    "4B MOV C, E   ",
    "4C MOV C, H   ",
    "4D MOV C, L   ",
    "4E MOV C, M   ",
    "4F MOV C, A   ",
    "50 MOV D, B   ",
    "51 MOV D, C   ",
    "52 MOV D, D   ",
    "53 MOV D, E   ",
    "54 MOV D, H   ",
    "55 MOV D, L   ",
    "56 MOV D, M   ",
    "57 MOV D, A   ",
    "58 MOV E, B   ",
    "59 MOV E, C   ",
    "5A MOV E, D   ",
    "5B MOV E, E   ",
    "5C MOV E, H   ",
    "5D MOV E, L   ",
    "5E MOV E, M   ",
    "5F MOV E, A   ",
    "60 MOV H, B   ",
    "61 MOV H, C   ",
    "62 MOV H, D   ",
    "63 MOV H, E   ",
    "64 MOV H, H   ",
    "65 MOV H, L   ",
    "66 MOV H, M   ",
    "67 MOV H, A   ",
    "68 MOV L, B   ",
    "69 MOV L, C   ",
    "6A MOV L, D   ",
    "6B MOV L, E   ",
    "6C MOV L, H   ",
    "6D MOV L, L   ",
    "6E MOV L, M   ",
    "6F MOV L, A   ",
    "70 MOV M, B   ",
    "71 MOV M, C   ",
    "72 MOV M, D   ",
    "73 MOV M, E   ",
    "74 MOV M, H   ",
    "75 MOV M, L   ",
    "76 HLT        ",
    "77 MOV M, A   ",
    "78 MOV A, B   ",
    "79 MOV A, C   ",
    "7A MOV A, D   ",
    "7B MOV A, E   ",
    "7C MOV A, H   ",
    "7D MOV A, L   ",
    "7E MOV A, M   ",
    "7F MOV A, A   ",
    "80 ADD B      ",
    "81 ADD C      ",
    "82 ADD D      ",
    "83 ADD E      ",
    "84 ADD H      ",
    "85 ADD L      ",
    "86 ADD M      ",
    "87 ADD A      ",
    "88 ADC B      ",
    "89 ADC C      ",
    "8A ADC D      ",
    "8B ADC E      ",
    "8C ADC H      ",
    "8D ADC L      ",
    "8E ADC M      ",
    "8F ADC A      ",
    "90 SUB B      ",
    "91 SUB C      ",
    "92 SUB D      ",
    "93 SUB E      ",
    "94 SUB H      ",
    "95 SUB L      ",
    "96 SUB M      ",
    "97 SUB A      ",
    "98 SBB B      ",
    "99 SBB C      ",
    "9A SBB D      ",
    "9B SBB E      ",
    "9C SBB H      ",
    "9D SBB L      ",
    "9E SBB M      ",
    "9F SBB A      ",
    "A0 ANA B      ",
    "A1 ANA C      ",
    "A2 ANA D      ",
    "A3 ANA E      ",
    "A4 ANA H      ",
    "A5 ANA L      ",
    "A6 ANA M      ",
    "A7 ANA A      ",
    "A8 XRA B      ",
    "A9 XRA C      ",
    "AA XRA D      ",
    "AB XRA E      ",
    "AC XRA H      ",
    "AD XRA L      ",
    "AE XRA M      ",
    "AF XRA A      ",
    "B0 ORA B      ",
    "B1 ORA C      ",
    "B2 ORA D      ",
    "B3 ORA E      ",
    "B4 ORA H      ",
    "B5 ORA L      ",
    "B6 ORA M      ",
    "B7 ORA A      ",
    "B8 CMP B      ",
    "B9 CMP C      ",
    "BA CMP D      ",
    "BB CMP E      ",
    "BC CMP H      ",
    "BD CMP L      ",
    "BE CMP M      ",
    "BF CMP A      ",
    "C0 RNZ        ",
    "C1 POP B      ",
    "C2 JNZ ADR    ",
    "C3 JMP ADR    ",
    "C4 CNZ ADR    ",
    "C5 PUSH B     ",
    "C6 ADI D8     ",
    "C7 RST 0      ",
    "C8 RZ         ",
    "C9 RET        ",
    "CA JZ ADR     ",
    "CB UNIMPLEMENTED",
    "CC CZ ADR     ",
    "CD CALL ADR   ",
    "CE ACI D8     ",
    "CF RST 1      ",
    "D0 RNC        ",
    "D1 POP D      ",
    "D2 JNC ADR    ",
    "D3 OUT D8     ",
    "D4 CNC ADR    ",
    "D5 PUSH D     ",
    "D6 SUI D8     ",
    "D7 RST 2      ",
    "D8 RC         ",
    "D9 UNIMPLEMENTED",
    "DA JC ADR     ",
    "DB IN D8      ",
    "DC CC ADR     ",
    "DD UNIMPLEMENTED",
    "DE SBI D8     ",
    "DF RST 3      ",
    "E0 RPO        ",
    "E1 POP H      ",
    "E2 JPO ADR    ",
    "E3 XTHL       ",
    "E4 CPO ADR    ",
    "E5 PUSH H     ",
    "E6 ANI D8     ",
    "E7 RST 4      ",
    "E8 RPE        ",
    "E9 PCHL       ",
    "EA JPE ADR    ",
    "EB XCHG       ",
    "EC CPE ADR    ",
    "ED UNIMPLEMENTED",
    "EE XRI D8     ",
    "EF RST 5      ",
    "F0 RP         ",
    "F1 POP PSW    ",
    "F2 JP ADR     ",
    "F3 DI         ",
    "F4 CP ADR     ",
    "F5 PUSH PSW   ",
    "F6 ORI D8     ",
    "F7 RST 6      ",
    "F8 RM         ",
    "F9 SPHL       ",
    "FA JM ADR     ",
    "FB EI         ",
    "FC CM ADR     ",
    "FD UNIMPLEMENTED",
    "FE CPI D8     ",
    "FF RST 7      "
};

#pragma clang diagnostic pop
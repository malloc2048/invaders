#include "intel8080.h"
#include "opcodes/opcodes.h"

void Intel8080::cycle() {
    if(registers->intEnabled == 1)
        registers->intEnabled = 2;

    auto opcode = ram->read(registers->pc.d16);
    registers->pc.d16 += opcodes[opcode]->Execute(opcode);

    if(registers->intEnabled == 2){
        // TODO: ?????????
    }
}

Intel8080::Intel8080() : ram(new RAM()), flags(new Flags()), registers(new Registers()) {
    opcodes[0x00] = static_cast<const std::shared_ptr<OpCode>>(new NOP(ram, flags, registers));

    std::shared_ptr<OpCode> unimplemented(new Unimplemented(ram, flags, registers));
    opcodes[0x08] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0x10] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0x18] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0x20] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0x28] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0x30] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0x38] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0xcb] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0xd9] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0xdd] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0xed] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);
    opcodes[0xfd] = static_cast<const std::shared_ptr<OpCode>>(unimplemented);

    std::shared_ptr<OpCode> lxi(new LXI(ram, flags, registers));
    opcodes[0x01] = static_cast<const std::shared_ptr<OpCode>>(lxi);
    opcodes[0x11] = static_cast<const std::shared_ptr<OpCode>>(lxi);
    opcodes[0x21] = static_cast<const std::shared_ptr<OpCode>>(lxi);
    opcodes[0x31] = static_cast<const std::shared_ptr<OpCode>>(lxi);

    std::shared_ptr<OpCode> stax(new STAX(ram, flags, registers));
    opcodes[0x02] = static_cast<const std::shared_ptr<OpCode>>(stax);
    opcodes[0x12] = static_cast<const std::shared_ptr<OpCode>>(stax);

    std::shared_ptr<OpCode> inx(new INX(ram, flags, registers));
    opcodes[0x03] = static_cast<const std::shared_ptr<OpCode>>(inx);
    opcodes[0x13] = static_cast<const std::shared_ptr<OpCode>>(inx);
    opcodes[0x23] = static_cast<const std::shared_ptr<OpCode>>(inx);
    opcodes[0x33] = static_cast<const std::shared_ptr<OpCode>>(inx);

    std::shared_ptr<OpCode> inr(new INR(ram, flags, registers));
    opcodes[0x04] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x0c] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x14] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x1c] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x24] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x2c] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x34] = static_cast<const std::shared_ptr<OpCode>>(inr);
    opcodes[0x3c] = static_cast<const std::shared_ptr<OpCode>>(inr);

    std::shared_ptr<OpCode> dcr(new DCR(ram, flags, registers));
    opcodes[0x05] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x0d] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x15] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x1d] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x25] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x2d] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x35] = static_cast<const std::shared_ptr<OpCode>>(dcr);
    opcodes[0x3d] = static_cast<const std::shared_ptr<OpCode>>(dcr);

    std::shared_ptr<OpCode> mvi(new MVI(ram, flags, registers));
    opcodes[0x06] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x0e] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x16] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x1e] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x26] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x2e] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x36] = static_cast<const std::shared_ptr<OpCode>>(mvi);
    opcodes[0x3e] = static_cast<const std::shared_ptr<OpCode>>(mvi);

    std::shared_ptr<OpCode> rotate(new Rotate(ram, flags, registers));
    opcodes[0x07] = static_cast<const std::shared_ptr<OpCode>>(rotate);
    opcodes[0x0f] = static_cast<const std::shared_ptr<OpCode>>(rotate);
    opcodes[0x17] = static_cast<const std::shared_ptr<OpCode>>(rotate);
    opcodes[0x2f] = static_cast<const std::shared_ptr<OpCode>>(rotate);

    std::shared_ptr<OpCode> dad(new DAD(ram, flags, registers));
    opcodes[0x09] = static_cast<const std::shared_ptr<OpCode>>(dad);
    opcodes[0x19] = static_cast<const std::shared_ptr<OpCode>>(dad);
    opcodes[0x29] = static_cast<const std::shared_ptr<OpCode>>(dad);
    opcodes[0x39] = static_cast<const std::shared_ptr<OpCode>>(dad);

    std::shared_ptr<OpCode> ldax(new LDAX(ram, flags, registers));
    opcodes[0x0a] = static_cast<const std::shared_ptr<OpCode>>(ldax);
    opcodes[0x1a] = static_cast<const std::shared_ptr<OpCode>>(ldax);

    std::shared_ptr<OpCode> dcx(new DCX(ram, flags, registers));
    opcodes[0x0b] = static_cast<const std::shared_ptr<OpCode>>(dcx);
    opcodes[0x1b] = static_cast<const std::shared_ptr<OpCode>>(dcx);
    opcodes[0x2b] = static_cast<const std::shared_ptr<OpCode>>(dcx);
    opcodes[0x3b] = static_cast<const std::shared_ptr<OpCode>>(dcx);

    opcodes[0x22] = static_cast<const std::shared_ptr<OpCode>>(new SHLD(ram, flags, registers));
    opcodes[0x27] = static_cast<const std::shared_ptr<OpCode>>(new DAA(ram, flags, registers));
    opcodes[0x2a] = static_cast<const std::shared_ptr<OpCode>>(new LHLD(ram, flags, registers));
    opcodes[0x2f] = static_cast<const std::shared_ptr<OpCode>>(new CMA(ram, flags, registers));
    opcodes[0x32] = static_cast<const std::shared_ptr<OpCode>>(new STA(ram, flags, registers));
    opcodes[0x37] = static_cast<const std::shared_ptr<OpCode>>(new STC(ram, flags, registers));
    opcodes[0x3a] = static_cast<const std::shared_ptr<OpCode>>(new LDA(ram, flags, registers));
    opcodes[0x3f] = static_cast<const std::shared_ptr<OpCode>>(new CMC(ram, flags, registers));

    std::shared_ptr<OpCode> mov(new MOV(ram, flags, registers));

    // MOV to B
    opcodes[0x40] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x41] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x42] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x43] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x44] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x45] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x46] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x47] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to C
    opcodes[0x48] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x49] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x4a] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x4b] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x4c] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x4d] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x4e] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x4f] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to D
    opcodes[0x50] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x51] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x52] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x53] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x54] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x55] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x56] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x57] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to E
    opcodes[0x58] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x59] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x5a] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x5b] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x5c] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x5d] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x5e] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x5f] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to H
    opcodes[0x60] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x61] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x62] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x63] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x64] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x65] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x66] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x67] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to L
    opcodes[0x68] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x69] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x6a] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x6b] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x6c] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x6d] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x6e] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x6f] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to Memory
    opcodes[0x70] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x71] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x72] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x73] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x74] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x75] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x77] = static_cast<const std::shared_ptr<OpCode>>(mov);

    // MOV to A
    opcodes[0x78] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x79] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x7a] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x7b] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x7c] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x7d] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x7e] = static_cast<const std::shared_ptr<OpCode>>(mov);
    opcodes[0x7f] = static_cast<const std::shared_ptr<OpCode>>(mov);

    opcodes[0x76] = static_cast<const std::shared_ptr<OpCode>>(new HLT(ram, flags, registers));

    std::shared_ptr<OpCode> add(new ADD(ram, flags, registers));
    opcodes[0x80] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x81] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x82] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x83] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x84] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x85] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x86] = static_cast<const std::shared_ptr<OpCode>>(add);
    opcodes[0x87] = static_cast<const std::shared_ptr<OpCode>>(add);

    std::shared_ptr<OpCode> adc(new ADC(ram, flags, registers));
    opcodes[0x88] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x89] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x8a] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x8b] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x8c] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x8d] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x8e] = static_cast<const std::shared_ptr<OpCode>>(adc);
    opcodes[0x8f] = static_cast<const std::shared_ptr<OpCode>>(adc);

    std::shared_ptr<OpCode> sub(new SUB(ram, flags, registers));
    opcodes[0x90] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x91] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x92] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x93] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x94] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x95] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x96] = static_cast<const std::shared_ptr<OpCode>>(sub);
    opcodes[0x97] = static_cast<const std::shared_ptr<OpCode>>(sub);

    std::shared_ptr<OpCode> sbb(new SBB(ram, flags, registers));
    opcodes[0x98] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x99] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x9a] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x9b] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x9c] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x9d] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x9e] = static_cast<const std::shared_ptr<OpCode>>(sbb);
    opcodes[0x9f] = static_cast<const std::shared_ptr<OpCode>>(sbb);

    std::shared_ptr<OpCode> ana(new ANA(ram, flags, registers));
    opcodes[0xa0] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa1] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa2] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa3] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa4] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa5] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa6] = static_cast<const std::shared_ptr<OpCode>>(ana);
    opcodes[0xa7] = static_cast<const std::shared_ptr<OpCode>>(ana);

    std::shared_ptr<OpCode> xra(new XRA(ram, flags, registers));
    opcodes[0xa8] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xa9] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xaa] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xab] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xac] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xad] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xae] = static_cast<const std::shared_ptr<OpCode>>(xra);
    opcodes[0xaf] = static_cast<const std::shared_ptr<OpCode>>(xra);

    std::shared_ptr<OpCode> ora(new ORA(ram, flags, registers));
    opcodes[0xb0] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb1] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb2] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb3] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb4] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb5] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb6] = static_cast<const std::shared_ptr<OpCode>>(ora);
    opcodes[0xb7] = static_cast<const std::shared_ptr<OpCode>>(ora);

    std::shared_ptr<OpCode> cmp(new CMP(ram, flags, registers));
    opcodes[0xa8] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xa9] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xaa] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xab] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xac] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xad] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xae] = static_cast<const std::shared_ptr<OpCode>>(cmp);
    opcodes[0xaf] = static_cast<const std::shared_ptr<OpCode>>(cmp);

    std::shared_ptr<OpCode> ret(new Return(ram, flags, registers));
    opcodes[0xc0] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xc8] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xc9] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xd0] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xd8] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xe0] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xe8] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xf0] = static_cast<const std::shared_ptr<OpCode>>(ret);
    opcodes[0xf8] = static_cast<const std::shared_ptr<OpCode>>(ret);

    std::shared_ptr<OpCode> pop(new POP(ram, flags, registers));
    opcodes[0xc1] = static_cast<const std::shared_ptr<OpCode>>(pop);
    opcodes[0xd1] = static_cast<const std::shared_ptr<OpCode>>(pop);
    opcodes[0xe1] = static_cast<const std::shared_ptr<OpCode>>(pop);
    opcodes[0xf1] = static_cast<const std::shared_ptr<OpCode>>(pop);

    std::shared_ptr<OpCode> jump(new Jump(ram, flags, registers));
    opcodes[0xc2] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xc3] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xca] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xd2] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xda] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xe2] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xea] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xf2] = static_cast<const std::shared_ptr<OpCode>>(jump);
    opcodes[0xfa] = static_cast<const std::shared_ptr<OpCode>>(jump);

    std::shared_ptr<OpCode> call(new CALL(ram, flags, registers));
    opcodes[0xc4] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xcc] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xcd] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xd4] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xdc] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xe4] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xec] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xf4] = static_cast<const std::shared_ptr<OpCode>>(call);
    opcodes[0xfc] = static_cast<const std::shared_ptr<OpCode>>(call);

    std::shared_ptr<OpCode> push(new PUSH(ram, flags, registers));
    opcodes[0xc5] = static_cast<const std::shared_ptr<OpCode>>(push);
    opcodes[0xd5] = static_cast<const std::shared_ptr<OpCode>>(push);
    opcodes[0xe5] = static_cast<const std::shared_ptr<OpCode>>(push);
    opcodes[0xf5] = static_cast<const std::shared_ptr<OpCode>>(push);

    std::shared_ptr<OpCode> rst(new RST(ram, flags, registers));
    opcodes[0xc7] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xcf] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xd7] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xdf] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xe7] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xef] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xf7] = static_cast<const std::shared_ptr<OpCode>>(rst);
    opcodes[0xff] = static_cast<const std::shared_ptr<OpCode>>(rst);

    opcodes[0xc6] = static_cast<const std::shared_ptr<OpCode>>(new ADI(ram, flags, registers));
    opcodes[0xce] = static_cast<const std::shared_ptr<OpCode>>(new ACI(ram, flags, registers));
    opcodes[0xd3] = static_cast<const std::shared_ptr<OpCode>>(new OUT(ram, flags, registers));
    opcodes[0xd6] = static_cast<const std::shared_ptr<OpCode>>(new SUI(ram, flags, registers));
    opcodes[0xdb] = static_cast<const std::shared_ptr<OpCode>>(new IN(ram, flags, registers));
    opcodes[0xde] = static_cast<const std::shared_ptr<OpCode>>(new SBI(ram, flags, registers));
    opcodes[0xe3] = static_cast<const std::shared_ptr<OpCode>>(new XTHL(ram, flags, registers));
    opcodes[0xe6] = static_cast<const std::shared_ptr<OpCode>>(new ANI(ram, flags, registers));
    opcodes[0xe9] = static_cast<const std::shared_ptr<OpCode>>(new PCHL(ram, flags, registers));
    opcodes[0xeb] = static_cast<const std::shared_ptr<OpCode>>(new XCHG(ram, flags, registers));
    opcodes[0xee] = static_cast<const std::shared_ptr<OpCode>>(new XRI(ram, flags, registers));
    opcodes[0xf3] = static_cast<const std::shared_ptr<OpCode>>(new DI(ram, flags, registers));
    opcodes[0xf6] = static_cast<const std::shared_ptr<OpCode>>(new ORI(ram, flags, registers));
    opcodes[0xf9] = static_cast<const std::shared_ptr<OpCode>>(new SPHL(ram, flags, registers));
    opcodes[0xfb] = static_cast<const std::shared_ptr<OpCode>>(new EI(ram, flags, registers));
    opcodes[0xfe] = static_cast<const std::shared_ptr<OpCode>>(new CPI(ram, flags, registers));
}

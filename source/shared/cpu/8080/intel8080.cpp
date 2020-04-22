#include <cstdio>
#include "common/config.h"
#include "common/utilities.h"
#include "cpu/8080/intel8080.h"
#include "cpu/8080/instruction_set/instruction_set.h"

Intel8080::Intel8080(): registers() {
    registers.a = 0;
    registers.shift = 0;
    registers.bc.d16 = 0;
    registers.de.d16 = 0;
    registers.hl.d16 = 0;
    registers.pc.d16 = 0;
    registers.sp.d16 = 0;
    registers.int_enable = 0;
    registers.memory = new uint8_t[65536];

    registers.psw.flags.z = 0;
    registers.psw.flags.s = 0;
    registers.psw.flags.p = 0;
    registers.psw.flags.cy = 0;
    registers.psw.flags.ac = 0;
    registers.psw.flags.pad = 0;
}

Intel8080::~Intel8080() {
    delete registers.memory;
}

void Intel8080::debug() {
    if(IsTraceOn()) {
        fprintf(TraceOut(), "0x%04x\t", registers.pc.d16);
        fprintf(TraceOut(), "pc[0]: 0x%02x\t", registers.memory[registers.pc.d16]);
        fprintf(TraceOut(), "pc[1]: 0x%02x\t", registers.memory[registers.pc.d16 + 1]);
        fprintf(TraceOut(), "pc[2]: 0x%02x\t", registers.memory[registers.pc.d16 + 2]);
        fprintf(TraceOut(), "a: 0x%02x\t", registers.a);
        fprintf(TraceOut(), "b: 0x%02x\t", registers.bc.d8.highByte);
        fprintf(TraceOut(), "c: 0x%02x\t", registers.bc.d8.lowByte);
        fprintf(TraceOut(), "d: 0x%02x\t", registers.de.d8.highByte);
        fprintf(TraceOut(), "e: 0x%02x\t", registers.de.d8.lowByte);
        fprintf(TraceOut(), "h: 0x%02x\t", registers.hl.d8.highByte);
        fprintf(TraceOut(), "l: 0x%02x\t", registers.hl.d8.lowByte);
        fprintf(TraceOut(), "sp: 0x%04x\t", registers.sp.d16);
        fprintf(TraceOut(), "sp[0]: 0x%02x\t", registers.memory[registers.sp.d16]);
        fprintf(TraceOut(), "sp[1]: 0x%02x\t", registers.memory[registers.sp.d16 + 1]);
        fprintf(TraceOut(), "z: 0x%02x\t", registers.psw.flags.z);
        fprintf(TraceOut(), "s: 0x%02x\t", registers.psw.flags.s);
        fprintf(TraceOut(), "p: 0x%02x\t", registers.psw.flags.p);
        fprintf(TraceOut(), "cy: 0x%02x\t", registers.psw.flags.cy);
        fprintf(TraceOut(), "ac: 0x%02x\t", registers.psw.flags.ac);
    }
}

void Intel8080::Emulate8080() {
    debug();
    (*instructionSet[registers.memory[registers.pc.d16]])(registers);
    if(IsTraceOn())
        fprintf(TraceOut(), "\n");
}

void Intel8080::Run(long bufferLength) {
    while (registers.pc.d16 < bufferLength) {
        Emulate8080();
        utilities::delay(0);
    }
}

Intel8080::instruction Intel8080::instructionSet[256] = {
    machine::NOP,	// 0X00
    load::LXI_B,	// 0X01
    store::STAX_B,	// 0X02
    increment::INX_B,	// 0X03
    increment::INR_B,	// 0X04
    decrement::DCR_B,	// 0X05
    move::MVI_B,	// 0X06
    rotate::RLC,	// 0X07
    machine::Unimplemented,	// 0X08
    addition::DAD_B,	// 0X09
    load::LDAX_B,	// 0X0A
    decrement::DCX_B,	// 0X0B
    increment::INR_C,	// 0X0C
    decrement::DCR_C,	// 0X0D
    move::MVI_C,	// 0X0E
    rotate::RRC,	// 0X0F

    machine::Unimplemented,	// 0X10
    load::LXI_D,	// 0X11
    store::STAX_D,	// 0X12
    increment::INX_D,	// 0X13
    increment::INR_D,	// 0X14
    decrement::DCR_D,	// 0X15
    move::MVI_D,	// 0X16
    rotate::RAL,	// 0X17
    machine::Unimplemented,	// 0X18
    addition::DAD_D,	// 0X19
    load::LDAX_D,	// 0X1A
    decrement::DCX_D,	// 0X1B
    increment::INR_E,	// 0X1C
    decrement::DCR_E,	// 0X1D
    move::MVI_E,	// 0X1E
    rotate::RAR,	// 0X1F

    machine::Unimplemented,	// 0X20
    load::LXI_H,	// 0X21
    store::SHLD,	// 0X22
    increment::INX_H,	// 0X23
    increment::INR_H,	// 0X24
    decrement::DCR_H,	// 0X25
    move::MVI_H,	// 0X26
    addition::DAA,	// 0X27
    machine::Unimplemented,	// 0X28
    addition::DAD_H,	// 0X29
    load::LHLD,	// 0X2A
    decrement::DCX_H,	// 0X2B
    increment::INR_L,	// 0X2C
    decrement::DCR_L,	// 0X2D
    move::MVI_L,	// 0X2E
    compliment::CMA,	// 0X2F

    machine::Unimplemented,	// 0X30
    load::LXI_SP,	// 0X31
    store::STA,	// 0X32
    increment::INX_SP,	// 0X33
    increment::INR_M,	// 0X34
    decrement::DCR_M,	// 0X35
    move::MVI_M,	// 0X36
    compliment::STC,	// 0X37
    machine::Unimplemented,	// 0X38
    addition::DAD_SP,	// 0X39
    load::LDA,	// 0X3A
    decrement::DCX_SP,	// 0X3B
    increment::INR_A,	// 0X3C
    decrement::DCR_A,	// 0X3D
    move::MVI_A,	// 0X3E
    compliment::CMC,	// 0X3F

    move::MOV_B_B,	// 0X40
    move::MOV_B_C,	// 0X41
    move::MOV_B_D,	// 0X42
    move::MOV_B_E,	// 0X43
    move::MOV_B_H,	// 0X44
    move::MOV_B_L,	// 0X45
    move::MOV_B_M,	// 0X46
    move::MOV_B_A,	// 0X47
    move::MOV_C_B,	// 0X48
    move::MOV_C_C,	// 0X49
    move::MOV_C_D,	// 0X4A
    move::MOV_C_E,	// 0X4B
    move::MOV_C_H,	// 0X4C
    move::MOV_C_L,	// 0X4D
    move::MOV_C_M,	// 0X4E
    move::MOV_C_A,	// 0X4F

    move::MOV_D_B,	// 0X50
    move::MOV_D_C,	// 0X51
    move::MOV_D_D,	// 0X52
    move::MOV_D_E,	// 0X53
    move::MOV_D_H,	// 0X54
    move::MOV_D_L,	// 0X55
    move::MOV_D_M,	// 0X56
    move::MOV_D_A,	// 0X57
    move::MOV_E_B,	// 0X58
    move::MOV_E_C,	// 0X59
    move::MOV_E_D,	// 0X5A
    move::MOV_E_E,	// 0X5B
    move::MOV_E_H,	// 0X5C
    move::MOV_E_L,	// 0X5D
    move::MOV_E_M,	// 0X5E
    move::MOV_E_A,	// 0X5F

    move::MOV_H_B,	// 0X60
    move::MOV_H_C,	// 0X61
    move::MOV_H_D,	// 0X62
    move::MOV_H_E,	// 0X63
    move::MOV_H_H,	// 0X64
    move::MOV_H_L,	// 0X65
    move::MOV_H_M,	// 0X66
    move::MOV_H_A,	// 0X67
    move::MOV_L_B,	// 0X68
    move::MOV_L_C,	// 0X69
    move::MOV_L_D,	// 0X6A
    move::MOV_L_E,	// 0X6B
    move::MOV_L_H,	// 0X6C
    move::MOV_L_L,	// 0X6D
    move::MOV_L_M,	// 0X6E
    move::MOV_L_A,	// 0X6F

    move::MOV_M_B,	// 0X70
    move::MOV_M_C,	// 0X71
    move::MOV_M_D,	// 0X72
    move::MOV_M_E,	// 0X73
    move::MOV_M_H,	// 0X74
    move::MOV_M_L,	// 0X75
    machine::HLT,	// 0X76
    move::MOV_M_A,	// 0X77
    move::MOV_A_B,	// 0X78
    move::MOV_A_C,	// 0X79
    move::MOV_A_D,	// 0X7A
    move::MOV_A_E,	// 0X7B
    move::MOV_A_H,	// 0X7C
    move::MOV_A_L,	// 0X7D
    move::MOV_A_M,	// 0X7E
    move::MOV_A_A,	// 0X7F

    addition::ADD_B,	// 0X80
    addition::ADD_C,	// 0X81
    addition::ADD_D, 	// 0X82
    addition::ADD_E, 	// 0X83
    addition::ADD_H,	// 0X84
    addition::ADD_L,	// 0X85
    addition::ADD_M,	// 0X86
    addition::ADD_A,	// 0X87
    addition::ADC_B,	// 0X88
    addition::ADC_C,	// 0X89
    addition::ADC_D,	// 0X8A
    addition::ADC_E,	// 0X8B
    addition::ADC_H,	// 0X8C
    addition::ADC_L,	// 0X8D
    addition::ADC_M,	// 0X8E
    addition::ADC_A,	// 0X8F

    subtraction::SUB_B,	// 0X90
    subtraction::SUB_C,	// 0X90
    subtraction::SUB_D,	// 0X92
    subtraction::SUB_E,	// 0X93
    subtraction::SUB_H,	// 0X94
    subtraction::SUB_L,	// 0X95
    subtraction::SUB_M,	// 0X96
    subtraction::SUB_A,	// 0X97
    subtraction::SBB_B,	// 0X98
    subtraction::SBB_C,	// 0X99
    subtraction::SBB_D,	// 0X9A
    subtraction::SBB_E,	// 0X9B
    subtraction::SBB_H,	// 0X9C
    subtraction::SBB_L,	// 0X9D
    subtraction::SBB_M,	// 0X9E
    subtraction::SBB_A,	// 0X9F

    logical_and::ANA_B,	// 0xA0
    logical_and::ANA_C,	// 0xA1
    logical_and::ANA_D,	// 0xA2
    logical_and::ANA_E,	// 0xA3
    logical_and::ANA_H,	// 0xA4
    logical_and::ANA_L,	// 0xA5
    logical_and::ANA_M,	// 0xA6
    logical_and::ANA_A,	// 0xA7
    logical_xor::XRA_B,	// 0xA8
    logical_xor::XRA_C,	// 0xA9
    logical_xor::XRA_D,	// 0xAA
    logical_xor::XRA_E,	// 0xAB
    logical_xor::XRA_H,	// 0xAC
    logical_xor::XRA_L,	// 0xAD
    logical_xor::XRA_M,	// 0xAE
    logical_xor::XRA_A, // 0xAF

    logical_or::ORA_B,	// 0xB0
    logical_or::ORA_C,	// 0xB1
    logical_or::ORA_D,	// 0xB2
    logical_or::ORA_E,	// 0xB3
    logical_or::ORA_H,	// 0xB4
    logical_or::ORA_L,	// 0xB5
    logical_or::ORA_M,	// 0xB6
    logical_or::ORA_A,	// 0xB7
    compare::CMP_B,	// 0xB8
    compare::CMP_C,	// 0xB9
    compare::CMP_D,	// 0xBA
    compare::CMP_E,	// 0xBB
    compare::CMP_H,	// 0xBC
    compare::CMP_L,	// 0xBD
    compare::CMP_M,	// 0xBE
    compare::CMP_A,	// 0xBF

    call::RNZ,	// 0XC0
    stack::POP_B,	// 0XC1
    jump::JNZ,	// 0XC2
    jump::JMP,	// 0XC3
    call::CNZ,	// 0XC4
    stack::PUSH_B,	// 0XC5
    addition::ADI,	// 0XC6
    restart::RST_0,	// 0XC7
    call::RZ,	// 0XC8
    call::RET,	// 0XC9
    jump::JZ,	// 0XCA
    machine::Unimplemented,	// 0XCB
    call::CZ,	// 0XCC
    call::CALL,	// 0XCD
    addition::ACI,	// 0XCE
    restart::RST_1,	// 0XCF

    call::RNC,	// 0XD0
    stack::POP_D,	// 0XD1
    jump::JNC,	// 0XD2
    io::OUT,	// 0XD3
    call::CNC,	// 0XD4
    stack::PUSH_D,	// 0XD5
    subtraction::SUI,	// 0XD6
    restart::RST_2,	// 0XD7
    call::RC,	// 0XD8
    machine::Unimplemented,	// 0XD9
    jump::JC,	// 0XDA
    io::IN,	// 0XDB
    call::CC,	// 0XDC
    machine::Unimplemented,	// 0XDD
    subtraction::SBI,	// 0XDE
    restart::RST_3,	// 0xDF

    call::RPO,	// 0xE0
    stack::POP_H,	// 0xE1
    jump::JPO,	// 0xE2
    stack::XTHL,	// 0xE3
    call::CPO,	// 0xE4
    stack::PUSH_H,	// 0xE5
    logical_and::ANI,	// 0xE6
    restart::RST_4,	// 0xE7
    call::RPE,	// 0xE8
    jump::PCHL,	// 0xE9
    jump::JPE,	// 0xEA
    store::XCHG,	// 0xEB
    call::CPE,	// 0xEC
    machine::Unimplemented,	// 0xED
    logical_xor::XRI,	// 0xEE
    restart::RST_5,	// 0xEF

    call::RP,	// 0xF0
    stack::POP_PSW,	// 0xF1
    jump::JP,	// 0xF2
    machine::DI,	// 0xF3
    call::CP,	// 0xF4
    stack::PUSH_PSW,	// 0xF5
    logical_or::ORI,	// 0xF6
    restart::RST_6,	// 0xF7
    call::RM,	// 0xF8
    stack::SPHL,	// 0xF9
    jump::JM,	// 0xFA
    machine::EI,	// 0xFB
    call::CM,	// 0xFC
    machine::Unimplemented,	// 0xFD
    compare::CPI,	// 0xFE
    restart::RST_7    // 0xFF
};

#include "cpu/8080/instructions/branch_group.h"

uint16_t jump(uint8_t highByte, uint8_t lowByte, uint16_t* pc) {
    uint16_t address = (highByte << 8) | lowByte;
    *pc = address;
    return address;
}

void JMP(State8080 *state) {
    uint16_t address =
        jump(state->memory[state->pc + 2], state->memory[state->pc + 1], &state->pc);

    if(IsTraceOn())
        fprintf(TraceOut(), "JMP %04x\n", address);
}

void CALL(State8080 *state) {
    uint8_t lowByte = (state->pc + 3) & 0xff;
    uint8_t highByte = ((state->pc + 3) & 0xff00 ) >> 8;

    state->memory[state->sp - 1] = highByte;
    state->memory[state->sp - 2] = lowByte;
    state->sp -= 2;

    uint16_t address =
        jump(state->memory[state->pc + 2], state->memory[state->pc + 1], &state->pc);

    if(IsTraceOn())
        fprintf(TraceOut(), "CALL %04x\n", address);
}

void RET(State8080* state) {
    state->pc = (state->memory[state->sp + 1] << 8) | state->memory[state->sp];
    state->sp += 2;

    if(IsTraceOn())
        fprintf(TraceOut(), "RET %04x\n", state->pc);
}

void JNZ(State8080 *state) {
    if(state->b != 0) {
        uint16_t address =
            jump(state->memory[state->pc + 2], state->memory[state->pc + 1], &state->pc);

        if(IsTraceOn())
            fprintf(TraceOut(), "JNZ %04x\n", address);
    } else {
        if(IsTraceOn())
            fprintf(TraceOut(), "JNZ\n");

        state->pc += 3;
    }
}

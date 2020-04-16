#include <cpu/8080/state.h>
#include "cpu/8080/instructions/stack_io_group.h"

void NOP(State8080 *state) {
    if(IsTraceOn())
        fprintf(TraceOut(), "NOP\n");
    state->pc += 1;
}

// POP rp (rl) <-- ((SP)) (rh) <-- ((SP) + 1) (SP) <-- (SP) + 2
void popRp(uint8_t* rh, uint8_t* rl, State8080* state) {
    *rl = state->memory[state->sp];
    *rh = state->memory[state->sp + 1];
    state->sp += 2;
    state->pc += 1;
}

// POP B (c) <-- ((SP)) (b) <-- ((SP) + 1) (SP) <-- (SP) + 2
void POP_B(State8080* state) {
    popRp(&state->b, &state->c, state);
    if(IsTraceOn())
        fprintf(TraceOut(), "POP BC %02x%02x\n", state->b, state->c);
}

// POP D (e) <-- ((SP)) (d) <-- ((SP) + 1) (SP) <-- (SP) + 2
void POP_D(State8080* state) {
    popRp(&state->d, &state->e, state);
    if(IsTraceOn())
        fprintf(TraceOut(), "POP DE %02x%02x\n", state->d, state->e);
}

// POP H (l) <-- ((SP)) (h) <-- ((SP) + 1) (SP) <-- (SP) + 2
void POP_H(State8080* state) {
    state->l = state->memory[state->sp];
    state->h = state->memory[state->sp + 1];
    state->sp += 2;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "POP HL %02x%02x\n", state->h, state->l);
}

void PUSH_B(State8080* state) {
    state->memory[state->sp - 2] = state->c;
    state->memory[state->sp - 1] = state->b;
    state->sp -= 2;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(),
            "PUSH BC %02x%02x\n", state->memory[state->sp - 1], state->memory[state->sp]);
}

// PUSH DE
//   ((SP) - 1) <- D
//   ((SP) - 2) <- E
//   (SP) <- (SP) - 2
void PUSH_D(State8080* state) {
    state->memory[state->sp - 1] = state->d;
    state->memory[state->sp - 2] = state->e;
    state->sp = state->sp - 2;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "PUSH DE %02x%02x\n", state->memory[state->sp], state->memory[state->sp + 1]);
}

void PUSH_H(State8080* state) {
    state->memory[state->sp - 1] = state->h;
    state->memory[state->sp - 2] = state->l;
    state->sp = state->sp - 2;
    state->pc += 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "PUSH DE %02x%02x\n", state->memory[state->sp], state->memory[state->sp + 1]);
}

void UnimplementedInstruction(State8080 *state) {
    if(IsTraceOn())
        fprintf(TraceOut(), "unimplemented instruction 0x%02x\n", state->memory[state->pc]);
    exit(1);
//    switch(state->memory[state->pc]){
//        case 0x10:
//        case 0x18:
//        case 0x20:
//        case 0x28:
//        case 0x30:
//        case 0x38:
//        case 0xcb:
//        case 0xd9:
//        case 0xdd:
//        case 0xed:
//        case 0xfd:
//            exit(1);
//            break;
//        default:
//            state->pc += 1;
//            break;
//    }
}

// OUT port (data) <- (A)
void Out(State8080* state) {
    if(IsTraceOn())
        fprintf(TraceOut(), "OUT %02x %02x\n", state->a, state->memory[state->pc + 1]);
    state->pc += 2;
}

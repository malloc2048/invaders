#include <cpu/8080/state.h>
#include "cpu/8080/instructions/stack_io_group.h"

void NoOp(State8080 *state) {
    if(TraceOn())
        fprintf(TraceOut(), "NOP\n");
    state->pc += 1;
}

// POP H (l) <-- ((SP)) (h) <-- ((SP) + 1) (SP) <-- (SP) + 2
void PopH(State8080* state) {
    state->l = state->memory[state->sp];
    state->h = state->memory[state->sp + 1];
    state->sp += 2;
    state->pc += 1;

    if(TraceOn())
        fprintf(TraceOut(), "POP HL %02x%02x\n", state->h, state->l);
}

void PushBC(State8080* state) {
    state->memory[state->sp - 2] = state->c;
    state->memory[state->sp - 1] = state->b;
    state->sp -= 2;
    state->pc += 1;

    if(TraceOn())
        fprintf(TraceOut(),
            "PUSH BC %02x%02x\n", state->memory[state->sp - 1], state->memory[state->sp]);
}

// PUSH DE
//   ((SP) - 1) <- D
//   ((SP) - 2) <- E
//   (SP) <- (SP) - 2
void PushDE(State8080* state) {
    state->memory[state->sp - 1] = state->d;
    state->memory[state->sp - 2] = state->e;
    state->sp = state->sp - 2;
    state->pc += 1;

    if(TraceOn())
        fprintf(TraceOut(), "PUSH DE %02x%02x\n", state->memory[state->sp], state->memory[state->sp + 1]);
}

void PushHL(State8080* state) {
    state->memory[state->sp - 1] = state->h;
    state->memory[state->sp - 2] = state->l;
    state->sp = state->sp - 2;
    state->pc += 1;

    if(TraceOn())
        fprintf(TraceOut(), "PUSH DE %02x%02x\n", state->memory[state->sp], state->memory[state->sp + 1]);
}

void UnimplementedInstruction(State8080 *state) {
    if(TraceOn())
        fprintf(TraceOut(), "unimplemented instruction 0x%02x\n", state->memory[state->pc]);

    switch(state->memory[state->pc]){
        case 0x10:
        case 0x18:
        case 0x20:
        case 0x28:
        case 0x30:
        case 0x38:
        case 0xcb:
        case 0xd9:
        case 0xdd:
        case 0xed:
        case 0xfd:
            exit(1);
            break;
        default:
            state->pc += 1;
            break;
    }
}

// OUT port (data) <- (A)
void Out(State8080* state) {
    fprintf(TraceOut(), "OUT %02x %02x\n", state->a, state->memory[state->pc + 1]);
    state->pc += 2;
}

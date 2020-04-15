#include <cpu/8080/state.h>
#include "cpu/8080/instructions/stack_io_group.h"

void NoOp(State8080 *state) {
    if(TraceOn())
        fprintf(TraceOut(), "NOP\n");
    state->pc += 1;
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
    exit(1);
}

#include "cpu/8080/state.h"
#include "common/utilities.h"
#include "cpu/8080/instructions/arithmetic_group.h"

void DCR_B(State8080* state) {
    state->b -= 1;
    state->pc += 1;

    state->cc.z = state->b == 0 ? 1 : 0;
    state->cc.s = state->b >= 0x80 ? 1 : 0;
    state->cc.p = Parity(state->b, 8);
    state->cc.ac = (state->b & 0x0fu) == 0x0fu ? 1 : 0;

    if(IsTraceOn())
        fprintf(TraceOut(), "DCR B %02x\n", state->b);
}

void DCR_C(State8080* state) {
    state->c -= 1;
    state->pc += 1;

    state->cc.z = state->c == 0 ? 1 : 0;
    state->cc.s = state->c >= 0x80 ? 1 : 0;
    state->cc.p = Parity(state->c, 8);
    state->cc.ac = (state->c & 0x0fu) == 0x0fu ? 1 : 0;

    if(IsTraceOn())
        fprintf(TraceOut(), "DCR C %02x\n", state->c);
}

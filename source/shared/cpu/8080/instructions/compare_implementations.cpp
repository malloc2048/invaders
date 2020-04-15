#include "common/config.h"
#include "logical_group.h"

void CompareImmediate(State8080* state) {
    uint8_t answer = state->a - state->memory[state->pc + 1];

    if(answer == 0)
        state->cc.z = 1;

    if(TraceOn())
        fprintf(TraceOut(), "CPI %02x\n", state->a);
    state->pc += 2;
}

#include "common/config.h"
#include "cpu/8080/instructions/logical_group.h"

void CPI(State8080* state) {
    uint8_t answer = state->a - state->memory[state->pc + 1];

    if(answer == 0)
        state->cc.z = 1;

    if(IsTraceOn())
        fprintf(TraceOut(), "CPI %02x\n", state->a);
    state->pc += 2;
}

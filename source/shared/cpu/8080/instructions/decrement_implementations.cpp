#include "arithmetic_group.h"

void DecrementRegisterB(State8080* state) {
    state->b -= 1;

    if(TraceOn())
        fprintf(TraceOut(), "DCR B %02x\n", state->b);
    state->pc += 1;
}

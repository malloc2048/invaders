#include <cstdlib>
#include "common/config.h"

int traceOn = 1;

void TraceOn() {
    traceOn = 1;
}

void TraceOff() {
    traceOn = 0;
}

int IsTraceOn() {
    return traceOn;
}

FILE* traceFile = stdout;
FILE* TraceOut() {
    if(traceFile == nullptr) {
        traceFile = fopen("./config/traceout.dis", "w");

        if(traceFile == nullptr) {
            printf("failed to open file: %d", errno);
            return stdout;
        }
    }
    return traceFile;
}

#include <cstdlib>
#include "config.h"

int Emulate() {
    return 0;
}

int TraceOn() {
    return 1;
}

FILE* traceFile = nullptr;
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

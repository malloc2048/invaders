#include <cstdlib>
#include "common/config.h"

int traceOn = 1;
int dumpHex = 1;

void TraceOn() {
    traceOn = 1;
}

void TraceOff() {
    traceOn = 0;
}

namespace config {
    int IsHexDump() {
        return dumpHex;
    }
}

int IsTraceOn() {
    return traceOn;
}

FILE* traceFile = nullptr;
//FILE* traceFile = stdout;
FILE* TraceOut() {
    if(traceFile == nullptr) {
        traceFile = fopen("../../../config/trace.dis", "w");

        if(traceFile == nullptr) {
            printf("failed to open file: %s", "./config/trace.dis");
            return stdout;
        }
    }
    return traceFile;
}

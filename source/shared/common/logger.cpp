#include <cstdio>
#include "logger.h"

const char* LOG_LEVEL_STRINGS[4] = {
    "ERROR",
    "WARNING",
    "INFO",
    "DEBUG"
};

void Log(LogLevel level, const char *message, const char *file, const char *function, int lineNumber) {
    fprintf(stdout,"%s: %s::%s:%d %s", LOG_LEVEL_STRINGS[level], file, function, lineNumber, message);
}

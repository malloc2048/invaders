#include "config.h"
#include "logger.h"

const char Logger::logLevelNames[4][16] = {
    "INFO",
    "DEBUG",
    "ERROR",
    "WARNING"
};

void Logger::Log(Logger::LogLevel level, const char *msg, const char *filename, const char *functionName, int lineNumber) {
    if(IsTraceOn())
        fprintf(TraceOut(),
            "%s:\t%s::%s:%d\t%s\n", logLevelNames[level], filename, functionName, lineNumber, msg);
}

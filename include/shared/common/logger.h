#ifndef EMULATOR_LOGGER_H
#define EMULATOR_LOGGER_H

#include "config.h"

enum LogLevel {
    ERROR = 0,
    WARNING = 1,
    INFO = 2,
    DEBUG = 3,
};

#define LogError(message) Log(ERROR, message, __FILE__, __FUNCTION__, __LINE__)

#if LOGGING_LEVEL == 3
#define LogDebug(message) Log(DEBUG, message, __FILE__, __FUNCTION__, __LINE__)
#else
#define LogDebug(message) 0
#endif

#if LOGGING_LEVEL == 2
#define LogInfo(message) Log(INFO, message, __FILE__, __FUNCTION__, __LINE__)
#else
#define LogInfo(message) 0
#endif

#if LOGGING_LEVEL == 1
#define LogWarning(message) Log(WARNING, message, __FILE__, __FUNCTION__, __LINE__)
#else
#define LogWarning(message) 0
#endif

void Log(LogLevel level, const char* message, const char* file, const char* function, int lineNumber);
#endif

#ifndef EMULATOR_LOGGER_H
#define EMULATOR_LOGGER_H

#define LogInfo(msg) Logger::Log(Logger::INFO, msg, __FILE__, __FUNCTION__, __LINE__)
#define LogDebug(msg) Logger::Log(Logger::DEBUG, msg, __FILE__, __FUNCTION__, __LINE__)
#define LogError(msg) Logger::Log(Logger::ERROR, msg, __FILE__, __FUNCTION__, __LINE__)
#define LogWarning(msg) Logger::Log(Logger::WARNING, msg, __FILE__, __FUNCTION__, __LINE__)

class Logger {
public:
    enum LogLevel {
        INFO,
        DEBUG,
        ERROR,
        WARNING
    };

    Logger() = default;
    ~Logger() = default;

    static void Log(LogLevel level, const char* msg, const char* filename, const char* functionName, int lineNumber);

private:
    static const char logLevelNames[4][16];
};
#endif

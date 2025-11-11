#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

namespace GEL {

    enum class LogLevel {
        Info,
        Warning,
        Error
    };

    inline std::string currentTime() {
        using namespace std::chrono;
        auto now = system_clock::now();
        std::time_t t = system_clock::to_time_t(now);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%H:%M:%S", std::localtime(&t));
        return std::string(buf);
    }

    inline const char* color(LogLevel level) {
        switch(level) {
            case LogLevel::Info:    return "\033[32m"; // verde
            case LogLevel::Warning: return "\033[33m"; // amarillo
            case LogLevel::Error:   return "\033[31m"; // rojo
        }
        return "\033[0m";
    }

    inline void Log(const std::string& msg, LogLevel level = LogLevel::Info) {
        std::ostream& out = (level == LogLevel::Error) ? std::cerr : std::cout;
        out << color(level)
            << "[" << currentTime() << "] "
            << (level == LogLevel::Info ? "INFO" :
                level == LogLevel::Warning ? "WARN" : "ERROR")
            << ": " << msg
            << "\033[0m" << std::endl;
    }

} // namespace GEL

// ---------------------------------
// Macros para simplificar el uso
// ---------------------------------
#define LOG_INFO(msg)    GEL::Log(msg, GEL::LogLevel::Info)
#define LOG_WARN(msg)    GEL::Log(msg, GEL::LogLevel::Warning)
#define LOG_ERROR(msg)   GEL::Log(msg, GEL::LogLevel::Error)

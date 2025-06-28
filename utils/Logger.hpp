#pragma once

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <mutex>

class Logger {
public:
    // Log levels
    enum class LogLevel {
        INFO,
        WARNING,
        ERROR
    };

    // Constructor: opens log file in append mode
    explicit Logger(const std::string& filename)
        : logFile(filename, std::ios::app)
    {
        if (!logFile.is_open()) {
            std::cerr << "Failed to open log file: " << filename << std::endl;
        }
    }

    // Log a message with a specific log level
    void log(const std::string& message, LogLevel level = LogLevel::INFO) {
        std::lock_guard<std::mutex> lock(mutex);
        if (logFile.is_open()) {
            logFile << currentTimestamp() << " [" << levelToString(level) << "] " << message << std::endl;
        }
    }

private:
    std::ofstream logFile;
    mutable std::mutex mutex;

    // Generate current timestamp string
    std::string currentTimestamp() const {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm tm{};
#ifdef _MSC_VER
        localtime_s(&tm, &t); // Windows
#else
        localtime_r(&t, &tm); // POSIX
#endif
        std::ostringstream oss;
        oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    // Convert enum to string
    std::string levelToString(LogLevel level) const {
        switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
        }
    }
};

#endif // LOGGER_HPP

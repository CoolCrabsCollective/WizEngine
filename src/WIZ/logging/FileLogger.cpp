//
// Created by Alexander Winter on 2022-02-10.
//

#include <WIZ/logging/FileLogger.h>

wiz::FileLogger::FileLogger(const std::string& filePath, LogLevel logLevel) : LoggerBase(logLevel) {
    filePointer.open(filePath, std::ios::out | std::ios::app);
}

wiz::FileLogger::~FileLogger() {
    filePointer.close();
}

void wiz::FileLogger::debug(const std::string& message) const {
    if(logLevel <= DEBUG)
        filePointer << message << std::endl;
}

void wiz::FileLogger::info(const std::string& message) const {
    if(logLevel <= INFO)
        filePointer  << message << std::endl;
}

void wiz::FileLogger::warning(const std::string& message) const {
    if(logLevel <= WARNING)
        filePointer << message << std::endl;
}

void wiz::FileLogger::error(const std::string& message) const {
    if(logLevel <= ERROR)
        filePointer  << message << std::endl;
}


//
// Created by Alexander Winter on 2022-02-10.
//

#include "WIZ/logging/StdOutLogger.h"

#include <iostream>

wiz::StdOutLogger::StdOutLogger(LogLevel logLevel) : LoggerBase(logLevel) {}

void wiz::StdOutLogger::debug(const std::string& message) const {
    if(logLevel <= DEBUG)
        std::cout << message << std::endl;
}

void wiz::StdOutLogger::info(const std::string& message) const {
    if(logLevel <= INFO)
        std::cout << message << std::endl;
}

void wiz::StdOutLogger::warning(const std::string& message) const {
    if(logLevel <= WARNING)
        std::cout << message << std::endl;
}

void wiz::StdOutLogger::error(const std::string& message) const {
    if(logLevel <= ERROR) {
        if(useStderr)
            std::cerr << message << std::endl;
        else
            std::cout << message << std::endl;
    }
}

bool wiz::StdOutLogger::useStderrOnError() const {
    return useStderr;
}

void wiz::StdOutLogger::setUseStderrOnError(bool useStderrOnError) {
    this->useStderr = useStderrOnError;
}


//
// Created by Alexander Winter on 2022-02-10.
//

#include <WIZ/logging/LoggerBase.h>

wiz::LoggerBase::LoggerBase(LogLevel logLevel) : logLevel(logLevel) {

}

wiz::LogLevel wiz::LoggerBase::getLogLevel() const {
    return logLevel;
}

void wiz::LoggerBase::setLogLevel(LogLevel level) {
    this->logLevel = level;
}


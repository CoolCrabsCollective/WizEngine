//
// Created by Alexander Winter on 2022-02-10.
//

#include "WIZ/logging/TagLoggerWrapper.h"

#include <utility>
#include <iomanip>

wiz::TagLoggerWrapper::TagLoggerWrapper(Logger* logger)
        : logger(std::shared_ptr<Logger>(logger)) {}

wiz::TagLoggerWrapper::TagLoggerWrapper(std::shared_ptr<Logger> logger)
    : logger(std::move(logger)) {}

void wiz::TagLoggerWrapper::debug(const std::string& message) const {
    logger->debug("[DEBUG] " + message);
}

void wiz::TagLoggerWrapper::info(const std::string& message) const {
    logger->info("[INFO] " + message);
}

void wiz::TagLoggerWrapper::warning(const std::string& message) const {
    logger->warning("[WARNING] " + message);
}

void wiz::TagLoggerWrapper::error(const std::string& message) const {
    logger->error("[ERROR] " + message);
}

wiz::LogLevel wiz::TagLoggerWrapper::getLogLevel() const {
    return logger->getLogLevel();
}

void wiz::TagLoggerWrapper::setLogLevel(LogLevel level) {
    logger->setLogLevel(level);
}


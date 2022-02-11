//
// Created by Alexander Winter on 2022-02-10.
//

#include <WIZ/logging/MultiLogger.h>

#include <utility>
#include <WIZ/logging/Logger.h>

wiz::MultiLogger::MultiLogger(const std::vector<Logger*>& loggers)
    : loggers() {
    for(Logger* logger : loggers)
        this->loggers.push_back(std::shared_ptr<Logger>(logger));
}

wiz::MultiLogger::MultiLogger(std::vector<std::shared_ptr<Logger>> loggers)
    : loggers(std::move(loggers)) {}

void wiz::MultiLogger::debug(const std::string& message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->debug(message);
}

void wiz::MultiLogger::info(const std::string &message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->info(message);
}

void wiz::MultiLogger::warning(const std::string &message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->warning(message);
}

void wiz::MultiLogger::error(const std::string &message) const {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->error(message);
}

wiz::LogLevel wiz::MultiLogger::getLogLevel() const {

    if(loggers.empty())
        return LogLevel::NONE;

    return loggers[0]->getLogLevel();
}

void wiz::MultiLogger::setLogLevel(LogLevel level) {
    for(const std::shared_ptr<Logger>& logger : this->loggers)
        logger->setLogLevel(level);
}


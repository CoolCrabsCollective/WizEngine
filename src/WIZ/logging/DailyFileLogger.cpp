//
// Created by Alexander Winter on 2022-02-10.
//

#include <ctime>
#include <iomanip>
#include <sstream>
#include <WIZ/util/FileUtil.h>
#include <WIZ/util/StringUtil.h>
#include <WIZ/logging/DailyFileLogger.h>


wiz::DailyFileLogger::DailyFileLogger(std::string directory, LogLevel level)
: LoggerBase(level), directory(std::move(directory) + (ends_with(directory, "/") ? "" : "/")) {

}

wiz::DailyFileLogger::~DailyFileLogger() {
    file.close();
}

void wiz::DailyFileLogger::debug(const std::string& message) const {
    if(logLevel <= DEBUG)
        getCurrentFile() << message << std::endl;
}

void wiz::DailyFileLogger::info(const std::string& message) const {
    if(logLevel <= INFO)
        getCurrentFile() << message << std::endl;
}

void wiz::DailyFileLogger::warning(const std::string& message) const {
    if(logLevel <= WARNING)
        getCurrentFile() << message << std::endl;
}

void wiz::DailyFileLogger::error(const std::string& message) const {
    if(logLevel <= ERROR)
        getCurrentFile() << message << std::endl;
}

std::ofstream& wiz::DailyFileLogger::getCurrentFile() const {
    std::string presentFile = getCurrentFileName();
    if(presentFile != curFile)
    {
        file.close();
        curFile = presentFile;

        if(ensureDirectory(directory) != 0)
            throw std::runtime_error("Failed to create directory " + directory + " for logging");

        std::string fileName = directory + curFile;
        file.open(fileName, std::ios::out | std::ios::app);

        if(file.fail())
            throw std::runtime_error("Failed to open file " + fileName + " for logging");
    }

    return file;
}

std::string wiz::DailyFileLogger::getCurrentFileName() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d") << ".log";
    return oss.str();
}



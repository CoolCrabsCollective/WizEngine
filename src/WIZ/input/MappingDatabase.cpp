//
// Created by Alexander Winter on 2022-03-27.
//

#include <fstream>
#include <sstream>
#include "WIZ/input/MappingDatabase.h"
#include "WIZ/util/string_util.h"

wiz::MappingDatabase wiz::MappingDatabase::instance;

const wiz::Mapping& wiz::MappingDatabase::getMapping(const std::string& controllerName) const {
	return map.at(controllerName);
}

void wiz::MappingDatabase::loadFromCSV(const std::string& csvDbContent) {
#ifndef OS_SWITCH
	std::stringstream ss(csvDbContent);
	std::string line;

	while(std::getline(ss, line, '\n')) {
		if(line[0] == '#')
			continue;

		wiz::trim(line);

		if(line.length() == 0)
			continue;

#ifdef OS_WINDOWS
		if(!line.ends_with("platform:Windows,"))
			continue;
#endif

#ifdef OS_MAC
		if(!line.ends_with("platform:Mac OS X,"))
			continue;
#endif

#ifdef OS_UNIX
		if(!line.ends_with("platform:Linux,"))
			continue;
#endif

		std::vector<std::string> bindings = wiz::split(line, ',');

		wiz::Mapping mapping;
		for(int i = 2; i < bindings.size(); i++)
		{
			if(parts[1].substr(1).starts_with("+"))
				continue;
			
			std::vector<std::string> parts = wiz::split(bindings[i], ':');
			if(parts[0] == "a")
				mapping.set(wiz::MapButton::A, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "b")
				mapping.set(wiz::MapButton::B, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "x")
				mapping.set(wiz::MapButton::X, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "y")
				mapping.set(wiz::MapButton::Y, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "back")
				mapping.set(wiz::MapButton::Back, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "start")
				mapping.set(wiz::MapButton::Start, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "leftshoulder")
				mapping.set(wiz::MapButton::Left_Shoulder, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "rightshoulder")
				mapping.set(wiz::MapButton::Right_Shoulder, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "lefttrigger")
				mapping.set(wiz::MapButton::Left_Trigger, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "righttrigger")
				mapping.set(wiz::MapButton::Right_Trigger, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "leftstick")
				mapping.set(wiz::MapButton::Left_Stick, std::stoi(parts[1].substr(1)));
			else if(parts[0] == "rightstick")
				mapping.set(wiz::MapButton::Right_Stick, std::stoi(parts[1].substr(1)));
		}

		addMapping(bindings[1], mapping);
	}
#endif
}

const wiz::MappingDatabase& wiz::MappingDatabase::getInstance() {
	return wiz::MappingDatabase::instance;
}

void wiz::MappingDatabase::addMapping(const std::string& controllerName, wiz::Mapping mapping) {
	map[controllerName] = mapping;
}

void wiz::MappingDatabase::clearMappings() {
	map.clear();
}

bool wiz::MappingDatabase::hasMapping(const std::string& controllerName) const {
	return map.find(controllerName) != map.end();
}

void wiz::MappingDatabase::loadFromCSVFile(const std::string& csvDbFile) {
	std::ifstream stream(csvDbFile);
	std::stringstream buffer;
	buffer << stream.rdbuf();
	loadFromCSV(buffer.str());
}

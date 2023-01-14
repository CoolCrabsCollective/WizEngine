//
// Created by Alexander Winter on 2022-03-27.
//

#include <fstream>
#include <sstream>
#include "WIZ/input/MappingDatabase.h"
#include "WIZ/util/StringUtil.h"
#include "WIZ/util/MathUtil.h"
#include <stdexcept>

wiz::MappingDatabase wiz::MappingDatabase::instance;

const wiz::Mapping& wiz::MappingDatabase::getMapping(uint16_t vendorId, uint16_t productId) const {
	return map.at(std::make_pair(vendorId, productId));
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
			std::vector<std::string> parts = wiz::split(bindings[i], ':');

			try
			{
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
                else if(parts[0] == "leftx")
                    mapping.set(wiz::MapAxis::Left_X, std::stoi(parts[1].substr(1)));
                else if(parts[0] == "lefty")
                    mapping.set(wiz::MapAxis::Left_Y, std::stoi(parts[1].substr(1)));
                else if(parts[0] == "rightx")
                    mapping.set(wiz::MapAxis::Left_X, std::stoi(parts[1].substr(1)));
                else if(parts[0] == "righty")
                    mapping.set(wiz::MapAxis::Left_Y, std::stoi(parts[1].substr(1)));
			}
			catch(const std::invalid_argument& ex)
			{

			}
		}

		/*
		 * This hacky solution of fetching the product from GUID in the dataset was found from our own testing, and then
		 * we found that it matched this solution here:
		 * https://github.com/GuidoBisocoli/SFML_GamepadSupport/blob/main/Gamepad.cpp
		 *
		 * We don't know for certain how many controllers it actually works with, but it seems to work with all the
		 * common ones we have tested.
		 */

		std::string guid = bindings[0];
		if (guid.length() > 19) { // there can be some fields in bindings[0] that are not GUIDs
			std::string vendorId = guid.substr(10, 2) + guid.substr(8, 2);
			std::string productId = guid.substr(18,2) + guid.substr(16, 2);

            std::string reorderVendorId = vendorId.substr(2, 2) + vendorId.substr(0, 2);
            std::string reorderProductId = productId.substr(2, 2) + productId.substr(0, 2);

			addMapping(std::stoi(reorderVendorId), std::stoi(reorderProductId), mapping);
		}
	}
#endif
}

const wiz::MappingDatabase& wiz::MappingDatabase::getInstance() {
	return wiz::MappingDatabase::instance;
}

void wiz::MappingDatabase::addMapping(uint16_t vendorId, uint16_t productId, wiz::Mapping mapping) {
	map[std::make_pair(vendorId, productId)] = mapping;
}

void wiz::MappingDatabase::clearMappings() {
	map.clear();
}

bool wiz::MappingDatabase::hasMapping(uint16_t vendorId, uint16_t productId) const {
	return map.find(std::make_pair(vendorId, productId)) != map.end();
}

void wiz::MappingDatabase::loadFromCSVFile(const std::string& csvDbFile) {
	std::ifstream stream(csvDbFile);
	std::stringstream buffer;
	buffer << stream.rdbuf();
	loadFromCSV(buffer.str());
}

const wiz::Mapping &wiz::MappingDatabase::getMapping(const sf::Joystick::Identification& id) const {
    return getMapping(id.vendorId, id.productId);
}

bool wiz::MappingDatabase::hasMapping(const sf::Joystick::Identification& id) const {
    return hasMapping(id.vendorId, id.productId);
}

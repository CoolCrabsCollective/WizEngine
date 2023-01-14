//
// Created by Alexander Winter on 2022-03-27.
//

#ifndef WIZENGINE_MAPPINGDATABASE_H
#define WIZENGINE_MAPPINGDATABASE_H

#include <string>
#include <map>
#include "Mapping.h"
#include <SFML/Window/Joystick.hpp>

namespace wiz {
	class MappingDatabase;
}

typedef std::pair<uint16_t, uint16_t> sfml_controller_id;

class wiz::MappingDatabase {
	std::map<sfml_controller_id, Mapping> map;
	static MappingDatabase instance;
public:
	void loadFromCSVFile(const std::string& csvDbFile);

	void loadFromCSV(const std::string& csvDbContent);

	void addMapping(uint16_t vendorId, uint16_t productId, wiz::Mapping mapping);

	void clearMappings();

	const wiz::Mapping& getMapping(uint16_t vendorId, uint16_t productId) const;

	bool hasMapping(uint16_t vendorId, uint16_t productId) const;

	const wiz::Mapping& getMapping(const sf::Joystick::Identification& id) const;

	bool hasMapping(const sf::Joystick::Identification& id) const;

	static const MappingDatabase& getInstance();
};


#endif //WIZENGINE_MAPPINGDATABASE_H

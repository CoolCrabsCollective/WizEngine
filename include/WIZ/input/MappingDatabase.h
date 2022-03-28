//
// Created by Alexander Winter on 2022-03-27.
//

#ifndef WIZENGINE_MAPPINGDATABASE_H
#define WIZENGINE_MAPPINGDATABASE_H

#include <string>
#include <map>
#include "Mapping.h"

namespace wiz {
	class MappingDatabase;
}

class wiz::MappingDatabase {
	std::map<std::string, Mapping> map;
	static MappingDatabase instance;
public:
	void loadFromCSVFile(const std::string& csvDbFile);

	void loadFromCSV(const std::string& csvDbContent);

	void addMapping(const std::string& controllerName, Mapping mapping);

	void clearMappings();

	const Mapping& getMapping(const std::string& controllerName) const;

	bool hasMapping(const std::string& controllerName) const;

	static const MappingDatabase& getInstance();
};


#endif //WIZENGINE_MAPPINGDATABASE_H

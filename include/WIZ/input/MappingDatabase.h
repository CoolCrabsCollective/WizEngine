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
public:
	void loadFromCSV(const std::string& csvDatabase);

	const Mapping& getMapping(const std::string& controllerName) const;
};


#endif //WIZENGINE_MAPPINGDATABASE_H

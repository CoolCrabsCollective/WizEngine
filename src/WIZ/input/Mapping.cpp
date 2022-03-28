//
// Created by Alexander Winter on 2022-03-27.
//

#include <stdexcept>
#include "WIZ/input/Mapping.h"

int wiz::Mapping::getButton(wiz::MapButton mapButton) const {
	if(mapButton == wiz::MapButton::Count)
		throw std::invalid_argument("Count is not a valid MapButton, this enum constant exists to count the amount of buttons");

	return map[static_cast<int>(mapButton)];
}

bool wiz::Mapping::hasButton(wiz::MapButton mapButton) const {
	return getButton(mapButton) != -1;
}

wiz::Mapping::Mapping() : map() {
	for(int & i : map)
		i = -1;
}

void wiz::Mapping::set(wiz::MapButton mapButton, int value) {
	map[static_cast<int>(mapButton)] = value;
}

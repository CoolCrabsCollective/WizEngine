//
// Created by Alexander Winter on 2022-03-27.
//

#include <stdexcept>
#include "WIZ/input/Mapping.h"

int wiz::Mapping::getButton(wiz::MapButton mapButton) const {
	if(mapButton == wiz::MapButton::MapButton_Count)
		throw std::invalid_argument("MapButton_Count is not a valid MapButton, this enum constant exists to count the amount of buttons");

	return buttonMap[static_cast<int>(mapButton)];
}

int wiz::Mapping::getAxis(wiz::MapAxis mapAxis) const {
    if(mapAxis == wiz::MapAxis::MapAxis_Count)
        throw std::invalid_argument("MapAxis_Count is not a valid MapAxis, this enum constant exists to count the amount of buttons");

    return axisMap[static_cast<int>(mapAxis)];
}

bool wiz::Mapping::hasButton(wiz::MapButton mapButton) const {
	return getButton(mapButton) != -1;
}

bool wiz::Mapping::hasAxis(wiz::MapAxis mapAxis) const {
    return getAxis(mapAxis) != -1;
}

wiz::Mapping::Mapping() : buttonMap(), axisMap() {
	for(int & i : buttonMap)
		i = -1;
}

void wiz::Mapping::set(wiz::MapButton mapButton, int value) {
    buttonMap[static_cast<int>(mapButton)] = value;
}

void wiz::Mapping::set(wiz::MapAxis mapAxis, int value) {
    axisMap[static_cast<int>(mapAxis)] = value;
}

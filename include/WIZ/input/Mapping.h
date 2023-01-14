//
// Created by Alexander Winter on 2022-03-27.
//

#ifndef WIZENGINE_MAPPING_H
#define WIZENGINE_MAPPING_H

namespace wiz {
	class Mapping;

	enum MapButton {
		A,
		B,
		X,
		Y,
		Left_Shoulder,
		Right_Shoulder,
		Left_Trigger,
		Right_Trigger,
		Left_Stick,
		Right_Stick,
		Back,
		Start,
		MapButton_Count
	};

	enum MapAxis {
		Left_X,
		Left_Y,
		Right_X,
		Right_Y,
		MapAxis_Count
	};
}

class wiz::Mapping {
	int buttonMap[MapButton::MapButton_Count];
	int axisMap[MapAxis::MapAxis_Count];
public:
	Mapping();

	/**
	 * Checks if this mapping has the given mapped button
	 *
	 * @param mapButton mapped button to check
	 * @return true if the button is present, otherwise false
	 */
	bool hasButton(MapButton mapButton) const;

	/**
	 * Retrieves the button ID for a specified mapped button
	 *
	 * @param mapButton universally mapped button
	 * @return the button number associated to the mapped button, or -1 if not present
	 */
	int getButton(MapButton mapButton) const;

	/**
	 * Checks if this mapping has the given mapped axis
	 *
	 * @param mapAxis axis to check
	 * @return true if the axis is present in the mapping, otherwise false
	 */
	bool hasAxis(MapAxis mapAxis) const;

	/**
	 * Returns the axis number for the specified mapped axis
	 *
	 * @param mapAxis axis
	 * @return axis number
	 */
	int getAxis(MapAxis mapAxis) const;

	void set(MapButton mapButton, int value);

	void set(MapAxis mapAxis, int value);
};


#endif //WIZENGINE_MAPPING_H

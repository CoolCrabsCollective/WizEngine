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
		Dpad_Right,
		Dpad_Up,
		Dpad_Left,
		Dpad_Down,
		Count
	};
}

class wiz::Mapping {
	int map[MapButton::Count];
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

	void set(MapButton mapButton, int value);
};


#endif //WIZENGINE_MAPPING_H

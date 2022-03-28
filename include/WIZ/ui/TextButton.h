//
// Created by Alexander Winter on 2022-03-15.
//

#ifndef WIZENGINE_TEXTBUTTON_H
#define WIZENGINE_TEXTBUTTON_H

#include "SFML/Graphics/Text.hpp"
#include "SW/NinePatch.hpp"

namespace wiz {
	class TextButton;
}

class wiz::TextButton : public sf::Drawable, public sf::Transformable {
	sf::Text text;
	sw::NinePatch up, down, over;
	float padTop, padBottom, padLeft, padRight;

public:
	TextButton();

	const sf::Text& getText() const;

	const sw::NinePatch& getUp() const;

	void setUp(const sw::NinePatch& up);

	const sw::NinePatch& getDown() const;

	void setDown(const sw::NinePatch& down);

	const sw::NinePatch& getOver() const;

	void setOver(const sw::NinePatch& over);

	float getPadTop() const;

	void setPadTop(float padTop);

	float getPadBottom() const;

	void setPadBottom(float padBottom);

	float getPadLeft() const;

	void setPadLeft(float padLeft);

	float getPadRight() const;

	void setPadRight(float padRight);

};


#endif //WIZENGINE_TEXTBUTTON_H

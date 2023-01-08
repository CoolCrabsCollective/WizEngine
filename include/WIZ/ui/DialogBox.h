//
// Created by cedric on 2022-10-02.
//

#ifndef LD51_CLIENT_DIALOGBOX_H
#define LD51_CLIENT_DIALOGBOX_H


#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <functional>

namespace wiz {
	class DialogBox;
}

/**
 * UI element for NPC dialogs, draws a box in the bottom of the screen with text
 */
class wiz::DialogBox : public sf::Drawable {
protected:

	static const int lineMaxChars = 78;

	static std::vector<std::vector<std::string>> processText(const std::vector<std::string>& text);

	std::vector<std::vector<std::string>> dialog;
	float currentTextProgressTime = 0.0f;
	float currentMaximumProgressTime = 0.0f;

	sf::Font* font = nullptr;
	mutable sf::Sprite sprite;
	mutable sf::Text text;

	std::function<void()> callback = []() {};
	bool wasInProgress = false;

	int dialogIndex = 0;
	float maximumTextProgressTime = 4.0f;

	void next();

	void complete();

	void setDialogDuration();

public:

	/**
	 * Instantiates a dialog given a font and a background texture
	 * @param font font to use
	 * @param background background to draw behind
	 */
	DialogBox(sf::Font* font, sf::Texture* background);

	/**
	 * Called when the player interacts with the dialog to progress through the text
	 */
	virtual void interact();

	/**
	 * Updates the dialog box, must be called every frame
	 * @param delta
	 */
	virtual void update(float delta);

	/**
	 * Starts a dialog given a vector of lines to display in order
	 *
	 * @param lines lines to display
	 * @param callback callback to call after the dialog is over, warning DO NOT start a new dialog in the callback
	 */
	virtual void startDialog(const std::vector<std::string>& lines, std::function<void()> callback = []() {});

	/**
	 * @return true if currently displaying, otherwise false
	 */
	virtual bool isInProgress() const;

	/**
	 * Draws the dialog on screen
	 */
	virtual void draw(sf::RenderTarget& target, const sf::RenderStates& states) const override;
};


#endif //LD51_CLIENT_DIALOGBOX_H

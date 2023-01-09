//
// Created by cedric on 2022-10-02.
//

#include <WIZ/ui/DialogBox.h>
#include <SFML/Graphics.hpp>

using namespace wiz;

DialogBox::DialogBox(sf::Font* font, sf::Texture* background)
		: font(font), sprite(*background) {

}

void DialogBox::interact() {
	if (currentTextProgressTime < currentMaximumProgressTime)
		complete();
	else
		next();
}

void DialogBox::update(float delta) {
	currentTextProgressTime += delta / 1000.0f;

	if (!isInProgress() && wasInProgress) {
		callback();
		callback = []() {};
	}

	wasInProgress = isInProgress();
}

void DialogBox::draw(sf::RenderTarget& target, const sf::RenderStates& states) const {
	if (!this->isInProgress())
		return;

	sf::View old = target.getView();

	// this dialog is made for 1280 x 720 viewports so we set the viewport and then
	// we undo it for whatever viewport the user is already using
	sf::Vector2f viewSize = {1280, 720};
	target.setView(sf::View({viewSize.x / 2.0f, viewSize.y / 2.0f}, viewSize));

	float dialog_ratio = currentTextProgressTime / currentMaximumProgressTime;
	if (dialog_ratio > 1.0f)
		dialog_ratio = 1.0f;


	std::string first_string = dialog[dialogIndex][0];
	std::string second_string = dialog[dialogIndex][1];


	int characters_to_show = (first_string.size() + second_string.size()) * dialog_ratio;

	if (characters_to_show < first_string.size()) {
		second_string.clear();
		first_string = first_string.substr(0, characters_to_show);
	} else {
		second_string = second_string.substr(0, characters_to_show - first_string.size());
	}

	sprite.setPosition({60.0f, 620.0f - 50.0f});
	sprite.setScale({1160.0f / sprite.getTexture()->getSize().x,
					 128.0f / sprite.getTexture()->getSize().y});
	target.draw(sprite);

	text.setFont(*font);
	text.setString(first_string);
	text.setScale({1.2f, 1.2f});
	text.setPosition({75.0f, 620.0f - 30.0f});
	text.setOutlineColor(sf::Color::Black);
	text.setFillColor(sf::Color::Black);
	target.draw(text);

	text.setPosition({75.0f, 620.0f});
	text.setString(second_string);
	target.draw(text);

	target.setView(old);
}

void DialogBox::next() {
	dialogIndex++;
	currentTextProgressTime = 0;
	if (dialogIndex < dialog.size())
		currentMaximumProgressTime = maximumTextProgressTime *
									 (static_cast<float>(dialog[dialogIndex][0].size() +
														 dialog[dialogIndex][1].size()) /
									  static_cast<float>(getMaxCharsPerLine()));
}

void DialogBox::complete() {
	currentTextProgressTime = currentMaximumProgressTime;
}

void DialogBox::startDialog(const std::vector<std::string>& lines, std::function<void()> callback) {
	dialogIndex = 0;
	this->dialog = processText(lines);
	this->callback = callback;
	currentTextProgressTime = 0;
	setDialogDuration();
}

bool DialogBox::isInProgress() const {
	return dialogIndex < dialog.size();
}

std::vector<std::vector<std::string>>
DialogBox::processText(const std::vector<std::string>& inputText) {
	std::vector<std::vector<std::string>> outputText;
	for (auto string: inputText) {
		std::string remainingString(string.begin(), string.end());
		bool done = false;
		std::vector<std::string> screen_text;
		do {
			if (remainingString.size() <= getMaxCharsPerLine()) {
				if (screen_text.size() == 2) {
					outputText.push_back(screen_text);
					screen_text.clear();
				}
				screen_text.push_back(remainingString);
				done = true;
			} else {
				int split_index = 0;
				for (int i = getMaxCharsPerLine() - 1; i >= 0; i--) {
					if (remainingString[i] == ' ' || remainingString[i] == '-') {
						split_index = i;
						break;
					}
				}

				if (screen_text.size() == 2) {
					outputText.push_back(screen_text);
					screen_text.clear();
				}
				screen_text.push_back(remainingString.substr(0, split_index + 1));
				remainingString = remainingString.substr(split_index + 1);
			}
		} while (!done);

		if (screen_text.size() == 1)
			screen_text.emplace_back("");
		outputText.push_back(screen_text);
	}
	return outputText;
}

void DialogBox::setDialogDuration() {
	currentMaximumProgressTime = maximumTextProgressTime *
								 (static_cast<float>(dialog[dialogIndex][0].size() +
													 dialog[dialogIndex][1].size()) /
								  static_cast<float>(getMaxCharsPerLine()));
}

int DialogBox::getMaxCharsPerLine() const {
    return 78;
}

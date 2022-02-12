//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_GAME_H
#define GAMETEMPLATE_GAME_H

#include <memory>
#include "SFML/Graphics/RenderWindow.hpp"
#include "WIZ/logging/Logger.h"

namespace wiz {
	class Game;
	class Screen;
}

class wiz::Game {
	const std::shared_ptr<sf::RenderWindow> window;
	const std::shared_ptr<Logger> logger;

	std::shared_ptr<Screen> currentScreen = nullptr;
public:
	Game(sf::RenderWindow* window, Logger* logger);
	Game(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<Logger> logger);
	virtual ~Game() = default;

	void update();

	std::shared_ptr<Screen> getScreen() const;
	void setScreen(std::shared_ptr<Screen> screen);
	void setScreen(Screen* screen);
};


#endif //GAMETEMPLATE_GAME_H

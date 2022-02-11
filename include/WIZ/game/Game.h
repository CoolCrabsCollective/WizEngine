//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_GAME_H
#define GAMETEMPLATE_GAME_H

#include <memory>
#include "Screen.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "WIZ/logging/Logger.h"

namespace wiz {
	class Game;
}

class wiz::Game {
	const std::shared_ptr<sf::RenderWindow> window;
	const std::shared_ptr<wiz::Logger> logger;

	std::shared_ptr<wiz::Screen> currentScreen = nullptr;
public:
	Game(sf::RenderWindow* window, wiz::Logger* logger);
	Game(std::shared_ptr<sf::RenderWindow> window, std::shared_ptr<wiz::Logger> logger);
	virtual ~wiz::Game() = default;

	void update();

	std::shared_ptr<wiz::Screen> getScreen() const;
	void setScreen(std::shared_ptr<wiz::Screen> screen);
	void setScreen(wiz::Screen* screen);
};


#endif //GAMETEMPLATE_GAME_H

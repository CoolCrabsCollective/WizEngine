//
// Created by Alexander Winter on 2022-02-11.
//

#ifndef GAMETEMPLATE_GAME_H
#define GAMETEMPLATE_GAME_H

#include <memory>
#include "SFML/Graphics/RenderWindow.hpp"
#include "WIZ/logging/Logger.h"
#include "WIZ/asset/AssetLoader.h"
#include "InputListener.h"
#include "WindowListener.h"

namespace wiz {
	class Game;
	class Screen;
}

class wiz::Game {
public:
	virtual ~Game() = default;

	virtual void update() = 0;

	virtual Screen& getScreen() = 0;
	virtual const Screen& getScreen() const = 0;

	virtual void setScreen(std::shared_ptr<Screen> screen) = 0;
	virtual void setScreen(Screen* screen) = 0;

	virtual Logger& getLogger() = 0;
	virtual const Logger& getLogger() const = 0;

	virtual sf::RenderWindow& getWindow() = 0;
	virtual const sf::RenderWindow& getWindow() const = 0;

	virtual AssetLoader& getAssets() = 0;
	virtual const AssetLoader& getAssets() const = 0;

	virtual void addInputListener(InputListener* listener) = 0;
	virtual void removeInputListener(InputListener* listener) = 0;

	virtual void addWindowListener(WindowListener* listener) = 0;
	virtual void removeWindowListener(WindowListener* listener) = 0;
};


#endif //GAMETEMPLATE_GAME_H

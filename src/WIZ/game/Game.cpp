//
// Created by Alexander Winter on 2022-02-11.
//

#include "WIZ/game/Game.h"
#include "WIZ/game/Screen.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "WIZ/logging/Logger.h"

#include <utility>


wiz::Game::Game(sf::RenderWindow* window, wiz::Logger* logger)
	: Game(std::shared_ptr<sf::RenderWindow>(window), std::shared_ptr<wiz::Logger>(logger)) {}

wiz::Game::Game(std::shared_ptr<sf::RenderWindow> window,
				std::shared_ptr<wiz::Logger> logger)
		: window(std::move(window)), logger(std::move(logger)) {}

void wiz::Game::update() {
	if(currentScreen != nullptr) {
		currentScreen->tick(16.666);
		currentScreen->render(*window);
	} else {
		window->clear();
		window->display();
	}
}

std::shared_ptr<wiz::Screen> wiz::Game::getScreen() const {
	return currentScreen;
}

void wiz::Game::setScreen(std::shared_ptr<wiz::Screen> screen) {
	if(this->currentScreen != nullptr) {
		this->logger->info("Hiding screen " + this->currentScreen->getName());
		this->currentScreen->hide();
	}

	this->currentScreen = std::move(screen);

	if(this->currentScreen != nullptr) {
		this->logger->info("Showing screen " + this->currentScreen->getName());
		this->currentScreen->show();
	}
}

void wiz::Game::setScreen(wiz::Screen* screen) {
	setScreen(std::shared_ptr<wiz::Screen>(screen));
}

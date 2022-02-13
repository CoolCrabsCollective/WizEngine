//
// Created by Alexander Winter on 2022-02-11.
//

#include "WIZ/game/Screen.h"

wiz::Screen::Screen(wiz::Game& game)
	: game(game) {}

const wiz::Game& wiz::Screen::getGame() const {
	return game;
}

wiz::Game& wiz::Screen::getGame() {
	return game;
}

wiz::Logger& wiz::Screen::getLogger() {
	return getGame().getLogger();
}

const wiz::Logger& wiz::Screen::getLogger() const {
	return getGame().getLogger();
}

wiz::AssetLoader& wiz::Screen::getAssets() {
	return getGame().getAssets();
}

const wiz::AssetLoader& wiz::Screen::getAssets() const {
	return getGame().getAssets();
}

sf::RenderWindow& wiz::Screen::getWindow() {
	return getGame().getWindow();
}

const sf::RenderWindow& wiz::Screen::getWindow() const {
	return getGame().getWindow();
}

//
// Created by Alexander Winter on 2022-02-11.
//

#include "WIZ/game/Screen.h"

wiz::Screen::Screen(const wiz::Game& game)
	: game(game) {}

const wiz::Game& wiz::Screen::getGame() const {
	return game;
}

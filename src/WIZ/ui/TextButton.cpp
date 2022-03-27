//
// Created by Alexander Winter on 2022-03-15.
//

#include "WIZ/ui/TextButton.h"

const sf::Text& wiz::TextButton::getText() const {
	return text;
}

const sw::NinePatch& wiz::TextButton::getUp() const {
	return up;
}

void wiz::TextButton::setUp(const sw::NinePatch& up) {
	this->up = up;
}

const sw::NinePatch& wiz::TextButton::getDown() const {
	return down;
}

void wiz::TextButton::setDown(const sw::NinePatch& down) {
	this->down = down;
}

const sw::NinePatch& wiz::TextButton::getOver() const {
	return over;
}

void wiz::TextButton::setOver(const sw::NinePatch& over) {
	this->over = over;
}

float wiz::TextButton::getPadTop() const {
	return padTop;
}

void wiz::TextButton::setPadTop(float padTop) {
	this->padTop = padTop;
}

float wiz::TextButton::getPadBottom() const {
	return padBottom;
}

void wiz::TextButton::setPadBottom(float padBottom) {
	this->padBottom = padBottom;
}

float wiz::TextButton::getPadLeft() const {
	return padLeft;
}

void wiz::TextButton::setPadLeft(float padLeft) {
	this->padLeft = padLeft;
}

float wiz::TextButton::getPadRight() const {
	return padRight;
}

void wiz::TextButton::setPadRight(float padRight) {
	this->padRight = padRight;
}

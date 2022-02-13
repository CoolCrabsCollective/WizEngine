//
// Created by Winter on 12/02/2022.
//

#ifndef WIZENGINE_INPUTLISTENER_H
#define WIZENGINE_INPUTLISTENER_H

#include "SFML/Window/Event.hpp"

namespace wiz {
	class InputListener;
}

class wiz::InputListener {
public:
	virtual ~InputListener() = default;

	virtual void keyPressed(const sf::Event::KeyEvent& keyEvent) {};
	virtual void keyReleased(const sf::Event::KeyEvent& keyEvent) {};
	virtual void textEntered(const sf::Event::TextEvent& textEvent) {};

	virtual void mouseMoved(const sf::Event::MouseMoveEvent& mouseMoveEvent) {};
	virtual void mouseButtonPressed(const sf::Event::MouseButtonEvent& mouseButtonEvent) {};
	virtual void mouseButtonReleased(const sf::Event::MouseButtonEvent& mouseButtonEvent) {};
	virtual void mouseWheelScrolled(const sf::Event::MouseWheelScrollEvent& mouseWheelScrollEvent) {};

	virtual void joystickButtonPressed(const sf::Event::JoystickButtonEvent& joystickButtonEvent) {};
	virtual void joystickButtonReleased(const sf::Event::JoystickButtonEvent& joystickButtonEvent) {};
	virtual void joystickMoved(const sf::Event::JoystickMoveEvent& joystickMoveEvent) {};
	virtual void joystickConnected(const sf::Event::JoystickConnectEvent& joystickConnectEvent) {};
	virtual void joystickDisconnected(const sf::Event::JoystickConnectEvent& joystickConnectEvent) {};

	virtual void touchBegan(const sf::Event::TouchEvent& touchEvent) {};
	virtual void touchMoved(const sf::Event::TouchEvent& touchEvent) {};
	virtual void touchEnded(const sf::Event::TouchEvent& touchEvent) {};

	virtual void sensorChanged(const sf::Event::SensorEvent& sensorEvent) {};
};


#endif //WIZENGINE_INPUTLISTENER_H

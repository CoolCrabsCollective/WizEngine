//
// Created by Winter on 12/02/2022.
//

#ifndef WIZENGINE_WINDOWLISTENER_H
#define WIZENGINE_WINDOWLISTENER_H

#include "SFML/Window/Event.hpp"

namespace wiz {
	class WindowListener;
}

class wiz::WindowListener {
public:
	virtual ~WindowListener() = default;

	virtual void windowClosed() {};
	virtual void windowResized(const sf::Event::SizeEvent& sizeEvent) {};
	virtual void windowLostFocus() {};
	virtual void windowGainedFocus() {};

	virtual void mouseEntered() {};
	virtual void mouseExited() {};
};


#endif //WIZENGINE_WINDOWLISTENER_H

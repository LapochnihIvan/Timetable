#include <iomanip>
#include <functional>

#include <SFML/Graphics.hpp>

#include "RectWithText.h"

#ifndef INPUT_OBJECT_H
#define INPUT_OBJECT_H

class InputObject : public RectWithText
{
public:
	InputObject(const sf::String &string,
		const sf::Vector2f &size,
		sf::RenderWindow &window);
	virtual void actionListener(sf::Event &event);
protected:
	sf::Event::EventType evType;
	virtual bool check() = 0;
	virtual void action() = 0;
};
#endif
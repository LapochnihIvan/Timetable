#include <iomanip>
#include <functional>

#include <SFML/Graphics.hpp>

#include "RectWithText.h"

#ifndef INPUT_OBJECT_H
#define INPUT_OBJECT_H

class InputObject : public RectWithText
{
public:
	InputObject(const sf::Vector2f& position,
		const sf::Vector2f& size,
		const sf::String& string,
		sf::RenderWindow& window);
	virtual void actionListener(sf::Event& event);
protected:
	virtual bool check() = 0;
	virtual void foo() = 0;
	sf::Event::EventType evType;
};
#endif
#ifndef BUTTON_H
#define BUTTON_H

#include <iomanip>
#include <functional>

#include "InputObject.h"

class Button : public InputObject
{
public:
	Button(const sf::String &string, 
		const sf::Vector2f &position,
		const sf::Vector2f &size,
		const std::function<void()> &action,
		sf::RenderWindow &window);
private:
	const std::function<void()> act;
	bool check() final;
	void action() final;
};
#endif
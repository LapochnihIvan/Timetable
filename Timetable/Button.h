#ifndef BUTTON_H
#define BUTTON_H

#include <iomanip>
#include <functional>

#include "InputObject.h"

class Button : public InputObject
{
public:
	Button(const sf::Vector2f& position,
		const sf::Vector2f& size,
		const sf::String& string,
		const std::function<void()>& action,
		sf::RenderWindow& window);
	bool check() final;
	void foo() final;
private:
	const std::function<void()> action;
};
#endif
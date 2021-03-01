#include "Button.h"

Button::Button(const sf::Vector2f& position,
	const sf::Vector2f& size,
	const sf::String& string,
	const std::function<void()>& action,
	sf::RenderWindow& window) :
	InputObject(position, size, string, window),
	action(action)
{
	evType = sf::Event::MouseButtonPressed;
	//actionListener();
}

bool
Button::check()
{
	sf::Vector2i mCoords = sf::Mouse::getPosition();
	sf::Vector2i wCoords = window->getPosition();
	sf::Vector2f bCoords = rect.getPosition();
	sf::Vector2f bSize = rect.getSize();
	return mCoords.x > bCoords.x + 8 + wCoords.x
		&& mCoords.x < bCoords.x + 8 + bSize.x + wCoords.x
		&& mCoords.y > bCoords.y + 37 + wCoords.y
		&& mCoords.y < bCoords.y + bSize.y + 37 + wCoords.y;
}

void
Button::foo()
{
	action();
}
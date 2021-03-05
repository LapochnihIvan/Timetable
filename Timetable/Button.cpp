#include "Button.h"

Button::Button(const sf::String &string, 
	const sf::Vector2f &position,
	const sf::Vector2f &size,
	const std::function<void()> &action,
	sf::RenderWindow &window) :
	InputObject(string,
		size,
		window),
	act(action)
{
	rect.setPosition(position);
	rect.setFillColor(sf::Color(169, 169, 169));
	text.setPosition(position.x + window.getSize().x / 8.f - text.getGlobalBounds().width / 2.f, position.y + 5);
	evType = sf::Event::MouseButtonPressed;
}

bool
Button::check()
{
	sf::Vector2i mCoords = sf::Mouse::getPosition();
	sf::Vector2i wCoords = w->getPosition();
	sf::Vector2f bCoords = rect.getPosition();
	sf::Vector2f bSize = rect.getSize();
	return mCoords.x > bCoords.x + 8 + wCoords.x
		&& mCoords.x < bCoords.x + 8 + bSize.x + wCoords.x
		&& mCoords.y > bCoords.y + 37 + wCoords.y
		&& mCoords.y < bCoords.y + bSize.y + 37 + wCoords.y;
}

void
Button::action()
{
	act();
}
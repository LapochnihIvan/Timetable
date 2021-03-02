#include "RectWithText.h"
#include <iostream>

RectWithText::RectWithText(const sf::Vector2f& position,
	const sf::Vector2f& size,
	const sf::String& string,
	sf::RenderWindow& window):
	rect(size)
{
	static sf::Font font;
	if (font.getInfo().family == "")
		font.loadFromFile("arial.ttf");
	text = sf::Text(string, font, 22);
	rect.setPosition(position);
	rect.setFillColor(sf::Color(169, 169, 169));
	text.setPosition(position.x + window.getSize().x / 8.f - text.getGlobalBounds().width / 2.f, position.y);
	text.setFillColor(sf::Color(99, 99, 99));
	w = &window;
	run = false;
}

void
RectWithText::enable()
{
	run = true;
}

void
RectWithText::draw()
{
	if (run)
	{
		w->draw(rect);
		w->draw(text);
	}
}

void
RectWithText::disable()
{
	run = false;
}
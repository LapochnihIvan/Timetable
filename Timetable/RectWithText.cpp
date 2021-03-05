#include "RectWithText.h"

RectWithText::RectWithText(const sf::String &string,
	const sf::Vector2f &size,
	sf::RenderWindow &window,
	unsigned short characterSize):
	rect(size)
{
	static sf::Font font;
	if (font.getInfo().family == "")
		font.loadFromFile("arial.ttf");
	text = sf::Text(string, font, characterSize);
	text.setFillColor(sf::Color(99, 99, 99));
	w = &window;
	run = false;
}

RectWithText::RectWithText(const sf::String &string,
	const sf::Vector2f &position,
	const sf::Vector2f &size,
	const sf::Color &bgColor,
	sf::RenderWindow &window,
	unsigned short characterSize):
	RectWithText(string, size, window, characterSize)
{
	rect.setPosition(position);
	rect.setFillColor(bgColor);
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1);
	text.setPosition(rect.getPosition().x, rect.getPosition().y + 5.f);
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
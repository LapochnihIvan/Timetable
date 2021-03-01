#include "RectWithText.h"
#include <iostream>

RectWithText::RectWithText(const sf::Vector2f& position,
	const sf::Vector2f& size,
	const sf::String& string,
	sf::RenderWindow& window):
	rect(size)
{
	if (font.getInfo().family == "")
		font.loadFromFile("arial.ttf");
	text = new sf::Text(string, font, 22);
	rect.setPosition(position);
	rect.setFillColor(sf::Color(169, 169, 169));
	text->setPosition(position.x + window.getSize().x / 8.f - text->getGlobalBounds().width / 2.f, position.y);
	text->setFillColor(sf::Color(99, 99, 99));
	this->window = &window;
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
		window->draw(rect);
		//sf::Text text(L"Саня", font, 22);
		//text.setPosition(300, 300);
		//text.setFillColor(sf::Color(99, 99, 99));
		//window->draw(text);
		window->draw(*text);
	}
}

void
RectWithText::disable()
{
	run = false;
}
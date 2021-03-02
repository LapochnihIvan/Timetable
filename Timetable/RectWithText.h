#ifndef RECT_WITH_TEXT_H
#define RECT_WITH_TEXT_H

#include <SFML/Graphics.hpp>

class RectWithText
{
public:
	RectWithText(const sf::Vector2f& position,
		const sf::Vector2f& size,
		const sf::String& string,
		sf::RenderWindow& window);
	void enable();
	void draw();
	void disable();
protected:
	sf::RectangleShape rect;
	sf::Text text;
	sf::RenderWindow* w;
	bool run;
};
#endif

#ifndef GUI_H
#define GUI_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "TextBox.h"
class GUI
{
public:
	GUI();
	void startMainMenu();
	void generateTable();
	void run();
	void inputLesson();

private:
	sf::RenderWindow window;
	sf::Vector2u screanSize;
	sf::Font font;
	std::vector<sf::RectangleShape> rects;
	std::vector<sf::Text> texts;
	std::vector<Button> buttons;
	sf::Color grey;
	sf::Color darkGrey;
	TextBox t;
	TextBox tt;
};
#endif

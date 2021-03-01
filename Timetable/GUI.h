#ifndef GUI_H
#define GUI_H

#include <vector>

#include <SFML/Graphics.hpp>

#include "Button.h"
class GUI
{
public:
	GUI();
	void startMainMenu();
	void generateTable();
	void run(std::vector<Button>b/*Button& button, Button& button1, Button& button2*/);
	bool checkButtonPosition(sf::Vector2i mCoords, sf::Vector2i wCoords, sf::Vector2f bCoords, sf::Vector2f bSize);
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
};
#endif

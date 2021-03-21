#ifndef GUI_H
#define GUI_H

#include <vector>
#include <iomanip>
#include <functional>
#include <xstring>

#include <SFML/Graphics.hpp>

#include "Button.h"
#include "TextBox.h"
#include "Reader.h"

class GUI
{
public:
	GUI();
	void startMainMenu();

private:
	enum class Locations
	{
		MainMenu,
		Table,
		InputLesson
	};
	Locations location;
	sf::RenderWindow window;
	sf::Vector2u screanSize;
	sf::Font font;
	std::vector<sf::RectangleShape> rects;
	sf::Text text;
	std::vector<RectWithText> rectsWithTexts;
	std::vector<Button> buttons;
	sf::Color grey;
	sf::Color darkGrey;
	std::vector<TextBox> textBoxes;
	void generateTable();
	void run();
	void inputLesson();
	void swapTextBox();
};
#endif

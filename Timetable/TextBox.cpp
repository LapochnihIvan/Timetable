#include "TextBox.h"
#include <iostream>

TextBox::TextBox(const sf::Vector2f& position,
	const sf::Vector2f& size,
	const Type type,
	sf::RenderWindow& window) :
	InputObject(position, size, "", window)
{
	evType = sf::Event::KeyPressed;
	this->type = type;
}

void
TextBox::actionListener(sf::Event& event)
{
	pressKey = event.key.code;
	InputObject::actionListener(event);
}

bool
TextBox::check()
{
	bool result;
	if (type == Type::Numeric)
	{
		result = pressKey >= sf::Keyboard::Key::Num0
			&& pressKey <= sf::Keyboard::Key::Num9;
	}
	else
	{
		result = pressKey >= sf::Keyboard::Key::A
			&& pressKey <= sf::Keyboard::Key::F
			|| pressKey == sf::Keyboard::Key::Space
			|| pressKey >= sf::Keyboard::Key::LBracket
			&& pressKey <= sf::Keyboard::Key::Quote
			|| pressKey == sf::Keyboard::Key::Tilde;
	}
	return result || pressKey == sf::Keyboard::Key::Backspace;
}

void
TextBox::foo()
{
	std::wstring textBoxValue = text.getString();
	if (pressKey == sf::Keyboard::Key::Backspace
		&& textBoxValue.size() != 0) 
		textBoxValue.pop_back();
	else {
		wchar_t key;
		if (type == Type::Numeric) key = pressKey + 22;
		else key = pressKey + 'a';
		textBoxValue.push_back(key);
	}
	text.setString(textBoxValue);
	std::cout << text.getString().toAnsiString() << '\n';
}
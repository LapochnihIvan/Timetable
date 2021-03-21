#include "TextBox.h"

#include "Writer.h"

TextBox::TextBox(float y,
	const Type &type,
	sf::RenderWindow &window) :
	InputObject("", sf::Vector2f(800.f, 30.f), window)
{
	rect.setPosition(0.f, y);
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1);
	text.setPosition(0, y + 3.f);
	evType = sf::Event::KeyPressed;
	this->type = type;
}

void
TextBox::actionListener(sf::Event &event)
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
			&& pressKey <= sf::Keyboard::Key::Num9
			|| pressKey == sf::Keyboard::Semicolon
			|| pressKey == sf::Keyboard::Period;
	}
	else
	{
		result = pressKey >= sf::Keyboard::Key::A
			&& pressKey <= sf::Keyboard::Key::Z
			|| pressKey == sf::Keyboard::Key::Space
			|| pressKey >= sf::Keyboard::Key::LBracket
			&& pressKey <= sf::Keyboard::Key::Quote
			|| pressKey == sf::Keyboard::Key::Tilde;
	}
	return result
		|| pressKey == sf::Keyboard::Key::Backspace;
}

void
TextBox::action()
{
	std::wstring textBoxValue = text.getString();
	if (pressKey == sf::Keyboard::Backspace)
	{
		if (textBoxValue.size() != 0)
			textBoxValue.pop_back();
	}
	else {
		wchar_t key;
		if (type == Type::Numeric)
		{
			if (pressKey == sf::Keyboard::Semicolon)
				key = ':';
			else if (pressKey == sf::Keyboard::Period)
				key = '.';
			else key = pressKey + 22;
		}
		else
		{
			static std::map<sf::Keyboard::Key, wchar_t> russianChars = {
				{sf::Keyboard::A, L'�'},
				{sf::Keyboard::B, L'�'},
				{sf::Keyboard::C, L'�'},
				{sf::Keyboard::D, L'�'},
				{sf::Keyboard::E, L'�'},
				{sf::Keyboard::F, L'�'},
				{sf::Keyboard::G, L'�'},
				{sf::Keyboard::H, L'�'},
				{sf::Keyboard::I, L'�'},
				{sf::Keyboard::J, L'�'},
				{sf::Keyboard::K, L'�'},
				{sf::Keyboard::L, L'�'},
				{sf::Keyboard::M, L'�'},
				{sf::Keyboard::N, L'�'},
				{sf::Keyboard::O, L'�'},
				{sf::Keyboard::P, L'�'},
				{sf::Keyboard::Q, L'�'},
				{sf::Keyboard::R, L'�'},
				{sf::Keyboard::S, L'�'},
				{sf::Keyboard::T, L'�'},
				{sf::Keyboard::U, L'�'},
				{sf::Keyboard::V, L'�'},
				{sf::Keyboard::W, L'�'},
				{sf::Keyboard::X, L'�'},
				{sf::Keyboard::Y, L'�'},
				{sf::Keyboard::Z, L'�'},
				{sf::Keyboard::LBracket, L'�'},
				{sf::Keyboard::RBracket, L'�'},
				{sf::Keyboard::Semicolon, L'�'},
				{sf::Keyboard::Comma, L'�'},
				{sf::Keyboard::Period, L'�'},
				{sf::Keyboard::Quote, L'�'},
				{sf::Keyboard::Tilde, L'�'}
			};
			if (pressKey == sf::Keyboard::Space)
				key = ' ';
			else key = russianChars[pressKey];
		}
		textBoxValue.push_back(key);
	}
	text.setString(textBoxValue);
}

void
TextBox::write()
{
	//std::wcout << text.getString().toWideString() << '\n';
	Writer w;
	w.write(text.getString().toWideString());
}
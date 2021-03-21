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
				{sf::Keyboard::A, L'ô'},
				{sf::Keyboard::B, L'è'},
				{sf::Keyboard::C, L'ñ'},
				{sf::Keyboard::D, L'â'},
				{sf::Keyboard::E, L'ó'},
				{sf::Keyboard::F, L'à'},
				{sf::Keyboard::G, L'ï'},
				{sf::Keyboard::H, L'ð'},
				{sf::Keyboard::I, L'ø'},
				{sf::Keyboard::J, L'î'},
				{sf::Keyboard::K, L'ë'},
				{sf::Keyboard::L, L'ä'},
				{sf::Keyboard::M, L'ü'},
				{sf::Keyboard::N, L'ò'},
				{sf::Keyboard::O, L'ù'},
				{sf::Keyboard::P, L'ç'},
				{sf::Keyboard::Q, L'é'},
				{sf::Keyboard::R, L'ê'},
				{sf::Keyboard::S, L'û'},
				{sf::Keyboard::T, L'å'},
				{sf::Keyboard::U, L'ã'},
				{sf::Keyboard::V, L'ì'},
				{sf::Keyboard::W, L'ö'},
				{sf::Keyboard::X, L'÷'},
				{sf::Keyboard::Y, L'í'},
				{sf::Keyboard::Z, L'ÿ'},
				{sf::Keyboard::LBracket, L'õ'},
				{sf::Keyboard::RBracket, L'ú'},
				{sf::Keyboard::Semicolon, L'æ'},
				{sf::Keyboard::Comma, L'á'},
				{sf::Keyboard::Period, L'þ'},
				{sf::Keyboard::Quote, L'ý'},
				{sf::Keyboard::Tilde, L'¸'}
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
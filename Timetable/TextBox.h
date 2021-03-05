#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <xstring>
#include <map>

#include "InputObject.h"

class TextBox : public InputObject
{
public:
	enum Type {
		Numeric,
		Text
	};
	TextBox(float y,
		const Type &type,
		sf::RenderWindow &window);
	bool check() final;
	void action() final;
	void actionListener(sf::Event &event) final;
private:
	Type type;
	sf::Keyboard::Key pressKey;
	std::map<sf::Keyboard::Key, wchar_t> russianChars;
};
#endif
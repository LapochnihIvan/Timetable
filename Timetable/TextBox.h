#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <iostream>
#include <xstring>
#include <map>

#include "InputObject.h"

class TextBox : public InputObject
{
public:
	enum class Type {
		Numeric,
		Text
	};
	TextBox(float y,
		const Type &type,
		sf::RenderWindow &window);
	void actionListener(sf::Event &event) final;
	void write();
private:
	Type type;
	sf::Keyboard::Key pressKey;
	bool check() final;
	void action() final;
};
#endif
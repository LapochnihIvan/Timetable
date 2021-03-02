#ifndef TEXT_BOX_H
#define TEXT_BOX_H

#include <xstring>

#include "InputObject.h"

class TextBox : public InputObject
{
public:
	enum Type {
		Numeric,
		Text
	};
	TextBox(const sf::Vector2f& position,
		const sf::Vector2f& size,
		const Type type,
		sf::RenderWindow& window);
	bool check() final;
	void foo() final;
	void actionListener(sf::Event& event) final;
private:
	Type type;
	sf::Keyboard::Key pressKey;
};
#endif
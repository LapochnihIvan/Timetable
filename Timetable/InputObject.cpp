#include "InputObject.h"

InputObject::InputObject(const sf::String &string,
    const sf::Vector2f &size,
    sf::RenderWindow &window) :
    RectWithText(string, size, window)
{

}

void
InputObject::actionListener(sf::Event &event)
{
    if (!run) return;
    if (event.type == evType)
        if (check())
            action();
}
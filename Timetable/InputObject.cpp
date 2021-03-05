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
    //sf::Event event;
    //run = true;
    //while (window->isOpen())
    //{
    if (!run) return;
    //while (window->pollEvent(event))
    //{
    if (event.type == evType)
        if (check())
            action();
    //}
//}
}
#include "InputObject.h"

InputObject::InputObject(const sf::Vector2f& position,
                         const sf::Vector2f& size,
                         const sf::String& string,
                         sf::RenderWindow& window) :
    RectWithText(position, size, string, window)
{

}

void
InputObject::actionListener(sf::Event& event)
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
            foo();
    //}
//}
}
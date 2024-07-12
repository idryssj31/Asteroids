// Engine includes
#include <SFML/Graphics.hpp>

// Game includes
#include "Starship.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    auto starship = Starship();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            starship.Move();
        }

        window.clear();
        window.draw(shape);
        starship.Display(window);
        window.display();
    }

	return 0;
}
// Engine includes
#include <SFML/Graphics.hpp>

// Game includes
#include "Starship.h"
#include "Asteroid.h"

constexpr int WINDOW_LENGTH = 800;
constexpr int WINDOW_WIDTH = 600;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "SFML works!");
    Map::Init(WINDOW_LENGTH, WINDOW_WIDTH);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    auto starship = Starship();
    auto asteroid = Asteroid();
    auto chrono = sf::Clock();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        starship.UpdateBoostStatus();
        auto timeLoop = chrono.restart().asSeconds();
        starship.UpdateMovement(timeLoop);
        asteroid.UpdateMovement(timeLoop);
        window.clear();
        window.draw(shape);
        asteroid.Display(window);
        starship.Display(window);

        window.display();
    }

	return 0;
}
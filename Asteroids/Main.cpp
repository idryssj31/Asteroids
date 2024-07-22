// Engine includes
#include <SFML/Graphics.hpp>
#include <array>

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
    shape.setFillColor(sf::Color::Blue);
    auto starship = Starship();
    auto asteroid = Asteroid();
    auto asteroid2 = Asteroid();
    auto asteroid3 = Asteroid();
    auto elements = std::array<Entity*, 4>{&asteroid, &starship, &asteroid2, &asteroid3};
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
        for (Entity* element : elements)
        {
            element->UpdateMovement(timeLoop);
        }
        window.clear();
        for (auto* element : elements)
        {
            element->Display(window);
        }
        window.display();
    }

	return 0;
}
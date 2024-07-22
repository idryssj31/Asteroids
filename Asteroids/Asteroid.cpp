#include "Asteroid.h"
#include <iostream>
#include <random>
Asteroid::Asteroid() : Entity("../Ressources/Image/Asteroid/asteroid.png")
{
    auto generator = std::random_device();
    auto generatePosition = std::uniform_real_distribution<float>{ -150, 150 };
    auto generateSpeed = std::uniform_real_distribution<float>{ 80,120 };
    auto generateAngle = std::uniform_real_distribution<float>{ 0,360 };
    auto generateAngularSpeed = std::uniform_real_distribution<float>{ 10,30 };
    m_position = {generatePosition(generator), generatePosition(generator)};
    m_speed = Vector::AngleOrigin(generateSpeed(generator), generateAngle(generator));
    m_angularSpeed = generateAngularSpeed(generator);
}

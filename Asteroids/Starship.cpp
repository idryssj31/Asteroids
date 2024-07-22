#include "Starship.h"
#include <iostream>

Starship::Starship() : Entity("../Ressources/Image/Starship/starship.png")
{
}

Starship::~Starship()
{
	//std::cout << "Good bye";
}

void Starship::UpdateBoostStatus()
{
	m_boost = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
	m_turnLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	m_turnRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
}

void Starship::UpdateMovement(float _time)
{
	if (m_boost)
	{
		m_speed += Vector::AngleOrigin(ACCELERATION* _time, m_sprite.getRotation());
	}
	m_speed -= m_speed * COEFFICIENT_FRICTION * _time;
	if (m_turnLeft)
	{
		m_angularSpeed = -ANGULAR_VELOCITY;
	}
	else if (m_turnRight)
	{
		m_angularSpeed = ANGULAR_VELOCITY;
	}
	else
	{
		m_angularSpeed = 0;
	}
	Entity::UpdateMovement(_time);
}



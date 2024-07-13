#include "Starship.h"
#include <iostream>

Starship::Starship()
{
	Init();
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

void Starship::UpdateMovement(float time)
{
	if (m_boost)
	{
		m_speed += {ACCELERATION* time, 0.f};
	}
	m_speed -= m_speed * COEFFICIENT_FRICTION * time;
	auto movement = m_speed * time;
	m_sprite.move(movement.x, movement.y);
	if (m_turnLeft)
	{
		m_sprite.rotate(-ANGULAR_VELOCITY * time);
	}
	if (m_turnRight)
	{
		m_sprite.rotate(ANGULAR_VELOCITY * time);
	}
}

void Starship::Display(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void Starship::SetColor()
{
	m_sprite.setColor(m_color.White);
}

void Starship::Init()
{
	SetTexture();
	SetSprite();
	SetColor();
}

void Starship::SetTexture()
{
	if (!m_texture.loadFromFile("../Ressources/Image/Starship/starship.png"))
	{
		std::cerr << "the ship's image was not correctly displayed" << std::endl;
	}
}

void Starship::SetSprite()
{
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	m_sprite.setPosition(50, 50);
}

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

void Starship::UpdateBoostStatus(sf::Event const& event)
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
	{
		m_boost = true;
	}
	else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
	{
		m_boost = false;
	}
}

void Starship::UpdateMovement(float time)
{
	if (m_boost)
	{
		m_speed += ACCELERATION * time;
	}
	m_speed -= m_speed * COEFFICIENT_FRICTION * time;
	m_sprite.move(m_speed * time, 0);
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
}

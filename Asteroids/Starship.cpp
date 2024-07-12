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

void Starship::Move()
{
	m_sprite.move(10, 10);
}

void Starship::Display(sf::RenderWindow& window)
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

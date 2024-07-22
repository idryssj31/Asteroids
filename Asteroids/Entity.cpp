#include "Entity.h"

#include <iostream>
#include <array>

Entity::Entity(std::string_view const& _imagePath)
{
	SetTexture(_imagePath);
	Init();
}

void Entity::UpdateMovement(float _time)
{
	auto movement = m_speed * _time;
	m_sprite.move(movement.x, movement.y);
}

void Entity::Display(sf::RenderWindow& _window) const
{
	auto affichages = std::array<Vector, 9>{Vector{ -1, -1 }, Vector{ 0, -1 }, Vector{ 1, -1 },
											Vector{ -1, 0 }, Vector{ 0,0 }, Vector{ 1,0 },
											Vector{ -1, 1 }, Vector{ 0,1 }, Vector{ 1,1 }};
	for (auto& affichage : affichages) {
		auto transformation = sf::Transform{};
		transformation.translate(affichage.x * Map::GetLenght(), affichage.y * Map::GetWeight());
		_window.draw(m_sprite, transformation);
	}
}

void Entity::Init()
{
	SetSprite();
	SetColor();
}

void Entity::SetTexture(std::string_view const& _imagePath)
{
	if (!m_texture.loadFromFile(_imagePath.data()))
	{
		std::cerr << "the ship's image was not correctly displayed" << std::endl;
	}
}

void Entity::SetSprite()
{
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2);
	m_sprite.setPosition(location.getX(), location.getY());
}

void Entity::SetColor()
{
	m_sprite.setColor(m_color.White);
}

#pragma once

// Engine includes
#include <SFML/Graphics.hpp>

// Game includes
#include "Vector.h"
#include "Map.h"

class Entity
{
public:
	// Constructor
	Entity(std::string_view const& a);

public: // Methods
	virtual void UpdateMovement(float _time);
	void Display(sf::RenderWindow& _window) const;

	void Init();
	void SetTexture(std::string_view const&);
	void SetSprite();
	void SetColor();

protected: // Attributes
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Color m_color;
	Map position;
	float m_angularSpeed;
	Vector m_speed = { 0.f, 0.f };

};


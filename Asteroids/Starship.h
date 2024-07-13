#pragma once

// Engine includes
#include <SFML/Graphics.hpp>

// Game includes
#include "Vector.h"

class Starship
{
public:
	// Constructor
	Starship();

	// Destructor
	~Starship();

public: // Methods 
	void UpdateBoostStatus();
	void UpdateMovement(float time);
	void Display(sf::RenderWindow& window) const;

private: // Attributes
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Color m_color;

	Vector m_speed = {0.f, 0.f};
	bool m_boost = false;
	bool m_turnRight = false;
	bool m_turnLeft = false;

	static constexpr float ACCELERATION = 7000.f;
	static constexpr float COEFFICIENT_FRICTION = 2.f;
	static constexpr float ANGULAR_VELOCITY = 50.f;

protected: // Methods
	void Init();
	void SetTexture();
	void SetSprite();
	void SetColor();
};


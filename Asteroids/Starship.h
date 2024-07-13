#pragma once

// Engine includes
#include <SFML/Graphics.hpp>

class Starship
{
public:
	// Constructor
	Starship();

	// Destructor
	~Starship();

public: // Methods 
	void UpdateBoostStatus(sf::Event const& event);
	void UpdateMovement(float time);
	void Display(sf::RenderWindow& window) const;

private: // Attributes
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Color m_color;

	float m_speed = 0.f;
	bool m_boost = false;

	static constexpr float ACCELERATION = 7000.f;
	static constexpr float COEFFICIENT_FRICTION = 2.f;

protected: // Methods
	void Init();
	void SetTexture();
	void SetSprite();
	void SetColor();
};


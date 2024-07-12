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
	void Move();
	void Display(sf::RenderWindow& window);

private: // Attributes
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Color m_color;

protected: // Methods
	void Init();
	void SetTexture();
	void SetSprite();
	void SetColor();
};


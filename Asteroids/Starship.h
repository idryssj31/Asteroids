#pragma once

// Engine includes
#include <SFML/Graphics.hpp>

// Game includes
#include "Vector.h"
#include "Entity.h"
#include "Map.h"

class Starship : public Entity
{
public:
	// Constructor
	Starship();

	// Destructor
	~Starship();

public: // Methods 
	void UpdateBoostStatus();
	void UpdateMovement(float _time);

private: // Attributes
	bool m_boost = false;
	bool m_turnRight = false;
	bool m_turnLeft = false;

	static constexpr float ACCELERATION = 7000.f;
	static constexpr float COEFFICIENT_FRICTION = 2.f;
	static constexpr float ANGULAR_VELOCITY = 50.f;

	Map location;

protected: // Methods

};


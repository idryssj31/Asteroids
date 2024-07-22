#pragma once
struct Vector
{
	// Methods
	void operator+=(Vector const& _other);
	void operator-=(Vector const& _other);
	Vector operator*(float _coefficient) const;
	static Vector AngleOrigin(float _size, float _degreeAngle);

	// Attributes
	float x = 0.f;
	float y = 0.f;
	static constexpr float M_PI = 3.14159265f;
};


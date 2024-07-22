
#include "Vector.h"
#include <corecrt_math.h>


void Vector::operator+=(Vector const& _other)
{
	x += _other.x;
	y += _other.y;

}

void Vector::operator-=(Vector const& _other)
{
	x -= _other.x;
	y -= _other.y;
}

Vector Vector::operator*(float _coefficient) const
{
	return {x*_coefficient, y*_coefficient};
}

Vector Vector::AngleOrigin(float _size, float _angleDegree)
{
	return { _size * static_cast<float>(cos(_angleDegree / 180.f * M_PI)), _size * static_cast<float>(sin(_angleDegree / 180.f * M_PI)) };
}

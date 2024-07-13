#include "Vector.h"

void Vector::operator+=(Vector const& other)
{
	x += other.x;
	y += other.y;

}

void Vector::operator-=(Vector const& other)
{
	x -= other.x;
	y -= other.y;
}

Vector Vector::operator*(float coefficient) const
{
	return {x*coefficient, y*coefficient};
}

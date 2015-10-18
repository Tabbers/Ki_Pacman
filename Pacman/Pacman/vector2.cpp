#include "vector2.h"
#include <math.h>


Vector2::Vector2()
{
	x = 0;
	y = 0;
}


Vector2::~Vector2()
{
}

Vector2 Vector2::operator+(const Vector2 &rhs)
{
	Vector2 temp;
	temp.x = x + rhs.x;
	temp.y = y + rhs.y;
	return temp;
}
Vector2 Vector2::operator-(const Vector2 &rhs)
{
	Vector2 temp;
	temp.x = x - rhs.x;
	temp.y = y - rhs.y;
	return temp;
}
Vector2 Vector2::operator*(const float &rhs)
{
	Vector2 temp;
	temp.x = x * rhs;
	temp.y = y * rhs;
	return temp;
}

Vector2 Vector2::invert()
{
	Vector2 temp;
	temp.x = -x;
	temp.y = -y;
	return temp;
}

Vector2 Vector2::rotate(float angle)
{
	Vector2 temp;

	float theta = (angle*PI)/180;

	float cs = cos(theta);
	float sn = sin(theta);

	float px = x * cs - y * sn;
	float py = x * sn + y * cs;

	x = px;
	y = py;

	temp.x = x;
	temp.y = y;

	return temp;
}

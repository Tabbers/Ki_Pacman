#pragma once

#define PI 3.1415927410125732421875
class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2 operator+(const Vector2 &rhs);
	Vector2 operator-(const Vector2 &rhs);
	Vector2 operator*(const float &rhs);
	Vector2 invert();
	Vector2 rotate(float);
public:
	int x;
	int y;
};
#pragma once
class Vector2
{
public:
	Vector2();
	~Vector2();
	Vector2 operator+(const Vector2 &rhs);
	Vector2 operator-(const Vector2 &rhs);
public:
	int x;
	int y;
};
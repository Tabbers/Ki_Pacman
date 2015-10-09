#pragma once
#include "vector2.h"
class  Board;

class StateMachine
{
public:
	virtual ~StateMachine();
	virtual Vector2 calculateNewPosition(Vector2) = 0;
	virtual void determinePosition(Board*,char, char, char, char);
protected:
	char State;
	Vector2 position;
	Vector2 heading;
};


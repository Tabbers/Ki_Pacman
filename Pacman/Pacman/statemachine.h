#pragma once
#include "vector2.h"
class  Board;

class StateMachine
{
public:
	virtual ~StateMachine();
	virtual void calculateNewDestination(Vector2,char) = 0;
	virtual Vector2 calculateNextPosition();
	virtual void determinePosition(Board*,char, char, char, char);
protected:
	char State;
	Vector2 position;
	Vector2 heading;
};


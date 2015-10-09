#pragma once
#include "statemachine.h"

class Speedy: public StateMachine
{
public:
	Speedy();
	~Speedy();
	virtual Vector2 calculateNewPosition(Vector2);
};


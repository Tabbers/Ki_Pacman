#pragma once
#include "statemachine.h"

class Speedy: public StateMachine
{
public:
	Speedy();
	~Speedy();
	virtual void calculateNewDestination(Vector2,char);
};


#pragma once
#include "statemachine.h"

class Bashful : public StateMachine
{
public:
	Bashful();
	~Bashful();
	virtual void calculateNewDestination(Vector2,char);
};


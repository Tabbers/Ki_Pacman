#pragma once
#include "statemachine.h"

class Pokey : public StateMachine
{
public:
	Pokey();
	~Pokey();
	virtual void calculateNewDestination(Vector2,char);
};


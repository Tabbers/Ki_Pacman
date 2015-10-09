#pragma once
#include "statemachine.h"

class Pokey : public StateMachine
{
public:
	Pokey();
	~Pokey();
	virtual Vector2 calculateNewPosition(Vector2);
};


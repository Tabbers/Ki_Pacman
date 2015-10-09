#pragma once
#include "statemachine.h"

class Bashful : public StateMachine
{
public:
	Bashful();
	~Bashful();
	virtual Vector2 calculateNewPosition(Vector2);
};


#pragma once
#include "statemachine.h"

class Shadow: public StateMachine
{
public:
	Shadow();
	~Shadow();
	virtual Vector2 calculateNewPosition(Vector2);
};


#pragma once
#include "statemachine.h"

class Speedy: public StateMachine
{
public:
	Speedy();
	~Speedy();
	virtual void calculateNewDestination(Vector2, Vector2, char);
private:
	Vector2 home;
};


#pragma once
#include "statemachine.h"

class Pokey : public StateMachine
{
public:
	Pokey();
	~Pokey();
	virtual void calculateNewDestination(Vector2, Vector2, char);
private:
	Vector2 home;
};


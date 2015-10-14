#pragma once
#include "statemachine.h"

class Pacman : public StateMachine   
{
public:
	Pacman();
	~Pacman();
	virtual void calculateNewDestination(Vector2, Vector2, char);
};


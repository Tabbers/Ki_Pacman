#pragma once
#include "statemachine.h"

class Pacman : public StateMachine   
{
public:
	Pacman();
	~Pacman();
	virtual Vector2 calculateNewPosition(Vector2);
};


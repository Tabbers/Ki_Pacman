#pragma once
#include "statemachine.h"

class Shadow: public StateMachine
{
public:
	Shadow();
	~Shadow();
	virtual void calculateNewDestination(Vector2,char);
private:
	Vector2 home;
};


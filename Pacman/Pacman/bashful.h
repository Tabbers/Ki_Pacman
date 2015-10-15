#pragma once
#include "statemachine.h"
#include "shadow.h"

class Bashful : public StateMachine
{
public:
	Bashful();
	~Bashful();
	virtual void calculateNewDestination(Vector2, Vector2, char);
	//SETTER
	inline void SetShadowRef(Shadow* shadowX) { shadow = shadowX; };
private:
	Vector2 home;
	Shadow* shadow;
};


#pragma once
class  Vector2;

class StateMachine
{
public:
	virtual ~StateMachine();
	virtual Vector2 calculateNewPosition(Vector2);

protected:
	char State;
	int x, y;
	int headingX, headingY;


};


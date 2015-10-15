#pragma once
#include "vector2.h"
class  Board;

class StateMachine
{
public:
	virtual ~StateMachine();
	virtual void calculateNewDestination(Vector2, Vector2, char) = 0;
	virtual Vector2 calculateNextPosition();
	virtual void determinePosition(Board*,char, char, char, char);
	virtual char orientedCharacter();
	//GETTER
	inline Vector2 GetPosition() { return position; };
	inline Vector2 GetHeading() { return heading; };
protected:
	char representation[4];
	char state;
	Vector2 prevposition;
	Vector2 position;
	Vector2 heading;
};


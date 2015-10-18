#pragma once
#include "vector2.h"
class  Board;

class StateMachine
{
public:
	virtual ~StateMachine();
	virtual void calculateNewDestination(Vector2, Vector2, char) = 0;
	virtual Vector2 calculateNextPosition(Board*);
	virtual void determinePosition(Board*,char, char, char, char);
	virtual char orientedCharacter();
	virtual void calculateDirection();
	//GETTER
	inline Vector2 getPosition() { return position; };
	inline Vector2 getPrevPosition() { return prevposition; };
	inline Vector2 getHeading() { return heading; };
	inline Vector2 getDirection() { return dir; };

private:
	virtual bool Wallcheck(Board*,Vector2);

protected:
	char representation[4];
	char state;
	Vector2 prevposition;
	Vector2 position;
	Vector2 heading;
	Vector2 dir;
};


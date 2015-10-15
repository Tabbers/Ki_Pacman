#include "pokey.h"
#include "vector2.h"


Pokey::Pokey()
{
	home.x = 0;
	home.y = 31;
	representation[0] = 'q';
	representation[1] = 'r';
	representation[2] = 'Q';
	representation[3] = 'R';
}


Pokey::~Pokey()
{
}

void Pokey::calculateNewDestination(Vector2 pacpos, Vector2 pacheading, char state)
{
	//p = patrol, r = pursuit, e = escape
	Vector2 Distancevector;

	if (state == 'r')
	{
		Distancevector = pacpos - position;
		
		if ((Distancevector.x + Distancevector.y) > 8) heading = Distancevector;
		else heading = home - position;
	}
	else if (state == 'p')
	{
		heading = home - position;
	}
	else if (state = 'e')
	{
		heading = heading.invert();
	}
}

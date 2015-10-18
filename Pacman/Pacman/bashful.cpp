#include "bashful.h"
#include "vector2.h"


Bashful::Bashful()
{
	home.x = 28;
	home.y = 31;
	representation[0] = 'o';
	representation[1] = 'p';
	representation[2] = 'O';
	representation[3] = 'P';
}

Bashful::~Bashful()
{
}

void Bashful::calculateNewDestination(Vector2 pacpos, Vector2 pacheading, char state)
{
	//p = patrol, r = pursuit, e = escape

	if (state == 'r')
	{
		heading = ((pacpos - shadow->getPosition())+pacheading*2)*2;
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

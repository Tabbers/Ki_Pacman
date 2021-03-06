#include "speedy.h"
#include "vector2.h"


Speedy::Speedy()
{
	home.x = 0;
	home.y = 0;
	representation[0] = 'm';
	representation[1] = 'n';
	representation[2] = 'M';
	representation[3] = 'N';
}


Speedy::~Speedy()
{
}

void Speedy::calculateNewDestination(Vector2 pacpos, Vector2 pacdir, char state)
{
	//p = patrol, r = pursuit, e = escape

	if (state == 'r')
	{
		heading = (pacpos - position) + pacdir * 4;
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

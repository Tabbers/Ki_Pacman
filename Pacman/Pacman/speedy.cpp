#include "speedy.h"
#include "vector2.h"


Speedy::Speedy()
{
	home.x = 0;
	home.y = 0;
}


Speedy::~Speedy()
{
}

void Speedy::calculateNewDestination(Vector2 pacpos, Vector2 pacheading, char state)
{
	//p = patrol, r = pursuit, e = escape

	if (state == 'r')
	{
		heading = (pacpos - position) + pacheading * 4;
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

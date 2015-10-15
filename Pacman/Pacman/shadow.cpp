#include "shadow.h"
#include "vector2.h"


Shadow::Shadow()
{
	home.x = 28;
	home.y = 0;
	representation[0] = 'k';
	representation[1] = 'l';
	representation[2] = 'K';
	representation[3] = 'L';
}


Shadow::~Shadow()
{
}

void Shadow::calculateNewDestination(Vector2 pacpos, Vector2 pacheading, char state)
{
	//p = patrol, r = pursuit, e = escape

	if (state == 'r')
	{
		heading = pacpos - position;
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

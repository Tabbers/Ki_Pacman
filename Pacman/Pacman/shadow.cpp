#include "shadow.h"
#include "vector2.h"


Shadow::Shadow()
{
	home.x = 29;
	home.y = 1;
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

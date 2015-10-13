#include "shadow.h"
#include "vector2.h"


Shadow::Shadow()
{
	home.x = 27;
	home.y = 1;
}


Shadow::~Shadow()
{
}

void Shadow::calculateNewDestination(Vector2 pac, char state)
{
	//p = patrol, r = pursuit, e = escape

	if (state == 'r')
	{
		heading = pac - position;
	}
	else if (state == 'p')
	{
		heading = home - position;
	}
	else if (state = 'e')
	{

	}
}

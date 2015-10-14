#include "bashful.h"
#include "vector2.h"


Bashful::Bashful()
{
}

Bashful::Bashful(Shadow* shadow)
{
	home.x = 29;
	home.y = 32;
	shadow = shadow;
}


Bashful::~Bashful()
{
}

void Bashful::calculateNewDestination(Vector2 pacpos, Vector2 pacheading, char state)
{
	//p = patrol, r = pursuit, e = escape

	if (state == 'r')
	{
		heading = ((pacpos - shadow->GetPosition())+pacheading*2)*2;
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

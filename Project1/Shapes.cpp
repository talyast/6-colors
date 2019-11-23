#include "Shapes.h"



Shapes::Shapes()
{
}

Shapes::~Shapes()
{
}

int Shapes::getSizeNeigh()const
{
	return m_neighbors.size();
}

colors Shapes::randomColor()
{
	int color;
	color = rand() % 6;
	switch (color)

	{
	case 0:
		return RED;
		break;
	case 1:
		return ORANGE;
		break;
	case 2:
		return YELLOW;
		break;
	case 3:
		return GREEN;
		break;
	case 4:
		return BLUE;
		break;
	case 5:
		return PINK;
		break;
	default:
		break;
	}

}




#include "Computer.h"

Computer::Computer(Shapes * shape)
{
	m_area.insert(shape);
}

Computer::~Computer()
{
}

void Computer::doTurn(colors color, colors c)
{
	
	for (int i = 0; i < 6; ++i)
	{
		m_temp.clear();
		arr[i] = 0;
		std::unordered_set < Shapes*>::iterator it;
		for (it = m_area.begin(); it != m_area.end(); ++it) {
			colors c = colors(i);
			if (c != color && c!= last_color )
				checkNeighbor((*it), c);
			else
				break;
		}
		arr[i] =m_temp.size();
	}
	findLargestArea(arr);
	
}

void Computer::checkNeighbor(Shapes * it, colors color)
{
	next = false;
	int counter = 0;
	for (int i = 0; i < it->getSizeNeigh(); ++i)
	{
		Shapes* neighbor = it->getneighber(i);
		if (neighbor->getColor() == convertColor(color))
		{
			//check if we are going over shapes that are already in the area
			std::unordered_set<Shapes*>::const_iterator t = m_temp.find(neighbor);
			if (t == m_temp.end()) {
				m_temp.insert(neighbor);
				next = true;
			}

		}
		if(next)
		checkNeighbor(neighbor, color);
	}
}
void Computer::findLargestArea(int arr[])
{
	int max=0,index=0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] > max)
		{
			index = i;
			max = arr[i];
		}
	}
	last_color = convertIndexToColor(index);
	updateArea(last_color);
}

colors Computer::convertIndexToColor(int i) const
{
	if (i==0)
		return (RED);
	else if (i==1)
		return(ORANGE);
	else if (i==2)
		return(YELLOW);
	else if (i==3)
		return(GREEN);
	else if (i==4)
		return(BLUE);
	else
		return(PINK);
}

void Computer::updateArea(colors color)
{
	std::unordered_set < Shapes*>::iterator it;

	for (it = m_area.begin(); it != m_area.end(); ++it)
		checkNeighborInsert((*it), color);
	for (it = m_area.begin(); it != m_area.end(); ++it)
		(*it)->setColor(color);
}

void Computer::checkNeighborInsert(Shapes * it, colors color)
{
	for (int i = 0; i < it->getSizeNeigh(); ++i)
	{
		Shapes* neighbor = it->getneighber(i);
		if (neighbor->getColor() == convertColor(color))
			m_area.insert(neighbor);
	}
}

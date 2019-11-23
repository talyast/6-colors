#include "User.h"
#include <iostream>//no need maybe
#include <algorithm>



User::User(Shapes*shape) :init(25, 400)
{
	m_area.insert(shape);
}

User::~User()
{
}

void User::doTurn(colors color, colors c)
{
	std::unordered_set < Shapes*>::iterator it;
	for (it = m_area.begin(); it != m_area.end(); ++it)
		if (color != last_color && color != c)
			checkNeighbor((*it), color);
		else
			return;
	for (it = m_area.begin(); it != m_area.end(); ++it)
		(*it)->setColor(color);
	last_color = color;

}
bool User::checkIfNei(Shapes *nei)
{
	for (auto &i : m_area)
		if (nei == i)
			return true;
	return false;
}

void User::checkNeighbor(Shapes * it, colors color)
{
	for (int i = 0; i < it->getSizeNeigh(); ++i)
	{
		Shapes* neighbor = it->getneighber(i);
		if (neighbor->getColor() == convertColor(color))
			m_area.insert(neighbor);

	}
}


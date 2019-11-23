#pragma once
#include"Utills.h"
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include <unordered_set>
class Players
{
public:
	Players();
	~Players();
	
	virtual void doTurn(colors color, colors c)=0;
	virtual void checkNeighbor(Shapes* it, colors color) = 0;
	virtual colors getLastColor()const = 0;
	virtual double getAreaSize()const { return m_area.size(); };
	virtual void clearArea() { m_area.clear(); };
	//converts the color from enum to sf::color
	sf::Color convertColor(colors color) const;
protected:
	std::unordered_set<Shapes*> m_area;
};


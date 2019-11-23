#pragma once
//#include "Board.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utills.h"
class Shapes
{
public:
	Shapes();
	~Shapes();
	virtual void draw(sf::RenderWindow & window) = 0;
	virtual void goFindYourFriends(Shapes * shape) = 0;
	virtual sf::Vector2f getLocation() const = 0;
	virtual void setColor(colors color) = 0;
	virtual sf::Vector2f getMiddlePoint() const = 0;
	virtual sf::Color getColor()const = 0;
	virtual bool distanceTwoPoints(sf::Vector2f a, sf::Vector2f b)const = 0;
	int getSizeNeigh()const;
	Shapes* getneighber(int j) { return m_neighbors[j]; };

	//randomizes the color for each shape
	colors randomColor();
protected:
	std::vector <Shapes*> m_neighbors;

};


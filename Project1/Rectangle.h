#pragma once
#include "Shapes.h"
#include <SFML/Graphics.hpp>
#include "Utills.h"
#include<vector>
class Rectangle :public Shapes
{
public:
	Rectangle(int radius, int edges);
	~Rectangle();
	//draws the rectangle 
	virtual void draw(sf::RenderWindow & window) override;

	//finds neighbors of the rectangle
	void goFindYourFriends(Shapes * shape);

	//sets the color of the rectangle
	virtual void setColor(colors color)override;

	//gets the position of the rectangle
	virtual sf::Vector2f getLocation()const override;


	virtual sf::Vector2f getMiddlePoint() const override { return m_middle_point; };

	//chacks the distance between to points foe neighborhood
	virtual bool distanceTwoPoints(sf::Vector2f a, sf::Vector2f b)const override;

	//returns the color of the rectangle
	virtual sf::Color getColor()const override;

private:
	sf::CircleShape m_circle;
	sf::Vector2f m_middle_point;
};


#pragma once
#include "Shapes.h"
#include "Utills.h"
class Triangle:public Shapes
{
public:
	Triangle(int x, int y, bool first, int up);
	~Triangle();

	virtual void draw(sf::RenderWindow & window) override;
	//sets the color of the triangle
	virtual void setColor(colors color)override ;
	//finds the neighbors of the triangle
	virtual void goFindYourFriends(Shapes * shape) override;
	//finds the distance between to points for neigberhood
	virtual bool distanceTwoPoints(sf::Vector2f a, sf::Vector2f b)const override;
	//midle point of triangle
	virtual sf::Vector2f getMiddlePoint() const override;

	//gets the color of triangle 
	virtual sf::Color getColor() const override;
	//sets the color of the triangle
	void setColor2(colors color);
	//creates two vertical triangles
	void creatTriangeY(int x, int y);
	//create two horizantal triangles
	void creatTriangeX(int x, int y);
	void setColorFirstTriangle(colors color);
	void setColorSecondTriangle(colors color);
	void creatFirstTriangle(int x, int y, int up);
	void creatSecondTriangle(int x, int y, int up);
	sf::Vector2f getLocation()const override;

	
private:
	sf::ConvexShape polygon;
	sf::ConvexShape polygon1;
	sf::Vector2f m_middle_point1;
	sf::Vector2f m_middle_point2;
	bool m_first;
	bool up;
	
};


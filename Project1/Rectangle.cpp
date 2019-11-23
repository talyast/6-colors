#include "Rectangle.h"
#include <stdlib.h> 
#include <SFML/Graphics/Color.hpp>


Rectangle::Rectangle(int x, int y)
	:m_circle(radius, edges)
{
	setColor(randomColor());
	m_circle.setOutlineColor(sf::Color::White);
	m_circle.setOutlineThickness(1);
	
	m_circle.setPosition(x, y);
	m_middle_point.x = x ;
	m_middle_point.y = y + radius;
}


Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderWindow & window)
{
	window.draw(m_circle);
}
void Rectangle::goFindYourFriends(Shapes * shape)
{
	if (!(m_circle.getPosition().x == shape->getLocation().x && //this is - if shape is not me
		m_circle.getPosition().y == shape->getLocation().y))
	{
		if (dynamic_cast<Rectangle*>(shape))
		{
			if (distanceTwoPoints(m_middle_point, shape->getMiddlePoint()))
				m_neighbors.push_back(shape);
		}
		else if(shape->distanceTwoPoints(m_middle_point, shape->getMiddlePoint()))
			m_neighbors.push_back(shape);
		else
			;
	}
	
}

void Rectangle::setColor(colors color)
{
	if(color==RED)
		m_circle.setFillColor(sf::Color::Red);
	else if (color == ORANGE)
		m_circle.setFillColor(sf::Color(255, 153, 51));
	else if (color == YELLOW)
		m_circle.setFillColor(sf::Color::Yellow);
	else if (color == GREEN)
		m_circle.setFillColor(sf::Color::Green);
	else if (color == BLUE)
		m_circle.setFillColor(sf::Color::Blue);
	else
		m_circle.setFillColor(sf::Color(255, 102, 178));
}

sf::Vector2f Rectangle::getLocation()const
{
	return(sf::Vector2f{ m_circle.getPosition().x, m_circle.getPosition().y });
}


bool Rectangle::distanceTwoPoints(sf::Vector2f a, sf::Vector2f b)const
{
		if (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) < 2 * radius)
			return true;
		return false;

}

sf::Color Rectangle::getColor()const
{
	return m_circle.getFillColor();
}


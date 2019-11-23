#include "Triangle.h"
#include "Utills.h"



Triangle::Triangle(int x, int y, bool first, int up)
{
	m_first = first;
	if (m_first)
		creatFirstTriangle(x, y, up);
	else
		creatSecondTriangle(x, y, up);
}

Triangle::~Triangle()
{
}

void Triangle::draw(sf::RenderWindow & window)
{
	window.draw(polygon);
	window.draw(polygon1);
}



void Triangle::setColor(colors color)
{
	if (m_first)
		setColorFirstTriangle(color);
	else
		setColorSecondTriangle(color);
}

void Triangle::setColor2(colors color)
{
	if (color == RED)
		polygon1.setFillColor(sf::Color::Red);
	else if (color == ORANGE)
		polygon1.setFillColor(sf::Color(255, 153, 51));
	else if (color == YELLOW)
		polygon1.setFillColor(sf::Color::Yellow);
	else if (color == GREEN)
		polygon1.setFillColor(sf::Color::Green);
	else if (color == BLUE)
		polygon1.setFillColor(sf::Color::Blue);
	else
		polygon1.setFillColor(sf::Color(255, 102, 178));
}

void Triangle::creatTriangeY(int x, int y)
{
	if (m_first)
	{
		polygon.setPoint(0, sf::Vector2f(x - radius, y + radius));
		polygon.setPoint(1, sf::Vector2f(x, y));
		polygon.setPoint(2, sf::Vector2f(x, y + 2 * radius));
	}
	else
	{
		polygon1.setPoint(0, sf::Vector2f(x, y));
		polygon1.setPoint(1, sf::Vector2f(x + radius, y + radius));
		polygon1.setPoint(2, sf::Vector2f(x, y + 2 * radius));
	}
}

void Triangle::creatTriangeX(int x, int y)
{
	if (m_first)
	{
		polygon.setPoint(0, sf::Vector2f(x - radius, y + radius));
		polygon.setPoint(1, sf::Vector2f(x, y));
		polygon.setPoint(2, sf::Vector2f(x + radius, y + radius));
	}
	else
	{
		polygon1.setPoint(0, sf::Vector2f(x - radius, y + radius));
		polygon1.setPoint(2, sf::Vector2f(x, y + 2 * radius));
		polygon1.setPoint(1, sf::Vector2f(x + radius, y + radius));
	}
}

void Triangle::setColorFirstTriangle(colors color)
{
	if (color == RED)
		polygon.setFillColor(sf::Color::Red);
	else if (color == ORANGE)
		polygon.setFillColor(sf::Color(255, 153, 51));
	else if (color == YELLOW)
		polygon.setFillColor(sf::Color::Yellow);
	else if (color == GREEN)
		polygon.setFillColor(sf::Color::Green);
	else if (color == BLUE)
		polygon.setFillColor(sf::Color::Blue);
	else
		polygon.setFillColor(sf::Color(255, 102, 178));
}

void Triangle::setColorSecondTriangle(colors color)
{
	if (color == RED)
		polygon1.setFillColor(sf::Color::Red);
	else if (color == ORANGE)
		polygon1.setFillColor(sf::Color(255, 153, 51));
	else if (color == YELLOW)
		polygon1.setFillColor(sf::Color::Yellow);
	else if (color == GREEN)
		polygon1.setFillColor(sf::Color::Green);
	else if (color == BLUE)
		polygon1.setFillColor(sf::Color::Blue);
	else
		polygon1.setFillColor(sf::Color(255, 102, 178));
}

void Triangle::creatFirstTriangle(int x, int y, int up)
{
	polygon.setPointCount(3);
	if (up == 1) {
		creatTriangeX(x, y);
		m_middle_point1.x = x - radius;
		m_middle_point1.y = y + radius / 2;
	}
	else
	{
		creatTriangeY(x, y);
		m_middle_point1.x = x - (radius + 5);
		m_middle_point1.y = y + radius;
	}
	setColor(randomColor());
	polygon.setOutlineColor(sf::Color::White);
	polygon.setOutlineThickness(1);
	polygon.setOrigin(x, y);
	polygon.setPosition(x, y);

}

void Triangle::creatSecondTriangle(int x, int y, int up)
{
	polygon1.setPointCount(3);
	setColor2(randomColor());
	if (up == 1) {
		creatTriangeX(x, y);
		m_middle_point2.x = x - radius;
		m_middle_point2.y = y + radius + radius / 2;
	}
	else
	{
		creatTriangeY(x, y);
		m_middle_point2.x = x - 5;
		m_middle_point2.y = y + radius;
	}
	polygon1.setOutlineColor(sf::Color::White);
	polygon1.setOutlineThickness(1);
	polygon1.setOrigin(x, y);
	polygon1.setPosition(x, y);


}

sf::Vector2f Triangle::getLocation() const
{
	return sf::Vector2f();
}

void Triangle::goFindYourFriends(Shapes * shape)
{
	if (m_first && !(this->getMiddlePoint().x == shape->getMiddlePoint().x  && //this is - if shape is not me
		this->getMiddlePoint().y == shape->getMiddlePoint().y))

	{
		if (distanceTwoPoints(m_middle_point1, shape->getMiddlePoint()))
			m_neighbors.push_back(shape);
	}
	if (!m_first && !(this->getMiddlePoint().x == shape->getMiddlePoint().x  && //this is - if shape is not me
		this->getMiddlePoint().y == shape->getMiddlePoint().y))

	{
		if (distanceTwoPoints(m_middle_point2, shape->getMiddlePoint()))
			m_neighbors.push_back(shape);
	}
}

bool Triangle::distanceTwoPoints(sf::Vector2f a, sf::Vector2f b) const
{
	if (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)) < radius + radius / 3)
		return true;
	return false;
}

sf::Vector2f Triangle::getMiddlePoint() const
{
	if (m_first)
		return m_middle_point1;
	return m_middle_point2;
}

sf::Color Triangle::getColor() const
{
	if (m_first)
		return polygon.getFillColor();
	else
		polygon1.getFillColor();
}




#include "Players.h"



Players::Players()
{
}

Players::~Players()
{
}

sf::Color Players::convertColor(colors color) const
{

	if (color == RED)
		return (sf::Color::Red);
	else if (color == ORANGE)
		return(sf::Color(255, 153, 51));
	else if (color == YELLOW)
		return(sf::Color::Yellow);
	else if (color == GREEN)
		return(sf::Color::Green);
	else if (color == BLUE)
		return(sf::Color::Blue);
	else
		return(sf::Color(255, 102, 178));

}



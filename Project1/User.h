#pragma once
#include "Players.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shapes.h"
#include <vector>
#include"Computer.h"
class User:public Players
{
public:
	//gets init place
	User(Shapes *shape);
	~User();

	//goes into neighbors of tneibors to check them as well
	virtual void checkNeighbor(Shapes* it, colors color) override;
	virtual colors getLastColor()const override { return last_color; };

	//does his turn based on the color that was pressed
	void doTurn(colors color, colors c) override;

	//checks if the neighbor exists already
	bool checkIfNei(Shapes *nei);
private:
	std::vector<Shapes*> m_internal_area;
	sf::Vector2f init;
	colors last_color = WHITE;
	colors computer_color;
	

};


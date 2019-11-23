#pragma once
#include <vector>
#include <iostream>
#include "Shapes.h"
#include "Players.h"
#include "Utills.h"
#include "ToolBar.h"

class Board
{
	
public:
	Board();
	//release vector of pointers
	~Board();
	//calculates area of each player
	sf::Vector2f calculateArea();
	//creates the board by rectangles ant triangle
	void createBoard();
	//finds for each shape his neighbors
	void createNeighbors();
	//creates a user player and computer player
	void createPlayers();
	//for restart - erases all the data structurs
	void eraseVectors();
	//draws all the shapes
	void draw(sf::RenderWindow & window);
	//each player does his turn
	void doTurn(colors currentColor);

	bool getEndGame() const{ return m_end_game; };

	double getAreaUser() const{ return m_user_area; };

	double getAreaComputer()const { return m_computer_area; };
	//randoms between vertical and horizantle triangles
	int randomTrangleShape() const;
	//randoms between rectangle and triangle
	int randomShape() const;
	colors getLastColorOfUser() const{ return m_last_color_user; };
	colors getLastColorOfComputer()const { return m_last_color_com; };
	
private:
	std::vector<Shapes*> m_shape;
	std::vector<Players*> m_players;
	std::vector<Shapes*>::iterator it;
	std::vector<Shapes*>::iterator it1;
	colors m_last_color_user = WHITE, m_last_color_com = WHITE;
	float m_user_area = 0, m_computer_area = 0;
	int m_initplayerlocation;
	int m_initcomputerlocation;
	bool m_end_game;
	
	
};


#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "ToolBar.h"
#include <vector>
class GameController
{
public:
	GameController();
	~GameController();
	//start the game
	void run();

	void openWindow();

	//controlles events
	void eventHandler();

	//create toolbar
	void createToolBar();

	//puts in the area of the plears in tool bar
	void setAreaInToolBar();

	//for restart
	void resetGame();

	//creats the baord and tool bar
	void creatGame();


private:
	sf::RenderWindow m_window;
	Board m_board;
	ToolBar m_toolbar;
	sf::Vector2f m_area;
	

};


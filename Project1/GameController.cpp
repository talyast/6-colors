#include "GameController.h"



GameController::GameController()
{
}

GameController::~GameController()
{
}

void GameController::run()
{
	if (!(m_toolbar.getRestart()))
		openWindow();
	if (m_toolbar.getRestart())
		resetGame();

	creatGame();
	while (m_window.isOpen())
	{
		m_window.clear(sf::Color::White);
		if (m_board.getEndGame())
			break;
		m_toolbar.showPlayerTurn(m_window);
		m_toolbar.draw(m_window);
		m_board.draw(m_window);
		m_window.display();
		eventHandler();
	}
}

void GameController::openWindow()
{
	m_window.create(sf::VideoMode(450, 500), "six colors");
}

void GameController::eventHandler()
{
	sf::Event event;
	//change to waitEvent
	while (m_window.pollEvent(event))//every event do somthing
	{
		switch (event.type)//types of events
		{
		case sf::Event::Closed:
			m_window.close();
			exit(EXIT_SUCCESS);
			break;
		case sf::Event::MouseButtonReleased:

			if (event.mouseButton.button == sf::Mouse::Button::Left &&
				m_toolbar.contain(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y })))
			{
				if (m_toolbar.getRestart()) 
					run();
				else if (m_toolbar.getExit())
					m_window.close();
				else
				{
					m_toolbar.showComputerTurn(m_window);
					m_board.doTurn(m_toolbar.getColor());
					m_toolbar.flashComputerColor(m_board.getLastColorOfComputer());
					m_area = m_board.calculateArea();
					setAreaInToolBar();
				}
				break;
			}
		}
	}

}

void GameController::createToolBar()
{
	m_toolbar.create();
}

void GameController::setAreaInToolBar()
{
	m_toolbar.setArea(m_area);
}

void GameController::resetGame()
{
	
	m_toolbar.resetArea();
	m_board.eraseVectors();
	m_toolbar.erase();
	m_toolbar.setBoolRestart();
}

void GameController::creatGame()
{
	createToolBar();
	m_board.createBoard();
	m_board.createNeighbors();
	m_board.createPlayers();
}

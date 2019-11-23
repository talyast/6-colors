#include "Board.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "User.h"
#include "Computer.h"


Board::Board()
{
}

Board::~Board()
{
	for (auto p : m_shape) { delete p; } m_shape.clear();
}

void Board::createBoard()
{
	int num, direction, i, j;
	for (i = 25; i < MAX_SIZE; i += 20)
	{
		for (j = 40; j < MAX_SIZE; j += 20)

		{
			if (j == 40 && i == 405)
			{
				m_shape.push_back(new Rectangle(i, j));
				m_initcomputerlocation = m_shape.size() - 1;
				continue;
			}
			else if (j == 400 && i == 25)
			{
				m_shape.push_back(new Rectangle(i, j));
				m_initplayerlocation = m_shape.size()-1;
				continue;
			}
			else
			{
				num = randomShape();
				if (num == 1)
					m_shape.push_back(new Rectangle(i, j));
				else
				 {
					direction = randomTrangleShape();
					m_shape.push_back(new Triangle(i + radius, j, true, direction));
					m_shape.push_back(new Triangle(i + radius, j, false, direction));
				}
			}


		}

	}
	for (int i = 35; i < MAX_SIZE; i += 20)
		for (int j = 50; j < MAX_SIZE; j += 20)
		{
			num = randomShape();
			if (num == 1)
				m_shape.push_back(new Rectangle(i, j));
			else
			{
				direction = randomTrangleShape();
				m_shape.push_back(new Triangle(i + radius, j, true, direction));
				m_shape.push_back(new Triangle(i + radius, j, false, direction));
			}

		}

}

void Board::createNeighbors()
{
	int size = m_shape.size();
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
			m_shape[i]->goFindYourFriends(m_shape[j]);
	}
}


void Board::createPlayers()
{
	m_players.push_back(new User(m_shape[m_initplayerlocation]));
	m_players.push_back(new  Computer(m_shape[m_initcomputerlocation]));
}

void Board::eraseVectors()
{
	m_shape.clear();
	m_players.clear();
	for (const auto& player : m_players)
		player->clearArea();

}

void Board::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < m_shape.size(); ++i)
		m_shape[i]->draw(window);
}

void Board::doTurn(colors currentColor)
{
	colors c;
	for (const auto &player : m_players)
	{
		if (dynamic_cast<User*>(player))
			m_last_color_user = player->getLastColor();
		else
			m_last_color_com = player->getLastColor();
	}
	for (const auto& player : m_players)
	{
		player->doTurn(currentColor, m_last_color_com);
	}

	for (const auto &player : m_players)
	{
		if (dynamic_cast<User*>(player))
			m_last_color_user = player->getLastColor();
		else
			m_last_color_com = player->getLastColor();

	}

}

int Board::randomShape() const
{
	int shape;
	shape = rand() % 15;
	switch (shape)
	{
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
		return 1;
		break;
	case 14:
		return 2;
		break;
	default:
		return 1;
	}
}
sf::Vector2f Board::calculateArea()
{
	for (auto & player : m_players)
	{
		if (dynamic_cast<User*>(player))
			m_user_area = player->getAreaSize();
		else
			m_computer_area = player->getAreaSize();
	}
	if (m_computer_area >= m_shape.size() / 2 || m_user_area >= m_shape.size() / 2)
	{
		for (const auto& player : m_players)
		{

			player->clearArea();
			m_end_game = true;

		}
	}
	m_user_area /= m_shape.size();
	m_computer_area /= m_shape.size();
	return (sf::Vector2f{ m_user_area,m_computer_area });
}


int Board::randomTrangleShape() const

{
	int shape;
	shape = rand() % 2;
	switch (shape)
	{
	case 0:
		return 1;
		break;
	case 1:
		return 2;
		break;
	default:
		return 2;
	}
}
#include "ToolBar.h"


ToolBar::ToolBar()
{
	createBotton();
	createPlayer();
	createTwoX();
}

ToolBar::~ToolBar()
{
}
void ToolBar::createtext()
{
	userAreaText.setPosition({ 25,450 });
	userAreaText.setFont(font);
	userAreaText.setCharacterSize(20);
	userAreaText.setFillColor(sf::Color(0, 102, 102));
	userAreaText.setStyle(sf::Text::Bold);
	userAreaText.setLetterSpacing(1);
	userAreaText.setString(std::to_string(m_user_area));

	computerAreaText.setPosition({ 340,450 });
	computerAreaText.setFont(font);
	computerAreaText.setCharacterSize(20);
	computerAreaText.setFillColor(sf::Color(0,102,102));
	computerAreaText.setStyle(sf::Text::Bold);
	computerAreaText.setLetterSpacing(1);
	computerAreaText.setString(std::to_string(m_comp_area));
}

void ToolBar::flashComputerColor(colors color)
{
	int index;
	index = a(color);
	m_xSprite_com.setPosition(m_toolBar[index].getPosition());
}

void ToolBar::createBotton()
{
	m_texture.loadFromFile("restart.png");
	m_restartSprite.setPosition(125, 2);
	m_restartSprite.setTexture(m_texture, false);

	m_texture_exit.loadFromFile("close.png");
	m_exitSprite.setPosition(275, 2);
	m_exitSprite.setTexture(m_texture_exit, false);
}

void ToolBar::createTwoX()
{
	m_texture_x.loadFromFile("x.png");
	m_xSprite.setPosition(700, 700);
	m_xSprite.setTexture(m_texture_x, false);

	m_texture_x_com.loadFromFile("x.png");
	m_xSprite_com.setPosition(700, 700);
	m_xSprite_com.setTexture(m_texture_x_com, false);

	font.loadFromFile("images/Remember.ttf");
	createtext();
}

int ToolBar::a(colors c)
{
	if (c == RED)
		return (0);
	else if (c == ORANGE)
		return(1);
	else if (c == YELLOW)
		return(2);
	else if (c == GREEN)
		return(3);
	else if (c == BLUE)
		return(4);
	else if (c == PINK)
		return(5);
	else
		;
}
void ToolBar::create()
{
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(25, 25));
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(120, 450);
	m_toolBar.push_back(rectangle);

	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(25, 25));
	rectangle2.setFillColor(sf::Color(255, 153, 51));
	rectangle2.setPosition(155, 450);
	m_toolBar.push_back(rectangle2);

	sf::RectangleShape rectangle3;
	rectangle3.setSize(sf::Vector2f(25, 25));
	rectangle3.setFillColor(sf::Color::Yellow);
	rectangle3.setPosition(190, 450);
	m_toolBar.push_back(rectangle3);

	sf::RectangleShape rectangle4;
	rectangle4.setSize(sf::Vector2f(25, 25));
	rectangle4.setFillColor(sf::Color::Green);
	rectangle4.setPosition(225, 450);
	m_toolBar.push_back(rectangle4);

	sf::RectangleShape rectangle5;
	rectangle5.setSize(sf::Vector2f(25, 25));
	rectangle5.setFillColor(sf::Color::Blue);
	rectangle5.setPosition(260, 450);
	m_toolBar.push_back(rectangle5);

	sf::RectangleShape rectangle6;
	rectangle6.setSize(sf::Vector2f(25, 25));
	rectangle6.setFillColor(sf::Color(255, 102, 178));
	rectangle6.setPosition(295, 450);
	m_toolBar.push_back(rectangle6);

	
}

void ToolBar::draw(sf::RenderWindow & window)
{
	window.draw(userAreaText);
	window.draw(computerAreaText);
	for (const auto &rec : m_toolBar)
		window.draw(rec);
	window.draw(m_restartSprite);
	window.draw(m_exitSprite);
	window.draw(m_xSprite_com);
	window.draw(m_xSprite);
}
void ToolBar::erase()
{
	m_toolBar.clear();
}
bool ToolBar::contain(sf::Vector2f place)
{
	int size = m_toolBar.size();

	for (int i = 0; i < size; ++i)
		if (m_toolBar[i].getGlobalBounds().contains(place))
		{
			
			m_xSprite.setPosition(m_toolBar[i].getPosition());
			current_color = checkColor(i);
			return true;
		}
	if (m_restartSprite.getGlobalBounds().contains(place))
	{
		m_xSprite.setPosition(800,800);
		m_xSprite_com.setPosition(800, 800);
		m_restart = true;
		return true;
	}

	if (m_exitSprite.getGlobalBounds().contains(place))
	{
		m_exit = true;
		return true;
	}

	return false;
}

colors ToolBar::checkColor(int i)
{
	switch (i)
	{
	case 0:
		return RED;
		break;
	case 1:
		return ORANGE;
		break;
	case 2:
		return YELLOW;
		break;
	case 3:
		return GREEN;
		break;
	case 4:
		return BLUE;
		break;
	case 5:
		return PINK;
		break;
	default:
		break;
	}
}

void ToolBar::setArea(sf::Vector2f area)
{
	m_user_area = area.x;
	m_comp_area = area.y;

	userAreaText.setString(std::to_string(m_user_area));
	computerAreaText.setString(std::to_string(m_comp_area));
}

void ToolBar::resetArea()
{
	 m_user_area=0;
	m_comp_area=0;

	userAreaText.setString(std::to_string(m_user_area));
	computerAreaText.setString(std::to_string(m_comp_area));
}

void ToolBar::createPlayer()
{
	m_texturplayer.loadFromFile("user.png");
	m_playersprite.setPosition(200, 0);
	m_playersprite.setTexture(m_texturplayer, false);

	m_texturcomputer.loadFromFile("computer.png");
	m_computersprite.setPosition(200, 0);
	m_computersprite.setTexture(m_texturcomputer, false);
}

void ToolBar::showPlayerTurn(sf::RenderWindow & window)
{
	window.draw(m_playersprite);
}

void ToolBar::showComputerTurn(sf::RenderWindow & window)
{
	window.draw(m_computersprite);
	window.display();
	sf::sleep(time);
}
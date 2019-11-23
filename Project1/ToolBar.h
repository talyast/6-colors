#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Utills.h"

class ToolBar
{
public:
	ToolBar();
	~ToolBar();
	//checks the color that was chosen
	colors checkColor(int i);

	colors getColor() const { return current_color; };

	//create the bottons of colors
	void create();

	void draw(sf::RenderWindow & window);
	//erase the vector
	void erase();
	void setBoolRestart() { m_restart = false; };
	//inpimates the area of each player
	void setArea(sf::Vector2f area);
	//initionalize to zero
	void resetArea();
	//puts the players images
	void createPlayer();
	void createtext();
	void flashComputerColor(colors color);
	//shoe image of user
	void showPlayerTurn(sf::RenderWindow & window);
	//show image of computer
	void showComputerTurn(sf::RenderWindow & window);
	// creates the restart and exit bottons
	void createBotton();
	//x on colors that can not be chosen
	void createTwoX();
	//checks if the mouse botton is in the realm of a shape
	bool contain(sf::Vector2f place);
	bool getRestart() const { return m_restart; };
	bool getExit()const { return m_exit; };
	int a(colors c);


private:
	colors current_color;
	std::vector< sf::RectangleShape >m_toolBar;
	sf::Texture  m_texture;
	sf::Texture  m_texturplayer;
	sf::Texture  m_texturcomputer;
	sf::Texture m_texture_exit;
	sf::Texture m_texture_x;
	sf::Texture m_texture_x_com;
	sf::Sprite m_playersprite;
	sf::Sprite m_computersprite;
	sf::Sprite m_restartSprite;
	sf::Sprite m_exitSprite;
	sf::Sprite m_xSprite;
	sf::Sprite m_xSprite_com;
	sf::Font font;
	sf::Text userAreaText, computerAreaText;
	bool m_restart, m_exit;
	float m_user_area;
	float m_comp_area;
	sf::Time time = sf::seconds(0.1);
	
};



#include"engine.h"
#include<string>
#include<iostream>
#include<SFML/Audio.hpp>
void Engine::draw(int doroga,bool &stolk,bool ant,int kok2,int hp,float immortal)
{
	Font font;
	font.loadFromFile("EightBits.ttf");
	m_Window.clear(Color::White);
	m_Window.draw(m_BackgroundSprite);
	m_Window.draw(m_MyCar.getSprite());
	for (int i = 0; i < m_Enemy.size()  && m_Enemy.size() >= 1; ++i) {
		m_Window.draw(m_Enemy[i].getSprite());
	}
	for (int i = 0; i < m_explose.size() && m_explose.size() >= 1; ++i) {
		m_Window.draw(m_explose[i].getSprite());
	}
	int y = 0;
	for (int i = 0; i < hp; i++)
	{
		m_Sprite1.setPosition(70+50*i, 5);
		m_Window.draw(m_Sprite1);
	}
	std::string s2;
	if (kok2 < 10 )
	{
		 s2 = "Time " + std::to_string(kok2 / 60) + ":0" + std::to_string(kok2);
	}
	else
	{
		if (kok2 >= 10 ) {
			 s2 = "Time " + std::to_string(kok2 / 60) + ":" + std::to_string(kok2);
		}
	}
	Text text2(s2, font);
	text2.setCharacterSize(75);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(75, 40);
	m_Window.draw(text2);
	m_Window.display();
	stolk = false;
}


#include"engine.h"
#include<string>
#include<iostream>
#include<SFML/Audio.hpp>
void Engine::draw(int doroga,bool &stolk,bool ant,int kok2,int hp,float immortal)
{
	std::string s1=std::to_string(doroga);
	Font font;
	font.loadFromFile("ArialRegular.ttf");
	Text text(s1, font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setPosition(300, 300);
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
	m_Window.draw(text);
	std::string s2 = std::to_string(stolk);
	Text text1(s2, font);
	text1.setCharacterSize(30);
	text1.setStyle(sf::Text::Bold);
	text1.setFillColor(sf::Color::White);
	text1.setPosition(300, 400);
	m_Window.draw(text1);
	s2 = std::to_string(kok2)+":"+ std::to_string(m_Enemy.size())+":"+std::to_string(ant)+":"+std::to_string(immortal);
	Text text2(s2, font);
	text2.setCharacterSize(30);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(400, 400);
	m_Window.draw(text2);
	m_Window.display();
	stolk = false;
}

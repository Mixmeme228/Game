
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
	for (int i = 0; i < m_Bullet.size() && m_Bullet.size() >= 1; ++i) {
		m_Window.draw(m_Bullet[i].getSprite());
	}
	for (int i = 0; i < m_explose.size() && m_explose.size() >= 1; ++i) {
		m_Window.draw(m_explose[i].getSprite());
	}
	for (int i = 0; i < m_Coin.size() && m_Coin.size() >= 1; ++i) {
		m_Window.draw(m_Coin[i].getSprite());
	}
	int y = 0;
	for (int i = 0; i < hp; i++)
	{
		m_Sprite1.setPosition(70+50*i, 5);
		m_Window.draw(m_Sprite1);
	}
	std::string s2;
	if ((kok2 - (kok2 / 60) * 60) < 10  )
	{
		 s2 = "Time " + std::to_string(kok2 / 60) + ":0" + std::to_string(kok2-(kok2/60)*60);
	}
	else
	{
		if ((kok2 - (kok2 / 60) * 60) >= 10 ) {
			 s2 = "Time " + std::to_string(kok2 / 60) + ":" + std::to_string(kok2- (kok2 / 60) * 60);
		}
	}
	std::string s3;
	s3 = "Score: " + std::to_string(Score);
	Text text3(s3, font);
	fps++;
	std::string fpsss;
	fpsss = "Fps:"+ std::to_string(int(fp));
	if (gohst1 - fpss >= 1000)
	{
		fp = fps;
		fps = 0;
		fpss = gohst1;
	}
	Text text4(fpsss, font);
	text4.setCharacterSize(75);
	text4.setStyle(sf::Text::Bold);
	text4.setFillColor(sf::Color::White);
	text4.setPosition(10, 630);
	m_Window.draw(text4);
	text3.setCharacterSize(75);
	text3.setStyle(sf::Text::Bold);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(75, 90);
	m_Window.draw(text3);
	Text text2(s2, font);
	text2.setCharacterSize(75);
	text2.setStyle(sf::Text::Bold);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(75, 40);
	m_Window.draw(text2);
	stolk = false;
}

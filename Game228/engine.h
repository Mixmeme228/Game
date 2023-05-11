#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"MyCar.h"
#include"Enemy.h"
#include"explose.h"
#include"Bullet.h"
#include"Coin.h"
#include<ctime>
#include<vector>
#include <random>
#include"string"
#include<fstream>
using namespace sf;
class Engine
{
public:
	Texture Logo_Texture;
	Sprite Logo_Sprite;
	Texture menuTexture1;
	Texture menuTexture1_1;
	Texture menuTexture2;
	Texture menuTexture2_1;
	Sprite menu2;
	Sprite menu1;
	Sprite m_chells;
	Texture m_chellt;
	Sprite m_strelkas;
	Texture m_strelkat;
	Engine();
	void start();
	bool pause;
	bool life;
	std::vector <Enemy> m_Enemy;
	std::vector <Coin> m_Coin;
	std::vector <Bullet> m_Bullet;
	Sprite m_Sprite1;
	Texture m_Texture1;
	Sprite m_GohstCars;
	Texture m_GohstCart;
	Sprite m_Sprite2;
	Texture m_Texture2;
	Sprite m_Sprite3;
	Texture m_Texture3;
	Sprite m_Sprite4;
	Texture m_Texture4;
	Sprite m_Sprite5;
	Texture m_Texture5;
	std::vector <explose> m_explose;
private:
	Cursor cursor1;
	Cursor hand;
	Clock clock2;
	int gg,fps;
	Music gosht;
	Music Menu_music;
	Music Menu_music1;
	Music Menu_music3;
	Music Menu_music2;
	bool menu_music;
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	MyCar m_MyCar;
	Coin Coin1;
	long Score;
	bool Score_shet;
	bool shet, zast,sound_menu, sound_menu1;
	Texture textur;
	Enemy Enemy1;
	explose explose1;
	Bullet bullet1;
	float dtAsSeconds_1;
	float fpss = 0, gohst1 = 0, fp = 0;
	std::string fpsss;
	SoundBuffer buffer;
	Sound sound_pause;
	SoundBuffer buffer1;
	Sound sound_focus;
	SoundBuffer buffer2;
	Sound sound_click;
	SoundBuffer buffer3;
	Sound sound_explose;
	SoundBuffer buffer4;
	Sound sound_shoot1;
	SoundBuffer buffer5;
	Sound sound_coin;
	std::vector <int> g;
	float spawn[4];
	void addBullet()
	{
		bullet1.m_Position = m_MyCar.m_Position;
		bullet1.m_Position.x += 47;
		bullet1.m_Position.y -= 40;
		bullet1.m_Speed = 8.5;
		m_Bullet.push_back(bullet1);
	}
	void game_over(float x,float y,std::vector <Enemy> & m_Enemy)
	{
		
		Menu_music3.play();
		Menu_music3.setVolume(20);
		Menu_music.stop();
		Menu_music1.stop();
		Menu_music2.stop();
		float time = 0;
		m_Texture5.loadFromFile("explose.png");
		m_Sprite5.setTexture(m_Texture5);
		m_Sprite5.setTextureRect(IntRect(0, 30, 270, 290));
		m_Sprite5.setScale(0.8f, 0.8f);
		m_Sprite5.setPosition(x, y);
		m_Texture3.loadFromFile("game over.png");
		m_Sprite3.setTexture(m_Texture3);
		m_Sprite3.setTextureRect(IntRect(40, 75, 160, 40));
		m_Texture4.loadFromFile("game over.png");
		m_Sprite4.setTexture(m_Texture4);
		m_Sprite4.setTextureRect(IntRect(40, 120, 160, 40));
		Clock clock;
		int dtMilliSeconds = 0;
		int i=0, j=1280;
		sf::Event event;
		Font font;
		font.loadFromFile("EightBits.ttf");
		std::string s2 = "Press Enter";
		Text text2(s2, font);
		text2.setCharacterSize(60);
		text2.setStyle(sf::Text::Bold);
		text2.setFillColor(sf::Color::Black);
		text2.setPosition(550, 350);
		std::string s3 = "Is he died at the end of the Drive?";
		Text text3(s3, font);
		text3.setCharacterSize(60);
		text3.setStyle(sf::Text::Bold);
		text3.setFillColor(sf::Color::Black);
		text3.setPosition(335, 450);
		while (life)
		{
			Time dt = clock.getElapsedTime();
			Time dt2 = clock.getElapsedTime();
			while (m_Window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					m_Window.close();
					life = false;
				}
			}
			dtMilliSeconds = dt.asMilliseconds();
			float dtSeconds = dt.asSeconds();
			if (i <= 475)
			{
				i += 4;
			}
			if (j >= 650)
			{
				j -= 4.5;
			}
			m_Window.clear(Color::White);
			m_Window.draw(m_BackgroundSprite);
			m_Sprite3.setPosition(i, 300);
			m_Sprite4.setPosition(j, 300);
			m_Window.draw(m_Sprite3);
			m_Window.draw(m_Sprite4);
			m_Window.draw(m_Sprite5);
			if ((j >= 650 && i <= 475)) {
				dont_move(dtMilliSeconds, 0, m_Sprite5);
				for (int i = 0; i < m_Enemy.size() && m_Enemy.size() >= 1; ++i) {
					addexplose(m_Enemy[i], dtMilliSeconds);
					m_Enemy.erase(m_Enemy.begin() + i);
				}
				for (int i = 0; i < m_explose.size() && m_explose.size() >= 1 && !m_explose.empty(); ++i)
				{
					m_explose[i].update(dtSeconds);
					m_explose[i].dont_move(dtMilliSeconds);
					if (dtMilliSeconds - m_explose[i].time > 750)
					{
						if (!m_explose.empty()) {
							m_explose.erase(m_explose.begin() + i);
						}
					}
				}
			}
			for (int i = 0; i < m_explose.size() && m_explose.size() >= 1; ++i) {
				m_Window.draw(m_explose[i].getSprite());
			}
			if (!(j >= 650 && i <= 475)) {
				m_Window.draw(text3);
				if ( (dtMilliSeconds <= 1000))
				{
					m_Window.draw(text2);
				}
				if ((dtMilliSeconds >= 2000))
				{
					clock.restart();
				}
			}
			m_Window.display();
			if (Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				m_MyCar.m_Texture.loadFromFile("3.png");
				m_MyCar.m_Sprite.setTexture(m_MyCar.m_Texture);
				m_MyCar.m_Sprite.setScale(0.2f, 0.2f);
				m_MyCar.m_Position.x = 550;
				m_MyCar.m_Position.y = 500;
				menu2.setPosition(487.5, 390);
				m_Coin.clear();
				m_explose.clear();
				m_Bullet.clear();
				m_Window.clear();
				m_Window.setFramerateLimit(0);
				fpss = 0;
				menu_music = true;
				clock2.restart();
				gohst1 = 0;
				gg = 0;
				Menu_music3.stop();
				life = false;
			}
		}
	}
	void dont_move(float dtMilliSeconds, float time, Sprite &m_Sprite);
	void polnoegavno()
	{
		m_Texture1.loadFromFile("4.png");
		m_Sprite1.setTexture(m_Texture1);
		m_Sprite1.setScale(0.1f, 0.1f);
	}
	void pause2()
	{
		m_Texture2.loadFromFile("button.png");
		m_Sprite2.setTexture(m_Texture2);
		m_Sprite2.setPosition(450, 300);
		buffer.loadFromFile("032206ca9e2b5e8.ogg");
		sound_pause.setBuffer(buffer);
	}
	void rasp()
	{
		for (int i = 0; i < 7; i++)
		{
			if (g[i] == 7)
			{
				for (int j = i + 1; j < g.size(); j++)
				{
					if (j == (i + 1))
					{
						g[j] = g[i] - 1;
					}
					else
					{
						g[j] = g[j - 1] - 1;
					}
				}
				for (int j = i -1; j >=0; j--)
				{
					if (j == (i - 1))
					{
						g[j] = g[i] - 1;
					}
					else
					{
						g[j] = g[j + 1] - 1;
					}
				}
			}
		}
	}
	void addexplose(Enemy Enemy1,float g)
	{
		explose1.time = g;
		explose1.m_Position.y = Enemy1.m_Position.y;
		explose1.m_Position.x = Enemy1.m_Position.x-15;
		explose1.m_Speed = 6;
		m_explose.push_back(explose1);
	}
	bool stolk;
	Music music;
	void sound_shoot()
	{
		sound_shoot1.play();
	}
	void sound1()
	{
		sound_explose.play(); 
	}
	void addEnemy()
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(3, 6); 
		for (int i = 0; i < dist6(rng); i++) {
			int q;
			srand(i+1);
			int k = 1;
			std::uniform_int_distribution<std::mt19937::result_type> m(0, 6);
			std::uniform_int_distribution<std::mt19937::result_type> m1(0, 6);
			if (g[m(rng)] >= g[m1(rng)] && m(rng) != m1(rng))
			{
				k = m(rng) + 1;
			}
			else {
				k = m1(rng) + 1;
			}
			switch (k)
			{
			case 1:
				q = 100;
				break;
			case 2:
				q = 250;
				break;
			case 3:
				q = 400;
				break;
			case 4:
				q = 550;
				break;
			case 5:
				q = 700;
				break;
			case 6:
				q = 850;
				break;
			case 7:
				q = 1000;
				break;
			}
			srand(0);
			std::uniform_int_distribution<std::mt19937::result_type> m2(0, 100);
			int value = m2(rng);
			for (int i = 0; i < dist6(rng); ++i)
			{
			value = (value * 73129 + 95121) % 1000;
			}
			Enemy1.m_Position.y = -200-value;
			Enemy1.m_Position.x = q;
			Enemy1.m_Speed = 6;
			m_Enemy.push_back(Enemy1);
			std::uniform_int_distribution<std::mt19937::result_type> dist(1, 10);
			if (dist(rng)>=9) {
				m_Enemy.back().stoika = true;
				m_Enemy.back().m_Sprite.setTexture(textur);
			}
		}
		}
	void sound2()
	{
		sound_coin.play();
	}
	void addCoin()
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 4);
		for (int i = 0; i < dist6(rng); i++) {
			int q;
			srand(i + 1);
			int k = 1;
			std::uniform_int_distribution<std::mt19937::result_type> m(0, 6);
			std::uniform_int_distribution<std::mt19937::result_type> m1(0, 6);
			if (g[m(rng)] <= g[m1(rng)] && m(rng) != m1(rng))
			{
				k = m(rng) + 1;
			}
			else {
				k = m1(rng) + 1;
			}
			switch (k)
			{
			case 1:
				q = 100;
				break;
			case 2:
				q = 250;
				break;
			case 3:
				q = 400;
				break;
			case 4:
				q = 550;
				break;
			case 5:
				q = 700;
				break;
			case 6:
				q = 850;
				break;
			case 7:
				q = 1000;
				break;
			}
			srand(0);
			std::uniform_int_distribution<std::mt19937::result_type> m2(0, 100);
			int value = m2(rng);
			for (int i = 0; i < dist6(rng); ++i)
			{
				value = (value * 73129 + 95121) % 1000;
			}
			Coin1.m_Position.y = -200 - value;
			Coin1.m_Position.x = q+30;
			Coin1.m_Speed = 6;
			m_Coin.push_back(Coin1);
		}
	}
	void input(int &doroga,bool&ant);
	void update(float dtAsSeconds, float dtMilliSeconds,float &immortal,int& hp,bool& ant2);
	void draw(int doroga,bool &stolk,bool ant,int kok2,int hp,float immortal);
};

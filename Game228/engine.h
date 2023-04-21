#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"MyCar.h"
#include"Enemy.h"
#include"explose.h"
#include<ctime>
#include<vector>
#include <random>
using namespace sf;
class Engine
{
public:
	Engine();
	void start();
	bool pause;
	std::vector <Enemy> m_Enemy;
	Sprite m_Sprite1;
	Texture m_Texture1;
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
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	MyCar m_MyCar;
	Enemy Enemy1;
	explose explose1;
	SoundBuffer buffer;
	Sound sound_pause;
	std::vector <int> g;
	float spawn[4];
	void game_over(float x,float y)
	{
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
		float dtMilliSeconds = 0;
		int i=0, j=1280;
		sf::Event event;
		while (m_Window.isOpen())
		{
			Time dt = clock.getElapsedTime();
			while (m_Window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_Window.close();
			}
			dtMilliSeconds = dt.asMilliseconds();
			dont_move(dtMilliSeconds,time,m_Sprite5);
			if (i <= 400)
			{
				i += 2;
			}
			if (j >= 600)
			{
				j -= 2.5;
			}
			m_Window.clear(Color::White);
			m_Window.draw(m_BackgroundSprite);
			m_Sprite3.setPosition(i, 300);
			m_Sprite4.setPosition(j, 300);
			m_Window.draw(m_Sprite3);
			m_Window.draw(m_Sprite4);
			m_Window.draw(m_Sprite5);
			m_Window.display();
			if (Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				m_Window.close();
				break;
			}
		}
	}
	void dont_move(float dtMilliSeconds,float time,Sprite &m_Sprite)
	{
		if (dtMilliSeconds - time >= 50)
		{
			m_Sprite.setTextureRect(IntRect(IntRect(310, 0, 270, 290)));
			if (dtMilliSeconds - time >= 100)
			{
				m_Sprite.setTextureRect(IntRect(IntRect(620, 0, 270, 290)));
				if (dtMilliSeconds - time >= 150)
				{
					m_Sprite.setTextureRect(IntRect(IntRect(930, 0, 270, 290)));
					if (dtMilliSeconds - time >= 200)
					{
						m_Sprite.setTextureRect(IntRect(IntRect(0, 320, 270, 290)));
						if (dtMilliSeconds - time >= 250)
						{
							m_Sprite.setTextureRect(IntRect(IntRect(310, 320, 270, 290)));
							if (dtMilliSeconds - time >= 300)
							{
								m_Sprite.setTextureRect(IntRect(IntRect(620, 320, 270, 290)));
								if (dtMilliSeconds - time >= 350)
								{
									m_Sprite.setTextureRect(IntRect(IntRect(930, 320, 270, 290)));
									if (dtMilliSeconds - time >= 400)
									{
										m_Sprite.setTextureRect(IntRect(IntRect(0, 640, 270, 290)));
										if (dtMilliSeconds - time >= 450)
										{
											m_Sprite.setTextureRect(IntRect(IntRect(310, 640, 270, 290)));
											if (dtMilliSeconds - time >= 500)
											{
												m_Sprite.setTextureRect(IntRect(IntRect(620, 640, 270, 290)));
												if (dtMilliSeconds - time >= 550)
												{
													m_Sprite.setTextureRect(IntRect(IntRect(930, 640, 270, 290)));
													if (dtMilliSeconds - time >= 600)
													{
														m_Sprite.setTextureRect(IntRect(IntRect(0, 960, 270, 290)));
														if (dtMilliSeconds - time >= 650)
														{
															m_Sprite.setTextureRect(IntRect(IntRect(310, 960, 270, 290)));
															if (dtMilliSeconds - time >= 700)
															{
																m_Sprite.setTextureRect(IntRect(IntRect(620, 960, 270, 290)));
																if (dtMilliSeconds - time >= 750)
																{
																	m_Sprite.setTextureRect(IntRect(IntRect(930, 960, 270, 290)));
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
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
	void sound1()
	{
		music.play();
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
		}
		}
	void input(int &doroga,bool&ant);
	void update(float dtAsSeconds, float dtMilliSeconds,float &immortal,int& hp,bool& ant2);
	void draw(int doroga,bool &stolk,bool ant,int kok2,int hp,float immortal);
};

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
	std::vector <explose> m_explose;
private:
	RenderWindow m_Window;
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;
	MyCar m_MyCar;
	Enemy Enemy1;
	explose explose1;
	std::vector <int> g;
	float spawn[4];
	void polnoegavno()
	{
		m_Texture1.loadFromFile("4.png");
		m_Sprite1.setTexture(m_Texture1);
		m_Sprite1.setScale(0.1f, 0.1f);
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
	void addexplose(Enemy Enemy1,int g)
	{
		explose1.time = g;
		explose1.m_Position.y = Enemy1.m_Position.y;
		explose1.m_Position.x = Enemy1.m_Position.x;
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
	void update(float dtAsSeconds,bool &stolk,float &immortal,int& hp,bool& ant2);
	void draw(int doroga,bool &stolk,bool ant,int kok2,int hp,float immortal);
};

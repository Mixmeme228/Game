#include"engine.h"
#include"Enemy.h"
#include<SFML/Audio.hpp>
#include<iostream>
#include<vector>
void Engine::input(int &doroga,bool &ant)
{
	if (Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_MyCar.moveLeft(doroga);
	}
	else
	{
		m_MyCar.stopLeft();
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_MyCar.moveRight(doroga);
	}
	else
	{
		m_MyCar.stopRight();
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_MyCar.moveUp();
	}
	else
	{
		m_MyCar.stopUp();
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_MyCar.moveDown();
	}
	else
	{
		m_MyCar.stopDown();
	}
	if (Keyboard::isKeyPressed(sf::Keyboard::Space) && ant)
	{
		if (Score - 500 >= 0)
		{
			addBullet();
			sound_shoot();
			Score -= 500;
			ant = false;
		}
	}
	else
	{
		if (!Keyboard::isKeyPressed(sf::Keyboard::Space))
			ant = true;
	}
	switch (doroga)
	{
	case 100:
		g[0] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 0)
			{
				g[i] = false;
			}
		}
		break;
	case 250:
		g[1] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 1)
			{
				g[i] = false;
			}
		}
		break;
	case 400:
		g[2] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 2)
			{
				g[i] = false;
			}
		}
		break;
	case 550:
		g[3] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 3)
			{
				g[i] = false;
			}
		}
		break;
	case 700:
		g[4] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 4)
			{
				g[i] = false;
			}
		}
		break;
	case 850:
		g[5] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 5)
			{
				g[i] = false;
			}
		}
		break;

	case 1000:
		g[6] = 7;
		for (int i = 0; i < 7; i++)
		{
			if (i != 6)
			{
				g[i] = false;
			}
		}
		break;
	}
	rasp();
}

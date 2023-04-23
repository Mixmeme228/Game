#pragma once
#include<SFML/Graphics.hpp>
#include <random>
using namespace sf;
class Enemy
{
private:
	Sprite m_Sprite;
	Texture m_Texture;
	bool up;
	bool down;
public:
	Enemy();
	float m_Speed;
	int line;
	int time;
	Vector2f m_Position;
	Sprite getSprite();
	void move(float dt)
	{
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 4001);
		if (m_Position.y < 720)
		{
			m_Position.y += 400*dt;
		}
		if (dist6(rng) == 1000)
		{
			if (m_Position.x != 100)
			{
				m_Position.x -= 150;
			}
		}
		if (dist6(rng) == 2000)
		{
			if (m_Position.x != 1000)
			{
				m_Position.x += 150;
			}
		}
	}
	bool stolke;
	void update(float elapsedTime)
	{
		m_Sprite.setPosition(m_Position);
	};
};

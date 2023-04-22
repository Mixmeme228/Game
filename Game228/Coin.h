#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include <random>
using namespace sf;
class Coin
{
public:
	Sprite m_Sprite;
	Texture m_Texture;
	Coin();
	float m_Speed;
	float time;
	Vector2f m_Position;
	Sprite getSprite();
	void move()
	{
		if (m_Position.y < 720)
		{
			m_Position.y += 0.6 + m_Speed;
		}
	}
	void update(float elapsedTime)
	{
		m_Sprite.setPosition(m_Position);
	}
};
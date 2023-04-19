#pragma once
#include<SFML/Graphics.hpp>
#include <random>
using namespace sf;
class explose
{
private:
	Sprite m_Sprite;
	Texture m_Texture;
public:
	explose();
	float m_Speed;
	int time;
	Vector2f m_Position;
	Sprite getSprite();
	void move()
	{
		if (m_Position.y < 720)
		{
			m_Position.y += 0.6 + m_Speed;
		}
	}
	bool stolke;
	void update(float elapsedTime)
	{
		m_Sprite.setPosition(m_Position);
	};
};


#include"Enemy.h"
#include"engine.h"
#include<ctime>
Enemy::Enemy()
{
	m_Texture.loadFromFile("Enemy.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(0.2f, 0.2f);
	m_Position.x = 0;
	m_Position.y = -200;
	bool up = true;
	bool down = false;
	bool stolke = false;
}
Sprite Enemy::getSprite()
{
	return m_Sprite;
}

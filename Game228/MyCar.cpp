#include "MyCar.h"
#include"engine.h"
#include"list.h"
MyCar::MyCar()
{
	globallist.addNode();
	m_Speed = 100;
	m_Speed1 = 8;
	m_Texture.loadFromFile("3.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(0.2f, 0.2f);
	m_Position.x = 550;
	m_Position.y = 500;
}
Sprite MyCar::getSprite()
{
	return m_Sprite;
}
bool flag = false,flag2=false;
void MyCar::moveLeft(int & doroga)
{
	m_RightPressed = true;
	m_LeftPressed = true;
	if ( m_Position.x >= 0&& !flag)
	{
		if (globallist.Begin->prev != NULL)
		{
			globallist.Begin = globallist.Begin->prev;
			m_Position.x = globallist.Begin->x;
			flag = true;
			doroga= globallist.Begin->x;
		}
	}
}
void MyCar::moveRight(int & doroga)
{
	m_RightPressed = true;
	m_LeftPressed = true;
	if (m_Position.x- m_Speed <= 1280 - 280 && !flag2)
	{
		if (globallist.Begin->next != NULL)
		{
			globallist.Begin = globallist.Begin->next;
			m_Position.x = globallist.Begin->x;
			flag2 = true;
			doroga= globallist.Begin->x;
		}
	}
}
void MyCar::stopRight()
{
	if (m_LeftPressed)
	{
		flag2 = false;
	}
}
void MyCar::stopLeft()
{
	if ( m_RightPressed)
	{
		flag = false;
	}
}
void MyCar::moveUp()
{
	m_UpPressed = false;
}
void MyCar::stopUp()
{
	m_UpPressed = true;
}
void MyCar::moveDown()
{
	m_DownPressed = false;
}
void MyCar::stopDown()
{
	m_DownPressed = true;
}
void MyCar::update(float elapsedTime,float dtAsSeconds_1)
{
	if (m_UpPressed&& m_Position.y<=568)
	{
		m_Position.y += 500* dtAsSeconds_1;
	}
	if (m_DownPressed &&m_Position.y >= 0)
	{
		m_Position.y -= 500* dtAsSeconds_1;
	}
	m_Sprite.setPosition(m_Position);
}

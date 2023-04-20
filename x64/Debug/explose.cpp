#include"explose.h"
#include"engine.h"
#include<ctime>
explose::explose()
{
	m_Texture.loadFromFile("2.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(0.2f, 0.2f);
	m_Position.x = 0;
	m_Position.y = -200;
}
Sprite explose::getSprite()
{
	return m_Sprite;
}
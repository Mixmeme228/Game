#include"explose.h"
#include"engine.h"
#include<ctime>
explose::explose()
{
	m_Texture.loadFromFile("explose.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setTextureRect(IntRect(0,30,270,290));
	m_Sprite.setScale(0.8f, 0.8f);
	m_Position.x = 500;
	m_Position.y = 500;
}
Sprite explose::getSprite()
{
	return m_Sprite;
}
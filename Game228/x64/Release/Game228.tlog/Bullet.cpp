#include"Bullet.h"
#include"engine.h"
#include<vector>
Bullet::Bullet()
{
	m_Texture.loadFromFile("bullet.png");
	m_Sprite.setTexture(m_Texture);
}
Sprite Bullet::getSprite()
{
	return m_Sprite;
}
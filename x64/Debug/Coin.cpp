#include "Coin.h"
#include "engine.h"
Coin::Coin()
{
	m_Texture.loadFromFile("coin.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(0.2f, 0.2f);
}
Sprite Coin::getSprite()
{
	return m_Sprite;
}
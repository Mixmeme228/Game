#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class vrag
{
private:
	Vector2f m_Position;
	Sprite m_Sprite;
	Texture m_Texture;
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_Space;
	float m_Speed;
	float m_Jump;
public:
	MyCar();
	Sprite getSprite();
	void moveLeft();
	void moveRight();
	void space();
	void offspace();
	void stopLeft();
	void stopRight();
	void update(float elapsedTime);
};
#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
using namespace sf;
class MyCar
{
private:
	float m_Speed;
	float m_Speed1;
public:
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_DownPressed;
	Sprite m_Sprite;
	float time;
	Texture m_Texture;
	MyCar();
	Vector2f m_Position;
	Sprite getSprite();
	void moveLeft(int &doroga);
	void moveRight(int &doroga);
	void stopLeft();
	void stopRight();
	void moveUp();
	void moveDown();
	void stopUp();
	void stopDown();
	void update(float elapsedTime,float size);
};
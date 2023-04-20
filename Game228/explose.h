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
	void move(float dtMilliSeconds)
	{
		if (m_Position.y < 720)
		{
			m_Position.y += 0.6 + m_Speed;
		}
		if (dtMilliSeconds - time >= 50)
		{
			m_Sprite.setTextureRect(IntRect(IntRect(310, 0, 270, 290)));
		if (dtMilliSeconds - time >= 100)
			{
				m_Sprite.setTextureRect(IntRect(IntRect(620, 0, 270, 290)));
				if (dtMilliSeconds - time >= 150)
				{
					m_Sprite.setTextureRect(IntRect(IntRect(930, 0, 270, 290)));
					if (dtMilliSeconds - time >= 200)
					{
						m_Sprite.setTextureRect(IntRect(IntRect(0, 320, 270, 290)));
						if (dtMilliSeconds - time >= 250)
						{
							m_Sprite.setTextureRect(IntRect(IntRect(310, 320, 270, 290)));
							if (dtMilliSeconds - time >= 300)
							{
								m_Sprite.setTextureRect(IntRect(IntRect(620, 320, 270, 290)));
								if (dtMilliSeconds - time >= 350)
								{
									m_Sprite.setTextureRect(IntRect(IntRect(930, 320, 270, 290)));
									if (dtMilliSeconds - time >= 400)
									{
										m_Sprite.setTextureRect(IntRect(IntRect(0, 640, 270, 290)));
										if (dtMilliSeconds - time >= 450)
										{
											m_Sprite.setTextureRect(IntRect(IntRect(310, 640, 270, 290)));
											if (dtMilliSeconds - time >= 500)
											{
												m_Sprite.setTextureRect(IntRect(IntRect(620, 640, 270, 290)));
												if (dtMilliSeconds - time >= 550)
												{
													m_Sprite.setTextureRect(IntRect(IntRect(930, 640, 270, 290)));
													if (dtMilliSeconds - time >= 600)
													{
														m_Sprite.setTextureRect(IntRect(IntRect(0, 960, 270, 290)));
														if (dtMilliSeconds - time >= 650)
														{
															m_Sprite.setTextureRect(IntRect(IntRect(310, 960, 270, 290)));
															if (dtMilliSeconds - time >= 700)
															{
																m_Sprite.setTextureRect(IntRect(IntRect(620, 960, 270, 290)));
																if (dtMilliSeconds - time >= 750)
																{
																	m_Sprite.setTextureRect(IntRect(IntRect(930, 960, 270, 290)));
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	bool stolke;
	void update(float elapsedTime)
	{
		m_Sprite.setPosition(m_Position);
	};
};


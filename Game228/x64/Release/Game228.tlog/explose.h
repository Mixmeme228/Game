#pragma once
#include<SFML/Graphics.hpp>
#include <random>
#include<vector>
using namespace sf;
class explose
{	
public:
	Sprite m_Sprite;
	Texture m_Texture;
	explose();
	float m_Speed;
	float time;
	Vector2f m_Position;
	Sprite getSprite();
	void move(float dtMilliSeconds,float dt)
	{
		if (m_Position.y < 720)
		{
			m_Position.y += 0.6 * dt;
		}
		if (dtMilliSeconds - time >= 25)
		{
			m_Sprite.setTextureRect(IntRect(IntRect(310, 0, 270, 290)));
		if (dtMilliSeconds - time >= 50)
			{
				m_Sprite.setTextureRect(IntRect(IntRect(620, 0, 270, 290)));
				if (dtMilliSeconds - time >= 75)
				{
					m_Sprite.setTextureRect(IntRect(IntRect(930, 0, 270, 290)));
					if (dtMilliSeconds - time >= 100)
					{
						m_Sprite.setTextureRect(IntRect(IntRect(0, 320, 270, 290)));
						if (dtMilliSeconds - time >= 125)
						{
							m_Sprite.setTextureRect(IntRect(IntRect(310, 320, 270, 290)));
							if (dtMilliSeconds - time >= 150)
							{
								m_Sprite.setTextureRect(IntRect(IntRect(620, 320, 270, 290)));
								if (dtMilliSeconds - time >= 175)
								{
									m_Sprite.setTextureRect(IntRect(IntRect(930, 320, 270, 290)));
									if (dtMilliSeconds - time >= 200)
									{
										m_Sprite.setTextureRect(IntRect(IntRect(0, 640, 270, 290)));
										if (dtMilliSeconds - time >= 225)
										{
											m_Sprite.setTextureRect(IntRect(IntRect(310, 640, 270, 290)));
											if (dtMilliSeconds - time >= 250)
											{
												m_Sprite.setTextureRect(IntRect(IntRect(620, 640, 270, 290)));
												if (dtMilliSeconds - time >= 275)
												{
													m_Sprite.setTextureRect(IntRect(IntRect(930, 640, 270, 290)));
													if (dtMilliSeconds - time >= 300)
													{
														m_Sprite.setTextureRect(IntRect(IntRect(0, 960, 270, 290)));
														if (dtMilliSeconds - time >= 325)
														{
															m_Sprite.setTextureRect(IntRect(IntRect(310, 960, 270, 290)));
															if (dtMilliSeconds - time >= 350)
															{
																m_Sprite.setTextureRect(IntRect(IntRect(620, 960, 270, 290)));
																if (dtMilliSeconds - time >= 375)
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
	void dont_move(float dtMilliSeconds)
	{
		if (dtMilliSeconds - time >= 25)
		{
			m_Sprite.setTextureRect(IntRect(IntRect(310, 0, 270, 290)));
			if (dtMilliSeconds - time >= 50)
			{
				m_Sprite.setTextureRect(IntRect(IntRect(620, 0, 270, 290)));
				if (dtMilliSeconds - time >= 75)
				{
					m_Sprite.setTextureRect(IntRect(IntRect(930, 0, 270, 290)));
					if (dtMilliSeconds - time >= 100)
					{
						m_Sprite.setTextureRect(IntRect(IntRect(0, 320, 270, 290)));
						if (dtMilliSeconds - time >= 125)
						{
							m_Sprite.setTextureRect(IntRect(IntRect(310, 320, 270, 290)));
							if (dtMilliSeconds - time >= 150)
							{
								m_Sprite.setTextureRect(IntRect(IntRect(620, 320, 270, 290)));
								if (dtMilliSeconds - time >= 175)
								{
									m_Sprite.setTextureRect(IntRect(IntRect(930, 320, 270, 290)));
									if (dtMilliSeconds - time >= 200)
									{
										m_Sprite.setTextureRect(IntRect(IntRect(0, 640, 270, 290)));
										if (dtMilliSeconds - time >= 225)
										{
											m_Sprite.setTextureRect(IntRect(IntRect(310, 640, 270, 290)));
											if (dtMilliSeconds - time >= 250)
											{
												m_Sprite.setTextureRect(IntRect(IntRect(620, 640, 270, 290)));
												if (dtMilliSeconds - time >= 275)
												{
													m_Sprite.setTextureRect(IntRect(IntRect(930, 640, 270, 290)));
													if (dtMilliSeconds - time >= 300)
													{
														m_Sprite.setTextureRect(IntRect(IntRect(0, 960, 270, 290)));
														if (dtMilliSeconds - time >= 325)
														{
															m_Sprite.setTextureRect(IntRect(IntRect(310, 960, 270, 290)));
															if (dtMilliSeconds - time >= 350)
															{
																m_Sprite.setTextureRect(IntRect(IntRect(620, 960, 270, 290)));
																if (dtMilliSeconds - time >= 375)
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


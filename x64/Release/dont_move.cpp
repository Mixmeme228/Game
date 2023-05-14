#include"engine.h"
void Engine::dont_move(float dtMilliSeconds, float time, Sprite & m_Sprite)
{
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
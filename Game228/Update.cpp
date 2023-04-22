#include"engine.h"
#include<vector>
#include<ctime>
using namespace sf;
void Engine::update(float dtAsSeconds, float dtMilliSeconds, float& immortal, int& hp, bool& ant2)
{
	if (long(dtAsSeconds) % 10 == 0&& long(dtAsSeconds)!=0&&Score_shet)
	{
		Score += 50;
		Score_shet = false;
	}
	if (long(dtAsSeconds) % 10 == 1 && long(dtAsSeconds) != 0 && !Score_shet)
	{
		Score_shet = true;
	}
	if (dtAsSeconds - spawn[0] > 2 )
	{
		addEnemy();
		spawn[0] = dtAsSeconds;
	}
	if (dtAsSeconds - spawn[1] > 1 )
	{
		addEnemy();
		spawn[1] = dtAsSeconds;
	}
	if (dtAsSeconds - spawn[2] > 1)
	{
		addCoin();
		spawn[2] = dtAsSeconds;
	}
	if (dtAsSeconds - spawn[3] > 2)
	{
		addCoin();
		spawn[3] = dtAsSeconds;
	}
	m_MyCar.update(dtAsSeconds, m_Enemy.size());
	for (int i = 0; i < m_Enemy.size() && m_Enemy.size() >= 1&&!m_Enemy.empty(); ++i) {
		m_Enemy[i].update(dtAsSeconds);
		m_Enemy[i].move();
		if (m_Enemy[i].m_Position.y >= 720)
		{
			m_Enemy.erase(m_Enemy.begin() + i);
			continue;
		}
		if ((m_MyCar.m_Position.y - m_Enemy[i].m_Position.y <= 110 && m_MyCar.m_Position.y - m_Enemy[i].m_Position.y >= -110) && m_MyCar.m_Position.x == m_Enemy[i].m_Position.x)
		{
			m_Enemy[i].stolke = true;
			stolk = true;
			if ((dtAsSeconds - immortal > 4)) {
				if (hp > 0)
				{
					hp--;
					m_MyCar.m_Texture.loadFromFile("31.png");
					m_MyCar.m_Sprite.setTexture(m_MyCar.m_Texture);
					ant2 = false;
					addexplose(m_Enemy[i], dtMilliSeconds);
					m_Enemy.erase(m_Enemy.begin() + i);
					if (hp == 0)
					{
						m_explose.clear();
						game_over(m_MyCar.m_Position.x, m_MyCar.m_Position.y,m_Enemy);
					}
					else
					{
						sound1();
					}
					immortal = dtAsSeconds;
				}
			}
			else
			{
				addexplose(m_Enemy[i], dtMilliSeconds);
				m_Enemy.erase(m_Enemy.begin() + i);
			}

		}
		else
		{
			m_Enemy[i].stolke = false;
		}
	}
	for (int i = 0; i < m_Enemy.size() && m_Enemy.size() >= 1&&!m_Enemy.empty(); ++i) {
		for (int j = i+1; j < m_Enemy.size() && m_Enemy.size()&&!m_Enemy.empty(); ++j)
		{
			if ((m_Enemy[j].m_Position.y - m_Enemy[i].m_Position.y <= 145 && m_Enemy[j].m_Position.y - m_Enemy[i].m_Position.y >= -145) && m_Enemy[j].m_Position.x == m_Enemy[i].m_Position.x && j != i)
			{
				if (!m_Enemy.empty()) {
					addexplose(m_Enemy[i], dtMilliSeconds);
						m_Enemy.erase(m_Enemy.begin() + i);
						m_Enemy.erase(m_Enemy.begin() + j - 1);
				}
			}
		}
		if (dtAsSeconds - immortal > 4 && !ant2)
		{
			music.stop();
			m_MyCar.m_Texture.loadFromFile("3.png");
			m_MyCar.m_Sprite.setTexture(m_MyCar.m_Texture);
			ant2 = true;
		}
	}
	for (int j = 0; j < m_Coin.size() && m_Coin.size() >= 1 && !m_Coin.empty(); ++j)
	{
		m_Coin[j].update(dtAsSeconds);
		m_Coin[j].move();
		if ((m_Coin[j].m_Position.y - m_MyCar.m_Position.y <= 80 && m_Coin[j].m_Position.y - m_MyCar.m_Position.y >= -80) && m_Coin[j].m_Position.x-30 == m_MyCar.m_Position.x )
		{
			m_Coin.erase(m_Coin.begin() + j);
			Score += 100;
		}
	}
	for (int i = 0; i < m_Enemy.size() && m_Enemy.size() >= 1 && !m_Enemy.empty(); ++i)
	{
		for (int j = 0; j < m_Coin.size() && m_Coin.size() >= 1 && !m_Coin.empty(); ++j)
		{
			if ((m_Coin[j].m_Position.y - m_Enemy[i].m_Position.y <= 130 && m_Coin[j].m_Position.y - m_Enemy[i].m_Position.y >= -130) && m_Coin[j].m_Position.x-30 == m_Enemy[i].m_Position.x )
			{
				m_Coin.erase(m_Coin.begin() + j);
			}
		}
	}
	for (int i = 0; i < m_Coin.size() && m_Coin.size() >= 1 && !m_Coin.empty(); ++i)
	{
		for (int j = i+1; j < m_Coin.size() && m_Coin.size() >= 1 && !m_Coin.empty(); ++j)
		{
			if ((m_Coin[j].m_Position.y - m_Coin[i].m_Position.y <= 130 && m_Coin[j].m_Position.y - m_Coin[i].m_Position.y >= -130) && m_Coin[j].m_Position.x == m_Coin[i].m_Position.x && j != i)
			{
				m_Coin.erase(m_Coin.begin() + j);
			}
		}
	}
	for (int i = 0; i < m_Coin.size() && m_Coin.size() >= 1 && !m_Coin.empty(); ++i)
	{
		if (m_Coin[i].m_Position.y >= 730)
		{
			m_Coin.erase(m_Coin.begin() + i);
		}
	}
	for (int i = 0; i < m_explose.size() && m_explose.size() >= 1&&!m_explose.empty(); ++i)
	{
		m_explose[i].update(dtAsSeconds);
		m_explose[i].move(dtMilliSeconds);
		if (dtMilliSeconds - m_explose[i].time > 750)
		{
			if (!m_explose.empty()) {
				m_explose.erase(m_explose.begin() + i);
			}
		}
	}
}
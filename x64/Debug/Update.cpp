#include"engine.h"
#include<vector>
#include<ctime>
using namespace sf;
void Engine::update(float dtAsSeconds, bool& ant, float& immortal, int& hp, bool& ant2)
{
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
					sound1();
					addexplose(m_Enemy[i], dtAsSeconds);
					m_Enemy.erase(m_Enemy.begin() + i);
					if (hp == 0)
					{
						m_Window.close();
					}
					immortal = dtAsSeconds;
				}
			}
			else
			{
				addexplose(m_Enemy[i], dtAsSeconds);
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
					addexplose(m_Enemy[i],dtAsSeconds);
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
	for (int i = 0; i < m_explose.size() && m_explose.size() >= 1&&!m_explose.empty(); ++i)
	{
		m_explose[i].update(dtAsSeconds);
		m_explose[i].move();
		if (dtAsSeconds -float( m_explose[i].time) > 0.75)
		{
			if (!m_explose.empty()) {
				m_explose.erase(m_explose.begin() + i);
			}
		}
	}
}
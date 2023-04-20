#include"engine.h"
#include"list.h"
#include"MyCar.h"
#include<SFML/Audio.hpp>
Engine::Engine()
{
	Vector2f resolution;
	resolution.x = 1280;
	resolution.y = 720;
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"MyGame",
		Style::Default);
	m_Window.setFramerateLimit(60);
	m_BackgroundTexture.loadFromFile("1.png");
	m_BackgroundSprite.setTexture(m_BackgroundTexture);
}
void Engine::start()
{
	bool ant = true, ant2=true,ant3=true;
	Cursor cursor;
	polnoegavno();
	pause = false;
	Font font;
	font.loadFromFile("ArialRegular.ttf");
	music.openFromFile("icq.wav");
	if (cursor.loadFromSystem(sf::Cursor::Arrow))
		m_Window.setMouseCursor(cursor);
	globallist.addNode();
	int doroga=100;
	for (int i=0;i<7;i++)
	{
		g.push_back(false);
	}
	stolk = false;
	int hp = 1,gavno=0;
	spawn[0] = 0;
	spawn[1] = 0;
	spawn[2] = 0;
	spawn[3] = 0;
	float immortal = 0,dtMilliSeconds=0,gavno2=0;
	Text text("Pause", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::White);
	text.setPosition(500, 500);
	pause2();
	sf::Event event;
	Clock clock;
	int dtAsSeconds=0;
	while (m_Window.isOpen())
	{
		Time dt = clock.getElapsedTime();
		dtAsSeconds = dt.asSeconds() + gavno;
		dtMilliSeconds = dt.asMilliseconds() + gavno2;
		if (pause==true)
		{
			clock.restart();
		}
		while (m_Window.pollEvent(event))
			{
					if (event.type == sf::Event::Closed)
						m_Window.close();
			}
		if (Keyboard::isKeyPressed(sf::Keyboard::Escape) && ant3)
		{
			if (pause == false) {
				gavno = dtAsSeconds;
				gavno2 = dtMilliSeconds;
				pause = true;
				sound_pause.play();
				m_Window.draw(m_Sprite2);
				m_Window.display();
			}
			else {
				pause = false;
			}
			ant3 = false;
		}
		else
		{
			if (!Keyboard::isKeyPressed(sf::Keyboard::Escape))
				ant3 = true;
		}
		if (pause == false) {
			input(doroga, ant);
			update(dtAsSeconds, dtMilliSeconds, immortal, hp, ant2);
			draw(doroga, stolk, pause, dtAsSeconds, hp, immortal);
		}
	}
}

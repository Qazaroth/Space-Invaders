#include <SFML/Graphics.hpp>

#include "Ship.h"
#include "Enemy.h"
#include "FPSTimer.h"
#include "Utils.h"
#include "Bullet.h"

#define print(m) std::cout << m << std::endl

#define FRAMECAP 60
#define MAX_ENEMY_CAP 7
#define DEFAULT_ENEMY_CAP 7.0f

std::string TITLE = "Space Invaders C++";
sf::Uint32 styleFlag = sf::Style::Default;

FPSTimer timer;
float timerCounter = 0.0f;
unsigned int frames = 0;

std::vector<Enemy> enemies;
std::vector<Bullet> bullets;

int main()
{
	enemies.resize(MAX_ENEMY_CAP);

	sf::RenderWindow window(sf::VideoMode(1200, 800), TITLE, styleFlag);
	sf::Vector2u windowSize = window.getSize();

	unsigned int width = windowSize.x;
	unsigned int height = windowSize.y;

	window.setFramerateLimit(FRAMECAP);

	Ship ship(window);

	for (int i = 0; i < enemies.size(); i++)
	{
		float x = ((i * 160) + 80) * (DEFAULT_ENEMY_CAP/MAX_ENEMY_CAP);
		enemies[i] = Enemy(x, 60);
	}

	while (window.isOpen())
	{
		width = windowSize.x;
		height = windowSize.y;

		sf::Event windowEvent;

		window.clear(sf::Color(51, 51, 51, 255));
		ship.show(window);
		ship.move();
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i].show(window);
			bullets[i].move();

			for (int j = 0; j < enemies.size(); j++)
			{
				if (bullets[i].hits(enemies[j]))
				{
					enemies[j].hurt();
					bullets.erase(std::next(bullets.begin(), i));
					print("KILL");
				}
			}
		}
		bool edge = false;
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i].show(window);
			enemies[i].move();

			if (enemies[i].getX() + enemies[i].getRadius() + 25.0f > width ||
				enemies[i].getX() < enemies[i].getRadius() - 25.0f)
			{
				edge = true;
			}
		}

		if (edge)
		{
			for (int i = 0; i < enemies.size(); i++)
			{
				enemies[i].shiftDown();
			}
		}

		window.display();

		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::KeyReleased:
			{
				auto keyCode = windowEvent.key.code;
				if (keyCode != sf::Keyboard::Space)
					ship.setDir(0);
				break;
			}
			case sf::Event::KeyPressed:
			{
				auto keyCode = windowEvent.key.code;

				if (keyCode == sf::Keyboard::Space)
				{
					Bullet b(ship.getX()-5, height);
					bullets.push_back(b);
				}

				if (keyCode == sf::Keyboard::Right)
				{
					ship.setDir(1);
				}
				else if (keyCode == sf::Keyboard::Left)
				{
					ship.setDir(-1);
				}
				break;
			}
			case sf::Event::Closed:
				window.close();
				break;
			default:
				break;
			}
		}

		frames++;
		if (timer.elapsed() - timerCounter > 1.0f)
		{
			timerCounter += 1.0f;
			printf("%d FPS\n", frames);
			frames = 0;
		}
	}
	return 0;
}
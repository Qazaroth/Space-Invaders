#include <SFML/Graphics.hpp>

#include "Ship.h"
#include "FPSTimer.h"

#define FRAMECAP 60

std::string TITLE = "Space Invaders C++";
sf::Uint32 styleFlag = sf::Style::Default;

FPSTimer timer;
float timerCounter = 0.0f;
unsigned int frames = 0;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), TITLE, styleFlag);
	window.setFramerateLimit(FRAMECAP);

	Ship ship(window);

	while (window.isOpen())
	{
		sf::Event windowEvent;

		window.clear(sf::Color(51, 51, 51, 255));
		ship.show(window);
		window.display();

		while (window.pollEvent(windowEvent))
		{
			switch (windowEvent.type)
			{
			case sf::Event::KeyPressed:
			{
				auto keyCode = windowEvent.key.code;

				if (keyCode == sf::Keyboard::Right)
				{
					ship.move(1);
				}
				else if (keyCode == sf::Keyboard::Left)
				{
					ship.move(-1);
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
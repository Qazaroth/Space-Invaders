#pragma once

#include <SFML/Graphics.hpp>

class Ship
{
private:
	float x;

	float width;
	float height;
public:
	Ship(sf::Window &window);
	~Ship();

	void move(int dir);

	void show(sf::RenderWindow &window);
};
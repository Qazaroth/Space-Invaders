#pragma once

#include <SFML/Graphics.hpp>

class Ship
{
private:
	float x;
	float xdir = 0.0f;

	float width;
	float height;
public:
	Ship(sf::Window &window);
	~Ship();

	void move();
	void setDir(int dir);
	void show(sf::RenderWindow &window);

	inline float getX() { return x; }
};
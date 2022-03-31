#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	float x = 0;
	float y = 50.0f;
	float r = 60.0f;

	float xdir = 1.0f;
public:
	Enemy() {}
	Enemy(float x, float y);
	~Enemy();

	void hurt();
	void move();
	void shiftDown();
	void show(sf::RenderWindow &window);

	inline float getX() { return x; }
	inline float getY() { return y; }
	inline float getRadius() { return r; }
	inline sf::Vector2f getPosition() { return sf::Vector2f(x, y); }
};
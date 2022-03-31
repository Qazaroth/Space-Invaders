#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
private:
	float x = 0;
	float y = 50.0f;

	float width = 0;
	float height = 0;
public:
	Enemy() {}
	Enemy(sf::Window &window, float x, float y);
	~Enemy();

	void move(int dir);

	void show(sf::RenderWindow &window);
};
#pragma once

#include "Enemy.h"
#include "Utils.h"

#include <SFML/Graphics.hpp>

class Bullet
{
private:
	float x = 0;
	float y = 50.0f;
	float r = 10.0f;

	float width = 0;
	float height = 0;
public:
	Bullet() {}
	Bullet(float x, float y);
	~Bullet();

	void move();
	void show(sf::RenderWindow &window);

	bool hits(Enemy enemy);
};
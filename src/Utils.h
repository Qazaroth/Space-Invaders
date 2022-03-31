#pragma once

#include <iostream>

inline int static getRandomNumber(int min, int max)
{
	return min + (std::rand() % (max - min + 1));
}
float static dist(const sf::Vector2f p1, const sf::Vector2f p2)
{
	float diffY = p1.y - p2.y;
	float diffX = p1.x - p2.x;
	return sqrt((diffY * diffY) + (diffX * diffX));
}
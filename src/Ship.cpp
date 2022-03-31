#include "Ship.h"

Ship::Ship(sf::Window &window)
{
	width = window.getSize().x;
	height = window.getSize().y;

	this->x = width / 2;
}

Ship::~Ship() {}

void Ship::move(int dir)
{
	this->x += dir * 5;
}

void Ship::show(sf::RenderWindow &window)
{
	sf::RectangleShape rect(sf::Vector2f(20, 60));
	rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
	rect.setPosition(this->x, this->height - 20);
	rect.setFillColor(sf::Color(255, 255, 255, 255));

	window.draw(rect);
}
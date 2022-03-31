#include "Bullet.h"

Bullet::Bullet(float x, float y)
{
	this->x = x;
	this->y = y;
}

Bullet::~Bullet() {}

void Bullet::move()
{
	this->y = this->y - 5;
}

void Bullet::show(sf::RenderWindow &window)
{
	sf::CircleShape circle(this->r);
	circle.setOutlineThickness(0);
	circle.setOrigin(circle.getRadius() / 2, circle.getRadius() / 2);
	circle.setPosition(this->x, this->y);
	circle.setFillColor(sf::Color(150, 0, 255, 255));

	window.draw(circle);
}

bool Bullet::hits(Enemy e)
{
	sf::Vector2f myPos(this->x, this->y);
	float d = dist(myPos, e.getPosition());

	if (d < this->r + e.getRadius())
	{
		return true;
	}

	return false;
}
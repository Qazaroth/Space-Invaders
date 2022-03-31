#include "Enemy.h"

Enemy::Enemy(float x, float y)
{	
	this->x = x;
	this->y = y;
}

Enemy::~Enemy() {}

void Enemy::hurt()
{
	this->r -= 2;
}

void Enemy::move()
{
	this->x += this->xdir;
}

void Enemy::shiftDown()
{
	this->xdir *= -1;
	this->y += this->r;
}

void Enemy::show(sf::RenderWindow &window)
{
	sf::CircleShape circle(this->r);
	circle.setPosition(this->x, this->y);
	circle.setFillColor(sf::Color(255, 0, 200, 150));
	circle.setOrigin(circle.getRadius() / 2, circle.getRadius() / 2);

	window.draw(circle);
}
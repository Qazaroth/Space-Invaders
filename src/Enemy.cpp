#include "Enemy.h"

Enemy::Enemy(sf::Window &window, float x, float y)
{
	this->width = window.getSize().x;
	this->height = window.getSize().y;
	
	this->x = x;
	this->y = y;
}

Enemy::~Enemy() {}

void Enemy::move(int dir)
{

}

void Enemy::show(sf::RenderWindow &window)
{
	sf::CircleShape circle(60.0f);
	circle.setOrigin(circle.getRadius() / 2, circle.getRadius() / 2);
	circle.setPosition(this->x, this->y);
	circle.setFillColor(sf::Color(255, 0, 200, 255));

	window.draw(circle);
}
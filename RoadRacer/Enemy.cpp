#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy()
{
	vFac = 0.0f;
	isDed = false;
}

Enemy::Enemy(sf::Vector2f pos)
{
	body.setTexture(&Assets::access()->getTxr("enemy"));
	body.setSize({ 25.0f, 50.0f });
	centerOrigin(body);
	body.setPosition(pos);
	//body.setFillColor(sf::Color::Magenta);
	vFac = 0.0f;
	isDed = false;
}

Enemy::~Enemy()
{
}

void Enemy::custom(std::string txr, sf::Vector2f size)
{
	body.setSize(size);
	body.setTexture(&Assets::access()->getTxr(txr));
	centerOrigin(body);
	body.setPosition(sf::Vector2f(400.0f, 650.0f));
}

void Enemy::update(float dt)
{
	body.move(0.0f, (enemySpeed + vFac) * dt);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(body);
}

void Enemy::overrideTexture(sf::Texture& txr)
{
	body.setTexture(&txr);
}

void Enemy::setPos(sf::Vector2f pos)
{
	body.setPosition(pos);
}

sf::Vector2f Enemy::getPos()
{
	return body.getPosition();
}

sf::FloatRect Enemy::getGB()
{
	return body.getGlobalBounds();
}

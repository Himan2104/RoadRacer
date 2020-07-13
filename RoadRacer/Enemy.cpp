#include "pch.h"
#include "Enemy.hpp"

Enemy::Enemy(sf::Vector2f size, std::string txr)
{
	body.setTexture(&Assets::access()->getTxr(txr));
	body.setSize(size);
	centerOrigin(body);
	body.setPosition(sf::Vector2f(400.0f, 100.0f));
}

Enemy::Enemy(sf::Vector2f pos)
{
	body.setTexture(&Assets::access()->getTxr("enemy"));
	body.setSize({ 25.0f, 50.0f });
	centerOrigin(body);
	body.setPosition(pos);
	//body.setFillColor(sf::Color::Magenta);
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	body.move(0.0f, enemySpeed * dt);
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

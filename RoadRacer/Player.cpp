#include "pch.h"
#include "Player.hpp"

Player::Player()
{
	lives = 3;
}

Player::~Player()
{
}

void Player::init()
{
	body.setSize(sf::Vector2f(25.0f, 50.0f));
	body.setTexture(&Assets::access()->getTxr("player"));
	centerOrigin(body);
	body.setPosition(Vmode.width / 2.0f, Vmode.height / 2.0f);
	//body.setFillColor(sf::Color(150, 0, 0, 200));
}

void Player::update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && body.getPosition().x < 600.0f)
	{
		body.move(playerSpeed.x * dt, 0.0f);
		body.setRotation(10);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && body.getPosition().x > 200.0f)
	{
		body.move(-playerSpeed.x * dt, 0.0f);
		body.setRotation(-10);
	}
	else body.setRotation(0);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && body.getPosition().y + body.getSize().y / 2.0f < 600.0f) body.move(0.0f, playerSpeed.x * dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && body.getPosition().y - body.getSize().y / 2.0f > 0.0f) body.move(0.0f, -playerSpeed.x * dt);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) lives++;

	if (lives == 0) body.setTexture(&Assets::access()->getTxr("boom"));
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(body);
}

sf::Vector2f Player::getPos()
{
	return body.getPosition();
}

void Player::addPushback(sf::Vector2f mag)
{
	body.move(mag);
}

sf::FloatRect Player::getGB()
{
	return body.getGlobalBounds();
}

#include "pch.h"
#include "Player.hpp"

Player::Player()
{
	hp = 100;
}

Player::~Player()
{
}

void Player::init(Assets& assets)
{
	this->assets = assets;

	body.setSize(sf::Vector2f(25.0f, 50.0f));
	body.setTexture(&this->assets.getTxr("player"));
	centerOrigin(body);
	body.setPosition(Vmode.width / 2.0f, Vmode.height / 2.0f);

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
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(body);
}

sf::FloatRect Player::getGB()
{
	return body.getGlobalBounds();
}

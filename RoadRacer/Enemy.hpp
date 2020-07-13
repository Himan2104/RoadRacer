#pragma once
#include"Definitions.hpp"

class Enemy
{
public:
	Enemy(sf::Vector2f size, std::string txr);
	Enemy(sf::Vector2f pos);
	~Enemy();
	
	void update(float dt);

	void render(sf::RenderTarget& target);

	void overrideTexture(sf::Texture& txr);

	void setPos(sf::Vector2f pos);

	sf::Vector2f getPos();

	sf::FloatRect getGB();
private:
	sf::RectangleShape body;
};


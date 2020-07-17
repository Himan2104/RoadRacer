#pragma once
#include"Definitions.hpp"

class Enemy
{
public:
	Enemy();
	Enemy(sf::Vector2f pos);
	~Enemy();

	void custom(std::string txr, sf::Vector2f size = sf::Vector2f(25.0f, 50.0f));
	
	void update(float dt);

	void render(sf::RenderTarget& target);

	void overrideTexture(sf::Texture& txr);

	void setPos(sf::Vector2f pos);

	sf::Vector2f getPos();

	sf::FloatRect getGB();

	float vFac;

	bool isDed;
private:
	sf::RectangleShape body;
};


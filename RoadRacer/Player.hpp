#pragma once
#include"Definitions.hpp"

class Player
{
public:
	Player();
	~Player();

	void init();

	void update(float dt);

	void render(sf::RenderTarget& target);

	unsigned int lives;

	sf::FloatRect getGB();

private:
	sf::RectangleShape body;
};


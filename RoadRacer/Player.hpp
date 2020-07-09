#pragma once
#include"Definitions.hpp"

class Player
{
public:
	Player();
	~Player();

	void init(Assets& assets);

	void update(float dt);

	void render(sf::RenderTarget& target);

	unsigned int hp;

	sf::FloatRect getGB();

private:
	sf::RectangleShape body;
	Assets assets;
};


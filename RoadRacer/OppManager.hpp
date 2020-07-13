#pragma once
#include"Definitions.hpp"
#include"Enemy.hpp"
#include"Player.hpp"

class OppManager
{
public:
	OppManager();
	~OppManager();

	void update(Player& player, float delTime);
	void render(sf::RenderTarget& target);

private:
	std::vector<Enemy*> normies;
	Enemy thicc;
	Enemy health;

	//spawnClocks
	sf::Clock nClk;
	sf::Clock tClk;
	sf::Clock hClk;
	float tdelay, hdelay;
};

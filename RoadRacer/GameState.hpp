#pragma once
#include"Definitions.hpp"

class GameState : public State
{
public:
	GameState();
	~GameState();
	
	void initialize(Assets& assets) override;
	void update(float delTime, sf::Vector2f mpos, int& statevar) override;
	void render(sf::RenderTarget& renderer) override;

private:
	Assets assets;
};


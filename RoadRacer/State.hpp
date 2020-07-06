#pragma once
#include<SFML/Graphics.hpp>
#include"Assets.hpp"

class State
{
public:
	virtual void initialize(Assets& assets) = 0;
	virtual void update(float delTime, sf::Vector2f mpos, int& statevar) = 0;
	virtual void render(sf::RenderTarget& renderer) = 0;
};
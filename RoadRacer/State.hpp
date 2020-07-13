#pragma once
#include<SFML/Graphics.hpp>

class State
{
public:
	virtual void initialize() = 0;
	virtual void update(float delTime, sf::Vector2f mpos, int& statevar) = 0;
	virtual void render(sf::RenderTarget& renderer) = 0;
};
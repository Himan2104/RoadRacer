#pragma once
#include"Definitions.hpp"

class SplashScreen : public State
{
public:
	SplashScreen();
	~SplashScreen();

	void initialize(Assets& assets) override;
	void update(float delTime, sf::Vector2f mpos, int& statevar) override;
	void render(sf::RenderTarget& renderer) override;

private:
	Assets assets;

	sf::Sprite splash;

	sf::RectangleShape rect1, rect2;
};


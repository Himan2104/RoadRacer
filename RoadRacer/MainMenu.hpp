#pragma once
#include"Definitions.hpp"
#include"Highscore.hpp"

class MainMenu : public State
{
public:
	MainMenu();
	~MainMenu();

	void initialize() override;
	void update(float delTime, sf::Vector2f mpos, int& statevar) override;
	void render(sf::RenderTarget& renderer) override;


private:
	sf::Sprite bg;

	sf::Text play, exit;
	sf::Text highscore;

	Highscore hs;

	sf::Sound select, hover;
};


#pragma once
#include"Definitions.hpp"
#include"Player.hpp"
#include"OppManager.hpp"
#include"Highscore.hpp"

class GameState : public State
{
public:
	GameState();
	~GameState();
	
	void initialize() override;
	void update(float delTime, sf::Vector2f mpos, int& statevar) override;
	void render(sf::RenderTarget& renderer) override;

private:
	sf::Sprite bgA, bgB;
	Player player;

	OppManager Oman;

	sf::Text debug;

	std::vector<sf::RectangleShape> lives;

	sf::RectangleShape heart;

	bool isOver;
	sf::Text gameOver, gSha;
	sf::Clock scoreClk;
	sf::Text Score;

	unsigned int score;

	bool isStarted;
	sf::Clock countDown;
	sf::Text cntDn;
	int cnt;
	sf::Sound CDX, CDGO;

	Highscore hs;

	static uint16_t xyz;
};


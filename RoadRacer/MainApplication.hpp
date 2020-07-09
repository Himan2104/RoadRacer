#pragma once
#include"Definitions.hpp"
#include"MainMenu.hpp"
#include"SplashScreen.hpp"
#include"GameState.hpp"

class MainApplication
{
public:
	MainApplication(sf::VideoMode videomode = sf::VideoMode(800, 600, 32), std::string windowTitle = "DefaultTitle");
	~MainApplication();

	void start();

private:
	sf::RenderWindow window;
	sf::Clock frameClock;
	float delTime;
	sf::Vector2f mpos;
	State* currentState;
	
	Assets assets;

	SplashScreen ss;
	MainMenu mainmenu;
	GameState game;

	int currentStateID, prevStateID;

	void handleStateChange();
};


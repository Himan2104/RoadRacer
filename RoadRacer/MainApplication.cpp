#include "pch.h"
#include "MainApplication.hpp"

MainApplication::MainApplication(sf::VideoMode videomode, std::string windowTitle)
{
	window.create(videomode, windowTitle);
	window.setFramerateLimit(frameRateCap);

	assets.loadAssets();

	delTime = 0;
	mainmenu.initialize(assets);
	ss.initialize(assets);
	game.initialize(assets);

	mpos = sf::Vector2f(0, 0);

	currentStateID = 0;
	prevStateID = 0;
	handleStateChange();
	
}

MainApplication::~MainApplication()
{
}

void MainApplication::start()
{
	while (window.isOpen())
	{
		if (prevStateID != currentStateID) handleStateChange();
		prevStateID = currentStateID;
		delTime = frameClock.restart().asSeconds();
		mpos = sf::Vector2f(sf::Mouse::getPosition(window));

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed: window.close();
				break;
			default: break;
			}
		}

		currentState->update(delTime, mpos, currentStateID);
		
		window.clear();
		currentState->render(window);
		window.display();
	}
}

void MainApplication::handleStateChange()
{
	switch (currentStateID)
	{
	case -1: window.close();
		break;
	case 0: currentState = &ss;
		break;
	case 1: currentState = &mainmenu;
		break;
	case 2: currentState = &game;
		break;
	default: currentState = &mainmenu;
		break;
	}
}

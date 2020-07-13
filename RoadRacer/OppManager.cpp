#include "pch.h"
#include "OppManager.hpp"

OppManager::OppManager() : 
	thicc(sf::Vector2f(50.0f, 140.0f), "thicc"),
	health(sf::Vector2f(25.0f, 50.0f), "health")
{

	tdelay = float(rand() % 20 + 10);
	hdelay = float(rand() % 40 + 20);

	nClk.restart().asSeconds();
	tClk.restart().asSeconds();
	hClk.restart().asSeconds();
}

OppManager::~OppManager()
{
}

void OppManager::update(Player& player, float delTime)
{
	for (auto& val : normies) val->update(delTime);
	thicc.update(delTime);
	health.update(delTime);

	for (size_t i = 0; i < normies.size(); i++)
	{
		if (player.getGB().intersects(normies[i]->getGB()))
		{
			delete normies[i];
			normies.erase(normies.begin() + i);
			player.lives--;
		}
		if (normies[i]->getPos().y > 650.0f)
		{
			delete normies[i];
			normies.erase(normies.begin() + i);
		}
	}
	if (player.getGB().intersects(thicc.getGB()))
	{
		thicc.setPos({ thicc.getPos().x, 800.0f });
		player.lives -= 2;
	}
	if (player.getGB().intersects(health.getGB()))
	{
		health.setPos({ health.getPos().x, 800.0f });
		player.lives++;
	}

	if (nClk.getElapsedTime().asSeconds() >= 0.95f)
	{
		normies.push_back(new Enemy(sf::Vector2f(float(rand() % 400 + 200), -50.0f)));
		nClk.restart().asSeconds();
	}
	if (tClk.getElapsedTime().asSeconds() >= tdelay)
	{
		thicc.setPos(sf::Vector2f(float(rand() % 400 + 200), -50.0f));
		tClk.restart().asSeconds();
		tdelay = float(rand() % 20 + 10);
	}
	if (hClk.getElapsedTime().asSeconds() >= tdelay)
	{
		health.setPos(sf::Vector2f(float(rand() % 400 + 200), -50.0f));
		hClk.restart().asSeconds();
		hdelay = float(rand() % 40 + 20);
	}
}

void OppManager::render(sf::RenderTarget& target)
{
	for (auto& val : normies) val->render(target);
	if (thicc.getPos().y < 650.0f)  thicc.render(target);
	if (health.getPos().y < 650.0f)  health.render(target);
}

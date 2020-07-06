#pragma once
#include<SFML/Graphics.hpp>

class Assets
{
public:
	Assets();
	~Assets();

	void loadAssets();

	sf::Texture& getTxr(std::string name);
	sf::Font& getFont(std::string name);

private:
	std::map<std::string, sf::Texture> txrs;
	std::map<std::string, sf::Font> fonts;

	void loadFont(std::string name, std::string filepath);
	void loadTexture(std::string name, std::string filepath);

	
};


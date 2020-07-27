#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<memory>

class Assets : sf::NonCopyable
{
public:
	Assets();
	~Assets();

	static Assets* access();

	void loadAssets();

	sf::Texture& getTxr(std::string name);
	sf::Font& getFont(std::string name);
	sf::SoundBuffer& getSoundBuffer(std::string name);

private:
	std::map<std::string, sf::Texture> txrs;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::SoundBuffer> soundBuffers;

	void loadFont(std::string name, std::string filepath);
	void loadTexture(std::string name, std::string filepath);
	void loadSoundBuffer(std::string name, std::string filepath);

	
};



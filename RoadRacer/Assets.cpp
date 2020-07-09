#include "pch.h"
#include "Assets.hpp"

Assets::Assets()
{
    
}

Assets::~Assets()
{
   
}

void Assets::loadAssets()
{
    loadTexture("mm_bg", "data/images/mm_bg.png");
    loadTexture("ss_main", "data/images/ss_main.png");
    loadTexture("player", "data/images/player.png");
    loadTexture("game_bg", "data/images/bg.png");


    loadFont("mm_fmain", "data/fonts/mm.ttf");
}

sf::Texture& Assets::getTxr(std::string name)
{
    return txrs.at(name);
    
}

sf::Font& Assets::getFont(std::string name)
{
    return fonts.at(name);
}

void Assets::loadFont(std::string name, std::string filepath)
{
    sf::Font tmp;
    tmp.loadFromFile(filepath);
    fonts.insert(std::make_pair(name, tmp));
}

void Assets::loadTexture(std::string name, std::string filepath)
{
    sf::Texture tmp;
    tmp.loadFromFile(filepath);
    txrs.insert(std::make_pair(name, tmp));
}

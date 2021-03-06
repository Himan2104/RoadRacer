#include "pch.h"
#include "Assets.hpp"

Assets::Assets()
{

}

Assets::~Assets()
{
   
}

Assets* Assets::access()
{
    static Assets assets;
    return &assets;
}


void Assets::loadAssets()
{
    loadTexture("mm_bg", "data/images/mm_bg.png");
    loadTexture("ss_main", "data/images/ss_main.png");
    loadTexture("player", "data/images/player.png");
    loadTexture("enemy", "data/images/normie.png");
    loadTexture("game_bg", "data/images/bg.png");
    loadTexture("thicc", "data/images/thicc.png");
    loadTexture("health", "data/images/hp.png");
    loadTexture("boom", "data/images/0.png");
    loadTexture("heart", "data/images/heart.png");

    loadFont("mm_fmain", "data/fonts/mm.ttf");
    loadFont("debug", "data/fonts/arial.ttf");

    loadSoundBuffer("mm_select", "data/sfx/MenuSelect.wav");
    loadSoundBuffer("mm_hover", "data/sfx/menuhover.wav");
    loadSoundBuffer("explosion", "data/sfx/explosion.wav");
    loadSoundBuffer("CDX", "data/sfx/countDownX.wav");
    loadSoundBuffer("CDGO", "data/sfx/countDownGO.wav");
}

sf::Texture& Assets::getTxr(std::string name)
{
    return txrs.at(name);
}

sf::Font& Assets::getFont(std::string name)
{
    return fonts.at(name);
}

sf::SoundBuffer& Assets::getSoundBuffer(std::string name)
{
    return soundBuffers.at(name);
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

void Assets::loadSoundBuffer(std::string name, std::string filepath)
{
    sf::SoundBuffer tmp;
    tmp.loadFromFile(filepath);
    soundBuffers.insert(std::make_pair(name, tmp));
}

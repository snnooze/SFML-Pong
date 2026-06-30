#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Globals.hpp"
#include <iostream>

extern sf::SoundBuffer Globals::g_bufferMenu;

using namespace sf;

class Button : public Sprite
{
    private: 
    Texture *m_textures;
    Font m_font;
    bool m_isSmallButton = false;
    sf::Sound m_sound = sf::Sound(Globals::g_bufferMenu);
    public:
    Button(sf::Texture &text, sf::IntRect size, bool isSmallButton = false);
    Text m_labelTxt = Text(m_font, "");
    void setHover();
    int m_position = 1;
    int previousPosition = 1;
    bool m_firstAffichage = true;
    void setVolumeBtn(float volume);
    ~Button();

};
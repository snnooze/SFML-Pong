#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Button : public Sprite
{
    private: 
    Texture *m_texture[2];
    Font m_font;
    public:
    Button(sf::Texture *text, sf::IntRect size);
    Text m_labelTxt = Text(m_font, "1 Player");
    void initialize(sf::Texture *textures);
    void update();
    void setHover();
    int m_position = 1;
    ~Button();

};
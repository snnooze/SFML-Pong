#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MyHelpers.hpp"

class Ball : public sf::Sprite
{
private :
    sf::RenderWindow *m_parent;
    int m_pos_x = 0;
    int m_pos_y = 0;
    bool m_isActive = false;
    float m_speed = 500;
    sf::Texture *m_textures[5];
    sf::Vector2f m_ballDirection = {0,0};
    sf::SoundBuffer m_buffer;
    sf::Sound m_rebond = sf::Sound(this->m_buffer);
public :
    Ball(sf::RenderWindow &par, sf::Texture *textures[5]);
    void inputs();
    void update(float dtTime);
    void draw();
    void startMove();
    void move(float dtTime);
    void reverseDirection();
    sf::Vector2f getDirection();
    ~Ball();
};

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "globals.hpp"
#include <iostream>
#include <random>

extern sf::SoundBuffer Globals::g_buffer;
extern sf::SoundBuffer Globals::g_bufferOut;
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
    sf::Sound m_rebond = sf::Sound(Globals::g_buffer);
    sf::Sound m_out = sf::Sound(Globals::g_bufferOut);
public :
    Ball(sf::RenderWindow &par, sf::Texture *textures[5]);
    void inputs();
    void update(float dtTime);
    void draw();
    void startMove(bool is_FirstPlayerTurn);
    void move(float dtTime);
    void reverseDirection();
    sf::Vector2f getDirection();
    void emitOutSound();
    void setVolume(float volume);
    ~Ball();
};

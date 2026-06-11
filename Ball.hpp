#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>

extern sf::SoundBuffer g_buffer;
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
    //Cause a crash, looking for a solution...
    //const std::filesystem::path m_filepath = "Assets/sounds/rebond_SFX.ogg";

    sf::Sound m_rebond = sf::Sound(g_buffer);
public :
    Ball(sf::RenderWindow &par, sf::Texture *textures[5]);
    void inputs();
    void update(float dtTime);
    void draw();
    void startMove(bool is_FirstPlayerTurn);
    void move(float dtTime);
    void reverseDirection();
    sf::Vector2f getDirection();
    ~Ball();
};

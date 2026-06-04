#pragma once
#include <SFML/Graphics.hpp>

class Paddle : public sf::Sprite
{
private :
    sf::RenderWindow *m_parent;
    int m_pos_x = 0;
    int m_pos_y = 0;
    bool m_isLeftPaddle = true;
    int m_speed = 100;
    sf::Texture *m_textures[5];

public :
    Paddle(sf::RenderWindow &par, sf::Texture *textures[5], bool isLeftPaddle);
    void inputs();
    void update(float deltaTime);
    void draw();
};

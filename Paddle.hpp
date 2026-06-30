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
    sf::Texture *m_textures;
    bool m_isAI = false;


public :
    Paddle(sf::RenderWindow &par, sf::Texture &textures, bool isLeftPaddle);
    void inputs();
    void update(float deltaTime);
    void draw();
    void move(int direction, float dtTime);
    ~Paddle();
};

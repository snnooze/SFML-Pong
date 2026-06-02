#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"

class Game : public sf::View
{
private :
    sf::Font m_font;
    sf::RenderWindow *m_parent;
    int m_parentWidth = 0;
    int m_parentHeight = 0;
    int m_mode2Players = false;
    Paddle m_paddleLeft = Paddle(*this->m_parent, this->m_textures, true);
    Paddle m_paddleRight = Paddle(*this->m_parent, this->m_textures, false);
    //Ball
    int m_scorePlayer1 = 0;
    int m_scorePlayer2 = 0;
    int m_ballSpeed = 0;
    sf::Vector2f m_angle = {0, 0};
    sf::Texture *m_textures[5];
public :
    Game(sf::RenderWindow &par, sf::Texture textures[5], const sf::Font &font);
    void start();
    void reset();
    void over();
    void inputs();
    void update();
    void draw();
    //~Game();

};


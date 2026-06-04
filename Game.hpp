#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"

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
    Ball m_ball = Ball(*this->m_parent, this->m_textures);
    int m_scorePlayer1 = 0;
    int m_scorePlayer2 = 0;
    int m_ballSpeed = 10;
    sf::Vector2f m_angle = {0, 0};
    sf::Texture *m_textures[5];
    bool m_isActive = false;
    int movePlayer1 = 0;
    int movePlayer2 = 0;
public :
    Game(sf::RenderWindow &par, sf::Texture textures[5], const sf::Font &font);
    void start();
    void reset();
    void over();
    void inputs();
    void update(float dtt);
    void draw();
    void movePlayer1Up();
    void movePlayer1Down();
    void stopPlayer1();
    //~Game();

};


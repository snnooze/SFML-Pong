#pragma once
#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"

class Game
{
private :
    sf::Font m_font;
    sf::RenderWindow *m_parent;
    int m_parentWidth = 0;
    int m_parentHeight = 0;
    int m_mode2Players = false;
    Paddle m_paddleLeft = Paddle(*this->m_parent, *this->m_textures, true);
    Paddle m_paddleRight = Paddle(*this->m_parent, *this->m_textures, false);
    Ball m_ball = Ball(*this->m_parent, this->m_textures);
    int m_scorePlayer1 = 0;
    int m_scorePlayer2 = 0;
    sf::Text m_scorePlayer1Lbl = sf::Text(this->m_font, (char)this->m_scorePlayer1, 45);
    sf::Text m_scorePlayer2Lbl = sf::Text(this->m_font, (char)this->m_scorePlayer2, 45);
    int m_ballSpeed = 120;
    sf::Vector2f m_angle = {0, 0};
    sf::Texture *m_textures[6];
    bool m_isActive = false;
    bool m_is2PlayersMode;
    int movePlayer1 = 0;
    int movePlayer2 = 0;
    bool m_isFirstPlayerTurn = true;
    int m_gameMode = 1;
public :
    Game(sf::RenderWindow &par, sf::Texture textures[6], const sf::Font &font, bool is2PlayersMode);
    void start();
    void reset();
    void over();
    void inputs();
    void update(float dtt);
    void draw();
    void movePlayer1Up();
    void movePlayer1Down();
    void stopPlayer1();
    void movePlayer2Up();
    void movePlayer2Down();
    void stopPlayer2();
    void set2PlayersMode();
    void set1PlayersMode();
    void resetScore();
    void setVolume(float volume);
    ~Game();

};


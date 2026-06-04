#include "Game.hpp"
#include <iostream>

Game::Game(sf::RenderWindow &par, sf::Texture textures[5], const sf::Font &font) : sf::View() {
    //Get the parent Window
    this->m_parent = &par;

    //this->setCenter({this->m_parent->getSize().x / 2.f, this->m_parent->getSize().y / 2.f});

    //Loading the font for writing text on the view
    if(!this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    //Get the textures loaded at the game launch
    for(int i = 0; i<=4; i++)
    {
        this->m_textures[i] = &textures[i];
    }

    this->m_parentWidth = this->m_parent->getSize().x;
    this->m_parentHeight = this->m_parent->getSize().y;

    this->m_paddleLeft = Paddle(par, this->m_textures, true);
    this->m_paddleRight = Paddle(par, this->m_textures, false);
    this->m_ball = Ball(par, this->m_textures);

    this->m_paddleRight.setOrigin(this->m_paddleRight.getLocalBounds().getCenter());
    this->m_paddleRight.setPosition({this->m_parent->getSize().x - 50.f, this->m_parent->getSize().y/2.f});

    this->m_paddleLeft.setOrigin(this->m_paddleLeft.getLocalBounds().getCenter());
    this->m_paddleRight.setOrigin(this->m_paddleRight.getLocalBounds().getCenter());

    this->m_ball.setOrigin(this->m_ball.getLocalBounds().getCenter());

}

void Game::start()
{
    if (!this->m_isActive) {
        this->reset();
        this->m_isActive = true;
        this->m_ball.startMove();
    }
    //Reset
    //this->m_ball.setPosition({(float)this->m_parent->getSize().x/2,(float)this->m_parent->getSize().y/2});

    //active la balle

}

void Game::update(float dtTime)
{
    if (this->m_isActive)
    {

        if (this->m_ball.getGlobalBounds().findIntersection(this->m_paddleRight.getGlobalBounds()) || this->m_ball.getGlobalBounds().findIntersection(this->m_paddleLeft.getGlobalBounds())) {
            this->m_ball.reverseDirection();
        }

        if (this->m_ball.getGlobalBounds().position.x >= this->m_parent->getSize().x-25 || this->m_ball.getGlobalBounds().position.x <= 0)
        {
            this->m_isActive = false;
            this->reset();
        }

        this->m_ball.update(dtTime);

        sf::Vector2f pdr = {this->m_paddleRight.getPosition().x, this->m_paddleRight.getPosition().y + (250 * dtTime )* this->movePlayer1};
        sf::Vector2 pdl = {this->m_paddleLeft.getPosition().x, this->m_paddleLeft.getPosition().y + (250 * dtTime )* this->movePlayer2 };

        this->m_paddleRight.setPosition(pdr);
        this->m_paddleLeft.setPosition(pdl);

        this->m_paddleLeft.update(dtTime);
        this->m_paddleRight.update(dtTime);

    }
    else {
        this->reset();
    }
}

void Game::draw() {
    //Load the background image and set the positions
    sf::Sprite background( *this->m_textures[2]);
    background.setOrigin(background.getLocalBounds().position);
    background.setPosition({0,0});
    //Draw the background of the view
    this->m_parent->draw(background);

    this->m_parent->draw(this->m_paddleLeft);


    this->m_parent->draw(this->m_paddleRight);
    this->m_parent->draw(this->m_ball);
}

void Game::movePlayer1Up()
{
    if (this->m_isActive) {
        this->movePlayer1 = -1;
    }

}

void Game::movePlayer1Down()
{
    if (this->m_isActive) {
        this->movePlayer1 = +1;
    }

}

void Game::stopPlayer1() {
    if (this->m_isActive) {
        this->movePlayer1 = 0;
    }
}

void Game::reset() {
    this->m_paddleRight.setPosition({this->m_parent->getSize().x - 50.f, this->m_parent->getSize().y/2.f});
    this->m_ball.setPosition({(float)this->m_parent->getSize().x/2,(float)this->m_parent->getSize().y/2});
    this->m_paddleLeft.setPosition({50.f, this->m_parent->getSize().y/2.f});
}
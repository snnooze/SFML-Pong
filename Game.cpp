#include "Game.hpp"
#include <iostream>

Game::Game(sf::RenderWindow &par, sf::Texture textures[5], const sf::Font &font) : sf::View() {
    //Get the parent Window
    this->m_parent = &par;

    this->setCenter({this->m_parent->getSize().x / 2.f, this->m_parent->getSize().y / 2.f});

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

}

void Game::draw() {
    //Load the background image and set the positions
    sf::Sprite background( *this->m_textures[2]);
    background.setOrigin(background.getLocalBounds().getCenter());
    background.setPosition(this->getCenter());
    //Draw the background of the view
    this->m_parent->draw(background);

    this->m_parent->draw(this->m_paddleLeft);
    this->m_paddleLeft.setOrigin(this->m_paddleRight.getLocalBounds().getCenter());
    this->m_paddleLeft.setPosition({-(this->m_parent->getSize().x/2.f - 50), 0});
    this->m_parent->draw(this->m_paddleRight);
    this->m_paddleRight.setOrigin(this->m_paddleRight.getLocalBounds().getCenter());
    this->m_paddleRight.setPosition({this->m_parent->getSize().x/2.f - 50, 0});
}



#include <iostream>
#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen() : sf::View()
{        

}

void MainMenuScreen::initialize(sf::RenderWindow &par, sf::Texture textures[2], sf::Font &font)
{
    this->m_parent = &par;

    for(int i = 0; i<2; i++)
    {
        this->m_textures[i] = &textures[i];
    }

    this->m_font = font;

    this->m_parentWidth = par.getSize().x;
    this->m_parentHeight = par.getSize().y;
   
    this->m_stateText.setFont(this->m_font);
    this->m_stateText.setCharacterSize(30);
    this->m_stateText.setFillColor(sf::Color::White);
    this->m_stateText.setString("Main Menu");
    float longueur = this->m_stateText.getLocalBounds().getCenter().x;
    float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;
    this->m_stateText.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.f-hauteur));

}

void MainMenuScreen::inputs()
{

}

void MainMenuScreen::update(float dt)
{        
}

void MainMenuScreen::draw()
{
    //sf::Sprite spriteLogo = this->getSprite();
    //this->m_parent->draw(getSprite());

    sf::Sprite logo( *this->m_textures[0]);

    logo.setPosition(sf::Vector2f(this->m_parentWidth/2.f-556/2.f, this->m_parentHeight/2.f-184/2.f-150));

    this->m_parent->draw(logo);
    
    this->m_parent->draw(this->m_stateText);
}
#include <iostream>
#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen() : sf::View()
{        

}

void MainMenuScreen::initialize(sf::RenderWindow &par)
{
    this->m_parent = &par;

    this->m_parentWidth = par.getSize().x;
    this->m_parentHeight = par.getSize().y;

    sf::Texture tmpText;
   

    if(this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        this->m_stateText.setFont(this->m_font);
        this->m_stateText.setCharacterSize(30);
        this->m_stateText.setFillColor(sf::Color::White);
        this->m_stateText.setString("Main Menu");
        float longueur = this->m_stateText.getLocalBounds().getCenter().x;
        float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;
        this->m_stateText.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.f-hauteur));
    }
    else
    {
        std::cout << "Font cannot be loaded";
    }

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

    sf::Texture tmpText;
    if(tmpText.loadFromFile("Assets/Graphics/logo.png"))
    {
        sf::Sprite tmpSPrite(tmpText);

        tmpSPrite.setPosition(sf::Vector2f(this->m_parentWidth/2.f-556/2.f, this->m_parentHeight/2.f-184/2.f-150));

        this->m_parent->draw(tmpSPrite);
    }
    
    this->m_parent->draw(this->m_stateText);
}
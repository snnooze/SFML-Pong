#include <iostream>
#include <SFML/Graphics.hpp>
#include "PauseScreen.hpp"

PauseScreen::PauseScreen()
{
    
        
}

void PauseScreen::initialize(sf::RenderWindow &parent)
{
    this->m_parent = &parent;

    this->m_parentWidth = parent.getSize().x;
    this->m_parentHeight = parent.getSize().y;

    if(this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        this->m_stateText.setFont(this->m_font);
        this->m_stateText.setCharacterSize(30);
        this->m_stateText.setFillColor(sf::Color::White);
        this->m_stateText.setString("Pause");
        float longueur = this->m_stateText.getLocalBounds().getCenter().x;
        std::cout << longueur;
        float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;
        this->m_stateText.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.F-hauteur));
    }
    else
    {
        std::cout << "Font cannot be loaded";
    }
}

void PauseScreen::inputs()
{

}

void PauseScreen::update(float dt)
{
        
        

}

void PauseScreen::draw()
{
     this->m_parent->draw(this->m_stateText);
}
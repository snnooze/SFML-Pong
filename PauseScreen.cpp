#include <iostream>
#include "PauseScreen.hpp"

PauseScreen::PauseScreen(RenderWindow &parent) : sf::View()
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
        float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;


    }
    else
    {
        std::cout << "Font cannot be loaded";
    }
}

void PauseScreen::inputs()
{
    //Todo : bouton vers menu principal

    //Todo : bouton vers Quitter
}

void PauseScreen::update(float dt)
{
}

void PauseScreen::draw()
{
    this->m_stateText.setOrigin(this->m_stateText.getLocalBounds().position);
    this->m_stateText.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_stateText.getLocalBounds().size.x , 15+30+184));
     this->m_parent->draw(this->m_stateText);
}

PauseScreen::~PauseScreen() = default;
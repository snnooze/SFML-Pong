#include <iostream>
#include "Button.hpp"

Button::Button(sf::Texture *textures, sf::IntRect size) : sf::Sprite(*textures, size)
{

}

void Button::initialize(sf::Texture *textures)
{
    this->setTexture(textures[1]);
}

void Button::update()
{

    

}

void Button::setHover()
{

    if(this->m_position == 1)
    {
        this->setTextureRect(sf::IntRect(sf::Vector2(0, this->m_position*64), sf::Vector2(sf::Vector2(150, 64))));
    }
    else
    {
        this->setTextureRect(sf::IntRect(sf::Vector2(0, this->m_position*64), sf::Vector2(sf::Vector2(150, 64))));
    }
}
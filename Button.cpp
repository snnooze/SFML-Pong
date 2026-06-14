#include "Button.hpp"
#include <iostream>

Button::Button(sf::Texture *textures, sf::IntRect size, bool isSmallButton) : sf::Sprite(*textures, size)
{
    if (!isSmallButton) {
        this->setTexture(textures[1]);
    }
    else {
        this->setTexture(textures[5]);
    }

}

void Button::initialize(sf::Texture *textures)
{

}

void Button::update()
{

}

void Button::setHover()
{

    this->setTextureRect(sf::IntRect(sf::Vector2(0, this->m_position*64), sf::Vector2(sf::Vector2(150, 64))));
}

Button::~Button() = default;
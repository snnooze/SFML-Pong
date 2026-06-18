#include "Button.hpp"
#include <iostream>

Button::Button(sf::Texture *textures[6], sf::IntRect size, bool isSmallButton) : sf::Sprite(*textures[1], size)
{
    this->isSmallButton = isSmallButton;
    if (!isSmallButton) {
        this->setTexture(*textures[1]);
    }
    else {
        this->setTexture(*textures[5]);
    }

}

void Button::update()
{

}

void Button::setVolumeBtn(float volume) {
    this->m_sound.setVolume(this->m_sound.getVolume()+volume);

    if (this->m_sound.getVolume() > 100) {
        this->m_sound.setVolume(100);
    }
    if (this->m_sound.getVolume() < 0) {
        this->m_sound.setVolume(0);
    }

}

void Button::setHover()
{
    if (!this->isSmallButton) {
        this->setTextureRect(sf::IntRect(sf::Vector2(0, this->m_position*64), sf::Vector2(sf::Vector2(150, 64))));
    }
    else {
        this->setTextureRect(sf::IntRect(sf::Vector2(0, this->m_position*60), sf::Vector2(sf::Vector2(60, 60))));
    }

    if (this->previousPosition != this->m_position) {
        if (!this->m_firstAffichage) {
            this->m_sound.play();
            this->previousPosition = this->m_position;
            this->m_firstAffichage = false;
        }
        else {
            this->previousPosition = this->m_position;
            this->m_firstAffichage = false;
        }


    }

}

Button::~Button() = default;
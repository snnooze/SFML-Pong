#include "Button.hpp"
#include <iostream>

Button::Button(sf::Texture &textures, sf::IntRect size, bool isSmallButton) : sf::Sprite(textures, size)
{
    m_isSmallButton = isSmallButton;

    m_textures = &textures;

    setTexture(*m_textures);

    if (!m_isSmallButton) {
        setTextureRect(sf::IntRect({1847, 0},{150, 193/3}));
    }
    else {
        setTextureRect(sf::IntRect({1289, 453},{60, 60}));
    }

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
    if (!this->m_isSmallButton) {
        this->setTextureRect(sf::IntRect(sf::Vector2(1847, this->m_position*64), sf::Vector2(sf::Vector2(150, 64))));
    }
    else {
        this->setTextureRect(sf::IntRect(sf::Vector2(1289, 453+this->m_position*60), sf::Vector2(sf::Vector2(60, 60))));
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
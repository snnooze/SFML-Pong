#include "Paddle.hpp"

#include <iostream>

Paddle::Paddle(sf::RenderWindow &par, sf::Texture *textures[5], bool isLeftPaddle, bool isAI) : Sprite(*textures[4])
{
    this->m_parent = &par;
    this->m_isAI = isAI;

    //Get the textures loaded at the game launch
    for(int i = 0; i<=4; i++)
    {
        this->m_textures[i] = textures[i];
    }

    this->setTexture(*textures[4]);

    this->m_isLeftPaddle = isLeftPaddle;

    if (isLeftPaddle) {

        this->setRotation(sf::degrees(180));
        //this->setOrigin({this->getLocalBounds().getCenter().x, this->getLocalBounds().getCenter().y});

    }
    else
    {
        //this->setOrigin({this->getLocalBounds().getCenter().x, this->getLocalBounds().getCenter().y});

    }
    sf::IntRect rect = {{0, 0},{40,99},};
    this->setTextureRect(rect);
}

void Paddle::update(float deltaTime) {

    //Borne pour empecher le paddle de sortir de sa zone de jeu
    if (this->getGlobalBounds().getCenter().y <= 0 || this->getGlobalBounds().position.y >= this->m_parent->getSize().y - this->getLocalBounds().getCenter().y) {
        if (this->getGlobalBounds().getCenter().y <= 0) {
            this->setPosition({this->getPosition().x, 0.5f});
            //std::cout << "Paddle : " << this->getPosition().x << " " << this->getPosition().y << std::endl;
        }
        else {
            this->setPosition({this->getPosition().x, this->m_parent->getSize().y+1.f});
        }
    }
}

bool Paddle::isAI() {
    return this->m_isAI;
}

Paddle::~Paddle() =default;
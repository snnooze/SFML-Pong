#include "Paddle.hpp"

Paddle::Paddle(sf::RenderWindow &par, sf::Texture *textures[5], bool isLeftPaddle) : Sprite(*textures[4])
{
    this->m_parent = &par;

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

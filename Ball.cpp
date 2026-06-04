#include "Ball.hpp"

#include <iostream>
#include <random>
#include <time.h>

Ball::Ball(sf::RenderWindow &par, sf::Texture *textures[5]) : Sprite(*textures[4])
{
    this->m_parent = &par;

    //Get the textures loaded at the game launch
    for(int i = 0; i<=4; i++)
    {
        this->m_textures[i] = textures[i];
    }

    this->setTexture(*textures[3]);

    sf::IntRect rect = {{0, 0},{25,25},};
    this->setTextureRect(rect);
}

void Ball::startMove()
{
     std::random_device rd;
     std::mt19937 gen(rd());
     std::uniform_real_distribution<float> distrib(0.0, 1.0);
    //
    float direction1 = distrib(gen);
    //
    float direction2 = distrib(gen);

    //srand(time(NULL));
    //float direction1 = rand()%(0 0 + 1);

    std::cout << direction1 << "." << direction2 << "\n";

    std::uniform_real_distribution<float> distrib2(-1.0, 1.0);

    float direction3 = distrib2(gen);

    if (direction3 > 0)
    {
        this->m_ballDirection= {direction1, direction2};
    }
    else
    {
        this->m_ballDirection= {-direction1, -direction2};
    }

    MyHelpers mh;

    this->m_ballDirection = mh.normalize(this->m_ballDirection);


}

void Ball::update(float dtTime) {
    // if (this->getPosition().x > this->m_parent->getSize().x - this->getLocalBounds().size.x || this->getPosition().x < 0 - this->getLocalBounds().size.x)
    // {
    //     this->m_ballDirection.x = -this->m_ballDirection.x;
    // }

    if (this->getPosition().y > this->m_parent->getSize().y - this->getLocalBounds().size.x || this->getPosition().y < 0 - this->getLocalBounds().size.x)
    {
        this->m_ballDirection.y = -this->m_ballDirection.y;
    }

    sf::Vector2f b = {this->getPosition().x + (this->getDirection().x * this->m_speed * dtTime), this->getPosition().y + (this->getDirection().y * this->m_speed * dtTime) };

    this->setPosition(b);
}

void Ball::move(float delta)
{
    //this->m_ballDirection *= (delta * 100);
}

void Ball::reverseDirection() {
    this->m_ballDirection.x = -this->m_ballDirection.x;
}

sf::Vector2f Ball::getDirection()
{
    return this->m_ballDirection;
}

Ball::~Ball() = default;
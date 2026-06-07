#include "Ball.hpp"

#include <iostream>
#include <random>

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

    if (!this->m_buffer.loadFromFile("Assets/Sounds/rebond_SFX.ogg")) {
        std::cout << "Failed to load sound! \n";
    }
}

void Ball::startMove(bool is_FirstPlayerTurn = true)
{
     std::random_device rd;
     std::mt19937 gen(rd());
     std::uniform_real_distribution<float> distrib(0.4, 1.0);
    //
    float direction1 = distrib(gen);
    //
    float direction2 = distrib(gen);

    std::cout << direction1 << "." << direction2 << "\n";

    if (is_FirstPlayerTurn)
    {
        this->m_ballDirection= {direction1, direction2};
    }
    else
    {
        this->m_ballDirection= {-direction1, direction2};
    }

    this->m_ballDirection = this->m_ballDirection.normalized();


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
    this->setPosition({this->getPosition().x + 0.5f, this->getPosition().y});
    this->m_ballDirection.x = -this->m_ballDirection.x;



         if(this->m_rebond.getStatus() == sf::SoundSource::Status::Stopped) {

            this->m_rebond.setBuffer(this->m_buffer);
            this->m_rebond.play();

        }


}

sf::Vector2f Ball::getDirection()
{
    return this->m_ballDirection;
}

Ball::~Ball() = default;
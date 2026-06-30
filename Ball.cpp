#include "Ball.hpp"

Ball::Ball(sf::RenderWindow &par, sf::Texture &textures) : Sprite(textures)
{
    this->m_parent = &par;

    this->m_textures = &textures;

    this->setTexture(*this->m_textures);

    sf::IntRect rect = {{1999, 101},{25,25},};
    this->setTextureRect(rect);

    if (!Globals::g_buffer.loadFromFile("Assets/sounds/rebond_SFX.ogg")) {
         std::cout<<"Error loading SFX"<<std::endl;
    }

    if (!Globals::g_bufferOut.loadFromFile("Assets/sounds/sfx_lose.ogg")) {
        std::cout<<"Error loading SFX lose ! "<<std::endl;
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
    std::uniform_real_distribution<float> distrib2(-1.0, 1.0);

    float direction2 = distrib2(gen);

    while ( direction2 == 0.0 ) {
        direction2 = distrib2(gen);
    }

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
    this->m_ballDirection *= (delta * 100);
}

void Ball::reverseDirection() {
    //this->setPosition({this->getPosition().x + 0.5f, this->getPosition().y});

    if (this->getPosition().x > this->m_parent->getSize().x/2.0) {
        this->setPosition({this->getPosition().x - 2.0f, this->getPosition().y});
    }
    else {
        this->setPosition({this->getPosition().x + 2.0f, this->getPosition().y});
    }

    this->m_ballDirection.x = -this->m_ballDirection.x;

        if(this->m_rebond.getStatus() != sf::SoundSource::Status::Playing) {
             this->m_rebond.setBuffer(Globals::g_buffer);
             this->m_rebond.play();
             std::cout << "Play SFX" << "\n";
         }

}

void Ball::emitOutSound() {
    m_out.setBuffer(Globals::g_bufferOut);
    m_out.play();
}

void Ball::setVolume(float volume) {
    this->m_rebond.setVolume(this->m_rebond.getVolume() + volume);
    this->m_out.setVolume(this->m_rebond.getVolume() + volume);

    if (this->m_rebond.getVolume() <0) {
        this->m_rebond.setVolume(0);
    }
    else if (this->m_rebond.getVolume() > 100) {
        this->m_rebond.setVolume(100);
    }

    if (this->m_out.getVolume() <0) {
        this->m_out.setVolume(0);
    }
    else if (this->m_out.getVolume() > 100) {
        this->m_out.setVolume(100);
    }

}

sf::Vector2f Ball::getDirection()
{
    return this->m_ballDirection;
}

Ball::~Ball() = default;
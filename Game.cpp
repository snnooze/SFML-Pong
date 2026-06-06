#include "Game.hpp"
#include <iostream>

Game::Game(sf::RenderWindow &par, sf::Texture textures[5], const sf::Font &font, bool is_2PlayersMode) : sf::View() {
    //Get the parent Window
    this->m_parent = &par;

    //this->setCenter({this->m_parent->getSize().x / 2.f, this->m_parent->getSize().y / 2.f});

    //Loading the font for writing text on the view
    if(!this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    //Get the textures loaded at the game launch
    for(int i = 0; i<=4; i++)
    {
        this->m_textures[i] = &textures[i];
    }

    this->m_parentWidth = this->m_parent->getSize().x;
    this->m_parentHeight = this->m_parent->getSize().y;


    if (this->m_is2PlayersMode) {
        this->m_paddleLeft = Paddle(par, this->m_textures, true);
    }
    else {
        this->m_paddleLeft = Paddle(par, this->m_textures, true);
    }

    this->m_paddleRight = Paddle(par, this->m_textures, false);
    this->m_ball = Ball(par, this->m_textures);

    this->m_paddleRight.setOrigin(this->m_paddleRight.getLocalBounds().getCenter());
    this->m_paddleRight.setPosition({this->m_parent->getSize().x - 50.f, this->m_parent->getSize().y/2.f});

    this->m_paddleLeft.setOrigin(this->m_paddleLeft.getLocalBounds().getCenter());
    //this->m_paddleRight.setOrigin(this->m_paddleRight.getLocalBounds().getCenter());

    this->m_ball.setOrigin(this->m_ball.getLocalBounds().getCenter());

    this->m_scorePlayer1Lbl = sf::Text(this->m_font, "0", 45);
    this->m_scorePlayer2Lbl = sf::Text(this->m_font, "0", 45);

    this->m_scorePlayer1Lbl.setFillColor(sf::Color::Transparent);
    this->m_scorePlayer2Lbl.setFillColor(sf::Color::Transparent);

    this->m_scorePlayer1Lbl.setOutlineThickness(1.5);
    this->m_scorePlayer2Lbl.setOutlineThickness(1.5);

    this->m_scorePlayer1Lbl.setOutlineColor(sf::Color::Black);
    this->m_scorePlayer2Lbl.setOutlineColor(sf::Color::Black);


}

void Game::start()
{
    if (!this->m_isActive) {
        this->reset();
        this->m_isActive = true;
        this->m_ball.startMove();
    }
    //Reset
    //this->m_ball.setPosition({(float)this->m_parent->getSize().x/2,(float)this->m_parent->getSize().y/2});

    //active la balle

}

void Game::set2PlayersMode() {
    //this->m_paddleLeft = Paddle(*this->m_parent, this->m_textures, true);
    this->m_is2PlayersMode = true;
    this->stopPlayer2();
}

void Game::set1PlayersMode() {
    //this->m_paddleLeft = Paddle(*this->m_parent, this->m_textures, true);
    this->m_is2PlayersMode = false;
    //this->m_paddleLeft.move(0, 0);
}

void Game::update(float dtTime)
{
    if (this->m_isActive)
    {
    //Gestion du heurt de la balle sur les Paddles
        if (this->m_ball.getGlobalBounds().findIntersection(this->m_paddleRight.getGlobalBounds()) || this->m_ball.getGlobalBounds().findIntersection(this->m_paddleLeft.getGlobalBounds())) {
            this->m_ball.reverseDirection();
        }
        //Gestion de sortie de balle sur la gauche et droite et remise de la balle au centre
        if (this->m_ball.getGlobalBounds().position.x >= this->m_parent->getSize().x-25 || this->m_ball.getGlobalBounds().position.x <= 0)
        {
            //Notation des scores
            if (this->m_ball.getGlobalBounds().position.x >= this->m_parent->getSize().x-25) {
                this->m_scorePlayer2+=1;
                this->m_scorePlayer2Lbl.setString(std::to_string(m_scorePlayer2));
            }
            else {
                this->m_scorePlayer1+=1;
                this->m_scorePlayer1Lbl.setString(std::to_string(m_scorePlayer1));
            }


            this->m_isActive = false;
            this->reset();
        }

        this->m_ball.update(dtTime);


        MyHelpers mh;

        if (this->m_is2PlayersMode) {


            this->m_paddleLeft.move(this->movePlayer2, dtTime);

            //sf::Vector2 pdl = {this->m_paddleLeft.getPosition().x, this->m_paddleLeft.getPosition().y + (250 * dtTime )* this->movePlayer2 };
            //this->m_paddleLeft.setPosition(pdl);

        }
        else {

            if (this->m_ball.getGlobalBounds().getCenter().y != this->m_paddleLeft.getPosition().y) {
                if (this->m_ball.getGlobalBounds().getCenter().y < this->m_paddleLeft.getPosition().y) {
                    this->movePlayer2 = -1;
                }
                else {
                    this->movePlayer2 = +1;
                }


                this->m_paddleLeft.move(this->movePlayer2, dtTime);

            }

        }
        // sf::Vector2f pdr = {this->m_paddleRight.getPosition().x, this->m_paddleRight.getPosition().y + (250 * dtTime )* this->movePlayer1};
        // this->m_paddleRight.setPosition(pdr);

        this->m_paddleRight.move(this->movePlayer1, dtTime);


        this->m_paddleLeft.update(dtTime);
        this->m_paddleRight.update(dtTime);



    }
    else {
        this->reset();
    }

    float centerTerrain = (float)this->m_parent->getSize().x/2.f;

    this->m_scorePlayer1Lbl.setLineAlignment(sf::Text::LineAlignment::Center);
    this->m_scorePlayer2Lbl.setLineAlignment(sf::Text::LineAlignment::Center);

    this->m_scorePlayer1Lbl.setPosition({ centerTerrain + 50.f, +20.f});
    this->m_scorePlayer2Lbl.setPosition({centerTerrain - 50.f , +20.f});
}

void Game::draw() {
    //Load the background image and set the positions
    sf::Sprite background( *this->m_textures[2]);
    background.setOrigin(background.getLocalBounds().position);
    background.setPosition({0,0});
    //Draw the background of the view
    this->m_parent->draw(background);

    this->m_parent->draw(this->m_paddleLeft);


    this->m_parent->draw(this->m_paddleRight);
    this->m_parent->draw(this->m_ball);

    this->m_parent->draw(this->m_scorePlayer1Lbl);
    this->m_parent->draw(this->m_scorePlayer2Lbl);
}

void Game::movePlayer1Up()
{
    if (this->m_isActive) {
        this->movePlayer1 = -1;
    }

}

void Game::movePlayer1Down()
{
    if (this->m_isActive) {
        this->movePlayer1 = 1;
    }

}

void Game::stopPlayer1() {
    if (this->m_isActive) {
        this->movePlayer1 = 0;
    }
}

void Game::reset() {
    this->m_isActive = false;
    this->m_paddleRight.setPosition({this->m_parent->getSize().x - 50.f, this->m_parent->getSize().y/2.f});
    this->m_ball.setPosition({(float)this->m_parent->getSize().x/2,(float)this->m_parent->getSize().y/2});
    this->m_paddleLeft.setPosition({50.f, this->m_parent->getSize().y/2.f});
}

void Game::movePlayer2Up()
{
    if (this->m_isActive && this->m_is2PlayersMode) {
        this->movePlayer2 = -1;
    }

}

void Game::movePlayer2Down()
{
    if (this->m_isActive && this->m_is2PlayersMode) {
        this->movePlayer2 = 1;
    }

}

void Game::stopPlayer2() {
    if (this->m_isActive && this->m_is2PlayersMode) {
        this->movePlayer2 = 0;
    }
}

Game::~Game() = default;
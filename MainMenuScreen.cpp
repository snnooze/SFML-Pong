#include <iostream>
#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen() : sf::View()
{        

}

void MainMenuScreen::initialize(sf::RenderWindow &par, sf::Texture textures[2], sf::Font &font)
{
    this->m_parent = &par;

    this->m_font = font;

    for(int i = 0; i<2; i++)
    {
        this->m_textures[i] = &textures[i];
    }

    this->m_parentWidth = par.getSize().x;
    this->m_parentHeight = par.getSize().y;
   
    this->m_stateText.setFont(this->m_font);
    this->m_stateText.setCharacterSize(30);
    this->m_stateText.setFillColor(sf::Color::White);
    this->m_stateText.setString("Main Menu");
    float longueur = this->m_stateText.getLocalBounds().getCenter().x;
    float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;
    this->m_stateText.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.f-hauteur-30));

    this->m_1PlayerBtn = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_1PlayerBtn.initialize(*this->m_textures);

    this->m_labelTxt.setFont(this->m_font);
    this->m_labelTxt.setString("1 Player");
    this->m_labelTxt.setCharacterSize(25);
    this->m_labelTxt.setFillColor(sf::Color::White);
    longueur = this->m_labelTxt.getLocalBounds().getCenter().x;
    hauteur = this->m_labelTxt.getGlobalBounds().getCenter().y;
    this->m_labelTxt.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.f-hauteur+50));

    this->m_2PlayersBtn = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_2PlayersBtn.initialize(*this->m_textures);

    this->m_label2playersTxt.setFont(this->m_font);
    this->m_label2playersTxt.setString("2 Players");
    this->m_label2playersTxt.setCharacterSize(25);
    this->m_label2playersTxt.setFillColor(sf::Color::White);
    longueur = this->m_label2playersTxt.getLocalBounds().getCenter().x;
    hauteur = this->m_label2playersTxt.getGlobalBounds().getCenter().y;
    this->m_label2playersTxt.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.f-hauteur+50+64+20));


    this->m_settingsButton = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_settingsButton.initialize(*this->m_textures);

    this->m_settingsLabelTxt.setFont(this->m_font);
    this->m_settingsLabelTxt.setString("Settings");
    this->m_settingsLabelTxt.setCharacterSize(25);
    this->m_settingsLabelTxt.setFillColor(sf::Color::White);
    longueur = this->m_settingsLabelTxt.getLocalBounds().getCenter().x;
    hauteur = this->m_settingsLabelTxt.getGlobalBounds().getCenter().y;
    this->m_settingsLabelTxt.setPosition(sf::Vector2f(this->m_parentWidth/2.f-longueur , this->m_parentHeight/2.f-hauteur+50+64+20+64+20));

}

void MainMenuScreen::inputs()
{

}

void MainMenuScreen::update(float dt)
{
    //std::cout << "Set hover \n";
    
    switch (this->m_menuPosition)
    {
    case 1:
        this->m_1PlayerBtn.m_position = 1; 
        this->m_2PlayersBtn.m_position = 0;
        this->m_settingsButton.m_position = 0;
        break;
    case 2:
        this->m_1PlayerBtn.m_position = 0; 
        this->m_2PlayersBtn.m_position = 1;
        this->m_settingsButton.m_position = 0;
    break;
    case 3:
        this->m_1PlayerBtn.m_position = 0; 
        this->m_2PlayersBtn.m_position = 0;
        this->m_settingsButton.m_position = 1;
        break;
    default:
        this->m_1PlayerBtn.m_position = 0; 
        this->m_2PlayersBtn.m_position = 0;
         this->m_settingsButton.m_position = 0;
        break;
    }

    this->m_1PlayerBtn.setHover();
    this->m_2PlayersBtn.setHover();
    this->m_settingsButton.setHover();

}

void MainMenuScreen::draw()
{
    //sf::Sprite spriteLogo = this->getSprite();
    //this->m_parent->draw(getSprite());

    sf::Sprite logo( *this->m_textures[0]);

    logo.setPosition(sf::Vector2f(this->m_parentWidth/2.f-556/2.f, this->m_parentHeight/2.f-184/2.f-150));

    this->m_parent->draw(logo);
    
    this->m_parent->draw(this->m_stateText);

    this->m_1PlayerBtn.setPosition(sf::Vector2f(this->m_parentWidth/2.f-150/2.f, this->m_parentHeight/2.f-64/2.f+50.f));

    this->m_parent->draw(this->m_1PlayerBtn);

    this->m_parent->draw(this->m_labelTxt);

    this->m_2PlayersBtn.setPosition(sf::Vector2f(this->m_parentWidth/2.f-150/2.f, this->m_parentHeight/2.f-64/2.f+50+64+20.f));

    this->m_parent->draw(this->m_2PlayersBtn);

    this->m_parent->draw(this->m_label2playersTxt);

    this->m_settingsButton.setPosition(sf::Vector2f(this->m_parentWidth/2.f-150/2.f, this->m_parentHeight/2.f-64/2.f+50+64+20+64+20.f));

    this->m_parent->draw(this->m_settingsButton);

    this->m_parent->draw(this->m_settingsLabelTxt);
}
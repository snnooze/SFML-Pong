#include <iostream>
#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen(sf::RenderWindow &par, sf::Texture textures[2], const sf::Font &font) : sf::View()
{        
    //Get the parent Window
    this->m_parent = &par;

    //Loading the font for writing text on the view
    if(!this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    //Get the textures loaded at the game launch
    for(int i = 0; i<=2; i++)
    {
        this->m_textures[i] = &textures[i];
    }

    this->m_parentWidth = this->m_parent->getSize().x;
    this->m_parentHeight = this->m_parent->getSize().y;

    //Initialize the Menu Title
    this->m_stateText = sf::Text(this->m_font, "MainMenu", 30);
    this->m_stateText.setFillColor(sf::Color::White);

    //Initialize the 1 PLayer button
    this->m_1PlayerBtn = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_1PlayerBtn.initialize(*this->m_textures);
    //Initialize the Text of the button
    this->m_labelTxt = sf::Text(this->m_font, "1 Player", 25);
    this->m_labelTxt.setFillColor(sf::Color::White);

    //Initialize the 2 players Button
    this->m_2PlayersBtn = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_2PlayersBtn.initialize(*this->m_textures);
    //Initialize the 2 Players Text for the button
    this->m_label2playersTxt = sf::Text(this->m_font, "2 Players", 20);
    this->m_label2playersTxt.setFillColor(sf::Color::White);

    //Initialize the Settings Button
    this->m_settingsButton = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_settingsButton.initialize(*this->m_textures);
    //Initialize the Settings Text
    this->m_settingsLabelTxt = sf::Text(this->m_font, "Settings", 25);
    this->m_settingsLabelTxt.setFillColor(sf::Color::White);

    //Initialize the Scores Button
    this->m_scoresButton = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_scoresButton.initialize(*this->m_textures);
    //Initialize the Scores Text
    this->m_scoresLabelTxt = sf::Text(this->m_font, "Scores", 25);
    this->m_scoresLabelTxt.setFillColor(sf::Color::White);

    //Initialize the Exit Button
    this->m_exitButton = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
    this->m_exitButton.initialize(*this->m_textures);
    //Initialize the Scores Text
    this->m_exitLabelTxt = sf::Text(this->m_font, "Quit", 25);
    this->m_exitLabelTxt.setFillColor(sf::Color::White);

}

void MainMenuScreen::inputs()
{

}

void MainMenuScreen::update(float dt)
{
    //moving between the main menu button with the arrows of the keyboard switch they state
    switch (this->m_menuPosition)
    {
    case 1:
        this->m_1PlayerBtn.m_position = 1; 
        this->m_2PlayersBtn.m_position = 0;
        this->m_settingsButton.m_position = 0;
        this->m_scoresButton.m_position = 0;
        this->m_exitButton.m_position = 0;
        break;
    case 2:
        this->m_1PlayerBtn.m_position = 0; 
        this->m_2PlayersBtn.m_position = 1;
        this->m_settingsButton.m_position = 0;
        this->m_scoresButton.m_position = 0;
        this->m_exitButton.m_position = 0;
    break;
    case 3:
        this->m_1PlayerBtn.m_position = 0; 
        this->m_2PlayersBtn.m_position = 0;
        this->m_settingsButton.m_position = 1;
        this->m_scoresButton.m_position = 0;
        this->m_exitButton.m_position = 0;
        break;
    case 4:
        this->m_1PlayerBtn.m_position = 0;
        this->m_2PlayersBtn.m_position = 0;
        this->m_settingsButton.m_position = 0;
        this->m_scoresButton.m_position = 1;
        this->m_exitButton.m_position = 0;
        break;
    case 5:
       this->m_1PlayerBtn.m_position = 0;
       this->m_2PlayersBtn.m_position = 0;
       this->m_settingsButton.m_position = 0;
       this->m_scoresButton.m_position = 0;
       this->m_exitButton.m_position = 1;
       break;
    default:
        this->m_1PlayerBtn.m_position = 0; 
        this->m_2PlayersBtn.m_position = 0;
         this->m_settingsButton.m_position = 0;
         this->m_scoresButton.m_position = 0;
         this->m_exitButton.m_position = 0;
        break;
    }

    this->m_1PlayerBtn.setHover();
    this->m_2PlayersBtn.setHover();
    this->m_settingsButton.setHover();
    this->m_scoresButton.setHover();
    this->m_exitButton.setHover();

}

void MainMenuScreen::draw()
{
    //Load the background image and set the positions
    sf::Sprite background( *this->m_textures[2]);
    background.setOrigin(background.getLocalBounds().position);
    background.setPosition({0,0});
    //Draw the background of the view
    this->m_parent->draw(background);

    //Load end draw the logo of the game
    sf::Sprite logo( *this->m_textures[0]);
    logo.setOrigin(logo.getLocalBounds().position);
    logo.setPosition({(this->m_parent->getSize().x/2.f) - (logo.getLocalBounds().size.x/2),15});
    this->m_parent->draw(logo);

    //Draw the "main menu title
    this->m_stateText.setPosition({(this->m_parent->getSize().x/2.f) - (this->m_stateText.getLocalBounds().size.x/2), 15 + 15 + logo.getLocalBounds().size.y});
    this->m_parent->draw(this->m_stateText);

    //Draw the "1 Player Button"
    this->m_1PlayerBtn.setOrigin(this->m_1PlayerBtn.getLocalBounds().position);
    this->m_1PlayerBtn.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 20 + this->m_stateText.getLocalBounds().size.y));
    this->m_parent->draw(this->m_1PlayerBtn);

    //Write the text for the button 1 PLayer
    this->m_parent->draw(this->m_labelTxt);
    this->m_labelTxt.setOrigin(this->m_labelTxt.getLocalBounds().getCenter());
    this->m_labelTxt.setPosition(this->m_1PlayerBtn.getGlobalBounds().getCenter());
    //this->m_labelTxt.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_labelTxt.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 30 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y/2));

    //Draw the "2 Players" Button
    this->m_2PlayersBtn.setOrigin(this->m_2PlayersBtn.getLocalBounds().position);
    this->m_2PlayersBtn.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 20*2 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y));
    this->m_parent->draw(this->m_2PlayersBtn);

    //Write the text of the button 2 PLayers
    this->m_parent->draw(this->m_label2playersTxt);
    this->m_label2playersTxt.setOrigin(this->m_label2playersTxt.getLocalBounds().getCenter());
    this->m_label2playersTxt.setPosition(this->m_2PlayersBtn.getGlobalBounds().getCenter());
    //this->m_label2playersTxt.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 30*2 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y));

    //Draw the Settings Button
    this->m_settingsButton.setOrigin(this->m_settingsButton.getLocalBounds().position);
    this->m_settingsButton.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 20*3 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y + this->m_2PlayersBtn.getLocalBounds().size.y));
    this->m_parent->draw(this->m_settingsButton);

    //Write the Settings Text on the BUtton
    this->m_parent->draw(this->m_settingsLabelTxt);
    this->m_settingsLabelTxt.setOrigin(this->m_settingsLabelTxt.getLocalBounds().getCenter());
    this->m_settingsLabelTxt.setPosition(this->m_settingsButton.getGlobalBounds().getCenter());
    //this->m_settingsLabelTxt.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 30*3 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y + this->m_2PlayersBtn.getLocalBounds().size.y));

    //Draw the Scores Button
    this->m_scoresButton.setOrigin(this->m_scoresButton.getLocalBounds().position);
    this->m_scoresButton.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 20*4 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y + this->m_2PlayersBtn.getLocalBounds().size.y + this->m_settingsButton.getLocalBounds().size.y));
    this->m_parent->draw(this->m_scoresButton);
    //Write the Score Text on the BUtton
    this->m_parent->draw(this->m_scoresLabelTxt);
    this->m_scoresLabelTxt.setOrigin(this->m_scoresLabelTxt.getLocalBounds().getCenter());
    this->m_scoresLabelTxt.setPosition(this->m_scoresButton.getGlobalBounds().getCenter());

    //Draw the Quit Button
    this->m_exitButton.setOrigin(this->m_exitButton.getLocalBounds().position);
    this->m_exitButton.setPosition(sf::Vector2f(this->m_parent->getSize().x/2.f-this->m_1PlayerBtn.getLocalBounds().size.x/2, 15 + 30 + logo.getLocalBounds().size.y + 20*5 + this->m_stateText.getLocalBounds().size.y + this->m_1PlayerBtn.getLocalBounds().size.y + this->m_2PlayersBtn.getLocalBounds().size.y + this->m_settingsButton.getLocalBounds().size.y +  this->m_scoresButton.getLocalBounds().size.y));
    this->m_parent->draw(this->m_exitButton);
    //Write the Score Text on the BUtton
    this->m_parent->draw(this->m_exitLabelTxt);
    this->m_exitLabelTxt.setOrigin(this->m_exitLabelTxt.getLocalBounds().getCenter());
    this->m_exitLabelTxt.setPosition(this->m_exitButton.getGlobalBounds().getCenter());

}

MainMenuScreen::~MainMenuScreen() = default;
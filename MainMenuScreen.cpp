#include <iostream>
#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen(sf::RenderWindow &par, sf::Texture &textures)
{        
    //Get the parent Window
    m_parent = &par;

    m_textures = textures;

    //Loading the font for writing text on the view
    if(!m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    this->m_parentWidth = this->m_parent->getSize().x;
    this->m_parentHeight = this->m_parent->getSize().y;


    if (!Globals::g_bufferMenu.loadFromFile("Assets/Sounds/sfx_win.ogg")) {
         std::cout << "Could not load sound effects ZAP !." << std::endl;
    }

}

void MainMenuScreen::showMenu()
{
    //Load the background image and set the positions
    m_background.setTexture(m_textures);
    m_background.setTextureRect(sf::IntRect({0,0}, {1287, 726}));
    m_background.setOrigin(m_background.getLocalBounds().getCenter());
    m_background.setPosition({m_parent->getSize().x/2.f,m_parent->getSize().y/2.f});

    //Main Menu Title
    m_stateText = sf::Text(m_font, "MainMenu", 30);
    m_stateText.setFillColor(sf::Color::White);
    m_stateText.setOrigin(m_stateText.getLocalBounds().getCenter());
    m_stateText.setPosition({m_parent->getSize().x/2.f, 15 + 15 + 184});

    //1 Player Button
    m_1PlayerBtn = Button(m_textures, sf::IntRect(sf::Vector2i(1847,0), sf::Vector2(150, 64)), false);
    m_1PlayerBtn.setOrigin(m_1PlayerBtn.getLocalBounds().getCenter());
    m_1PlayerBtn.setPosition(sf::Vector2f(m_parent->getSize().x/2.f, 15 + 30 + 199 + 20 + m_stateText.getLocalBounds().size.y));

    //Text for the 1 player menu
    m_labelTxt = sf::Text(m_font, "1 Player", 25);
    m_labelTxt.setFillColor(sf::Color::White);
    m_labelTxt.setOrigin(m_labelTxt.getLocalBounds().getCenter());
    m_labelTxt.setPosition(m_1PlayerBtn.getGlobalBounds().getCenter());


    //2 Players Button
    m_2PlayersBtn = Button(m_textures, sf::IntRect(sf::Vector2i(1847,0), sf::Vector2(150, 64)), false);
    m_2PlayersBtn.setOrigin(m_2PlayersBtn.getLocalBounds().getCenter());
    m_2PlayersBtn.setPosition(sf::Vector2f(m_parent->getSize().x/2.f, 15 + 30 + 199 + 20*2 + m_stateText.getLocalBounds().size.y + 64));

    //Initialize the 2 Players Text for the button
    m_label2playersTxt = sf::Text(m_font, "2 Players", 20);
    m_label2playersTxt.setFillColor(sf::Color::White);
    m_label2playersTxt.setOrigin(m_label2playersTxt.getLocalBounds().getCenter());
    m_label2playersTxt.setPosition(m_2PlayersBtn.getGlobalBounds().getCenter());

    //Settings Button
    m_settingsButton = Button(m_textures, sf::IntRect(sf::Vector2i(1847,0), sf::Vector2(150, 64)), false);
    m_settingsButton.setOrigin(m_settingsButton.getLocalBounds().getCenter());
    m_settingsButton.setPosition(sf::Vector2f(m_parent->getSize().x/2.f, 15 + 30 + 199 + 20*3 + m_stateText.getLocalBounds().size.y + 2 * 64));

    //Initialize the Settings Text
    m_settingsLabelTxt = sf::Text(m_font, "Settings", 25);
    m_settingsLabelTxt.setFillColor(sf::Color::White);
    m_settingsLabelTxt.setOrigin(m_settingsLabelTxt.getLocalBounds().getCenter());
    m_settingsLabelTxt.setPosition(m_settingsButton.getGlobalBounds().getCenter());


    //Scores Button
    m_scoresButton = Button(m_textures, sf::IntRect(sf::Vector2i(1847,0), sf::Vector2(150, 64)), false);
    m_scoresButton.setOrigin(m_scoresButton.getLocalBounds().getCenter());
    m_scoresButton.setPosition(sf::Vector2f(m_parent->getSize().x/2.f, 15 + 30 + 199 + 20*4 + m_stateText.getLocalBounds().size.y + 3 * 64));

    //Scores Button Text
    m_scoresLabelTxt = sf::Text(m_font, "Scores", 25);
    m_scoresLabelTxt.setFillColor(sf::Color::White);
    m_scoresLabelTxt.setOrigin(m_scoresLabelTxt.getLocalBounds().getCenter());
    m_scoresLabelTxt.setPosition(this->m_scoresButton.getGlobalBounds().getCenter());


    //Exit button
    m_exitButton = Button(m_textures, sf::IntRect(sf::Vector2i(1847,0), sf::Vector2(150, 64)));
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().getCenter());
    m_exitButton.setPosition(sf::Vector2f(m_parent->getSize().x/2.f, 15 + 30 + 199 + 20*5 + m_stateText.getLocalBounds().size.y + 4*64));

    //Text of the Exit Button
    m_exitLabelTxt = sf::Text(m_font, "Quit", 25);
    m_exitLabelTxt.setFillColor(sf::Color::White);
    m_exitLabelTxt.setOrigin(m_exitLabelTxt.getLocalBounds().getCenter());
    m_exitLabelTxt.setPosition(m_exitButton.getGlobalBounds().getCenter());
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

            m_1PlayerBtn.setHover();
            m_2PlayersBtn.setHover();
            m_settingsButton.setHover();
            m_scoresButton.setHover();
            m_exitButton.setHover();

}

void MainMenuScreen::setVolumeBtn(float volume) {
    m_1PlayerBtn.setVolumeBtn(volume);
    m_2PlayersBtn.setVolumeBtn(volume);
    m_settingsButton.setVolumeBtn(volume);
    m_scoresButton.setVolumeBtn(volume);
    m_exitButton.setVolumeBtn(volume);
}

void MainMenuScreen::draw()
{
    //Draw the background of the view
    m_parent->draw(m_background);

    //Load end draw the logo of the game
    sf::Sprite logo( m_textures, sf::IntRect({1289,0}, {556, 184}));
    logo.setOrigin(logo.getLocalBounds().getCenter());
    logo.setPosition({(this->m_parent->getSize().x/2.f),184/2+15});
    m_parent->draw(logo);

    //Draw the "main menu title
    m_parent->draw(m_stateText);

    //Draw the "1 Player Button"
    m_parent->draw(m_1PlayerBtn);

    //Write the text for the button 1 PLayer
    m_parent->draw(m_labelTxt);

    //Draw the "2 Players" Button
    m_parent->draw(m_2PlayersBtn);

    //Write the text of the button 2 PLayers
    m_parent->draw(this->m_label2playersTxt);

    //Draw the Settings Button
    m_parent->draw(m_settingsButton);

    //Write the Settings Text on the BUtton
    m_parent->draw(m_settingsLabelTxt);


    //Draw the Scores Button
    m_parent->draw(m_scoresButton);

    //Write the Score Text on the BUtton
    m_parent->draw(m_scoresLabelTxt);


    //Draw the Quit Button
    m_parent->draw(m_exitButton);

    //Write the Score Text on the BUtton
    m_parent->draw(m_exitLabelTxt);

}

MainMenuScreen::~MainMenuScreen() = default;
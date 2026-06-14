#include "SettingsScreen.hpp"

SettingsScreen::SettingsScreen(sf::RenderWindow &par, sf::Texture textures[6], sf::Font &font)
{
    //Get the parent Window
    this->m_parent = &par;

    //Loading the font for writing text on the view
    if(!this->m_Font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    //Get the textures loaded at the game launch
    for(int i = 0; i<=5; i++)
    {
        this->m_textures[i] = &textures[i];
    }


        this->m_stateText.setFont(this->m_Font);
        this->m_stateText.setCharacterSize(30);
        this->m_stateText.setFillColor(sf::Color::White);
        this->m_stateText.setString("Settings");
        float longueur = this->m_stateText.getLocalBounds().getCenter().x;
        float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;
        this->m_stateText.setOrigin({longueur,hauteur});

        this->m_textMusicVolume.setFont(this->m_Font);
        this->m_textMusicVolume.setCharacterSize(20);
        this->m_textMusicVolume.setFillColor(sf::Color::White);
        this->m_textMusicVolume.setString("Music Volume");
        longueur = this->m_textMusicVolume.getLocalBounds().getCenter().x;
        hauteur = this->m_textMusicVolume.getGlobalBounds().getCenter().y;
        this->m_textMusicVolume.setOrigin({longueur,hauteur});

        this->m_textSFXVolume.setFont(this->m_Font);
        this->m_textSFXVolume.setCharacterSize(20);
        this->m_textSFXVolume.setFillColor(sf::Color::White);
        this->m_textSFXVolume.setString("SFX Volume");
        longueur = this->m_textSFXVolume.getLocalBounds().getCenter().x;
        hauteur = this->m_textSFXVolume.getGlobalBounds().getCenter().y;
        this->m_textSFXVolume.setOrigin({longueur,hauteur});




}

void SettingsScreen::draw() {

    sf::IntRect rectangle = sf::IntRect( {0,0},{1287, 726} );

    sf::Sprite background = sf::Sprite(*this->m_textures[2], rectangle);

    this->m_parent->draw(background);

    this->m_stateText.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,35));

    this->m_textMusicVolume.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,70));

    this->m_textSFXVolume.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,170));

    this->m_parent->draw(this->m_stateText);

    this->m_parent->draw(this->m_textMusicVolume);

    this->m_parent->draw(this->m_textSFXVolume);
}

SettingsScreen::~SettingsScreen() = default;
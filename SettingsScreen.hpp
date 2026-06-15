#ifndef SFML_PONG_SETTINGSSCREEN_HPP
#define SFML_PONG_SETTINGSSCREEN_HPP
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>

class SettingsScreen {

private :
    sf::RenderWindow *m_parent;
    sf::Texture *m_textures[6];
    sf::Font m_Font;

    Button m_buttonPlusMusique = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(60, 60)), true);

    Button m_buttonMoinsMusique = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(60, 60)), true);

    Button m_buttonPlusSFX = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(60, 60)), true);

    Button m_buttonMoinsSFX = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(60, 60)), true);

    Button m_buttonSave = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));

    Button m_buttonCredits = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));

    Button m_buttonGameMode = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));

    sf::Text m_textPlus1= sf::Text(this->m_Font, "");
    sf::Text m_textPlus2= sf::Text(this->m_Font, "");
    sf::Text m_textMoins1= sf::Text(this->m_Font, "");
    sf::Text m_textMoins2= sf::Text(this->m_Font, "");
    sf::Text m_textCredits= sf::Text(this->m_Font, "");
    sf::Text m_textSave= sf::Text(this->m_Font, "");
    sf::Text m_textGameMode= sf::Text(this->m_Font, "");
    sf::Text m_textGameModeSelected= sf::Text(this->m_Font, "");

    sf::Text m_textMusicVolume = sf::Text(this->m_Font, "");
    sf::Text m_textSFXVolume = sf::Text(this->m_Font, "");

    sf::Text m_stateText = Text(this->m_Font, "");

public :
   SettingsScreen(sf::RenderWindow &par, sf::Texture textures[6], sf::Font &font);
    void update(float dtTime);
    void draw();
    sf::Vector2i menuPosition = sf::Vector2i(1, 1);
    void setVolumeBtn(float volumeBtn);
    ~SettingsScreen();

};


#endif //SFML_PONG_SETTINGSSCREEN_HPP

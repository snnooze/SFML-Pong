#pragma once
#include <SFML/Graphics.hpp>
#include "Button.hpp"

class MainMenuScreen : public sf::View
{

    private :
        sf::Font m_font;
        sf::Text m_stateText = sf::Text(m_font, "");
        sf::RenderWindow *m_parent;
        sf::Texture *m_textures[3];
        //sf::Sprite m_background = sf::Sprite(*this->m_textures[2]);
        float m_parentWidth;
        float m_parentHeight;
        Button m_1PlayerBtn =  Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
        sf::Text m_labelTxt = sf::Text(m_font, "");

        Button m_2PlayersBtn =  Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
        sf::Text m_label2playersTxt = sf::Text(m_font, "");

        Button m_settingsButton =  Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
        sf::Text m_settingsLabelTxt = sf::Text(m_font, "");

        Button m_scoresButton =  Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
        sf::Text m_scoresLabelTxt = sf::Text(m_font, "");

        Button m_exitButton =  Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));
        sf::Text m_exitLabelTxt = sf::Text(m_font, "");




    public : 
        MainMenuScreen(sf::RenderWindow &par, sf::Texture textures[2], const sf::Font &font);
        int m_menuPosition = 1;
        void inputs();
        void update(float dt = 0.f);
        sf::Sprite getSprite();
        void draw();
        ~MainMenuScreen();
};
#pragma once
#include <SFML/Graphics.hpp>

class MainMenuScreen : public sf::View
{

    private :
        sf::Font m_font;
        sf::Text m_stateText = sf::Text(m_font, "");
        sf::RenderWindow *m_parent;
        sf::Texture *m_textures[2];
        int m_parentWidth;
        int m_parentHeight; 

    public : 
        MainMenuScreen();
        void initialize(sf::RenderWindow &parent, sf::Texture *textures, sf::Font &font);
        void inputs();
        void update(float dt = 0.f);
        sf::Sprite getSprite();
        void draw();
};
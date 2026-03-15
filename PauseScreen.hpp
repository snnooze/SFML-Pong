#pragma once
#include <SFML/Graphics.hpp>

class PauseScreen{

    private :
        sf::Font m_font;
        sf::Text m_stateText = sf::Text(m_font, "");
        sf::RenderWindow *m_parent;
        int m_parentWidth;
        int m_parentHeight; 

    public : 
        PauseScreen();
        void initialize(sf::RenderWindow &parent);
        void inputs();
        void update(float dt = 0.f);
        void draw();
};
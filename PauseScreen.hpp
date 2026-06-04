#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PauseScreen : public View
{

    private :
        Font m_font;
        Text m_stateText = Text(m_font, "");
        RenderWindow *m_parent;
        int m_parentWidth;
        int m_parentHeight; 

    public : 
        PauseScreen(RenderWindow &parent);
        void inputs();
        void update(float dt = 0.f);
        void draw();
        ~PauseScreen();
};
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Engine
{
    private :
        RenderWindow m_window;
        int m_windowWidth = 800;
        int m_windowHeight = 600;
        void createWindow(int width, int height, String name);
        const String m_GameName = "#Pong";
        Clock m_clock;
        Time m_dt;
    public : 
        Engine();
        void loop();
        void inputs();
        void update();
        void draw();
};
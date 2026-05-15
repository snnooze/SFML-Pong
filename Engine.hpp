#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "States.hpp"
#include "PauseScreen.hpp"
#include "MainMenuScreen.hpp"

using namespace sf;

class Engine
{
    private :
        RenderWindow m_window;
        int m_windowWidth = 800;
        int m_windowHeight = 600;
        void createWindow(int width, int height, String name);
        bool texturesLoader();
        Font m_Font;
        Texture m_Logo;
        Texture m_textures[2];
        const String m_GameName = "#Pong";
        Clock m_clock;
        Time m_dt;
        States m_GameState;
        PauseScreen m_PS;
        //MainMenuScreen m_MMS;
        MainMenuScreen m_viewMMS;
    public : 
        Engine();
        void loop();
        void inputs();
        void update();
        void draw();
};
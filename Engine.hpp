#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "States.hpp"
#include "PauseScreen.hpp"
#include "MainMenuScreen.hpp"
#include "SettingsScreen.hpp"
#include "Game.hpp"

using namespace sf;

class Engine
{
    private :
        RenderWindow m_window;
        int m_windowWidth = 1287;
        int m_windowHeight = 726;
        void createWindow(int width, int height, String name);
        bool texturesLoader();
        Font m_Font;
        Texture m_textures;
        const String m_GameName = "#Pong";
        Clock m_clock;
        Time m_dt;
        States m_GameState;
        //PauseScreen m_PS = PauseScreen(this->m_window);
        MainMenuScreen m_viewMMS = MainMenuScreen(m_window, m_textures);
        SettingsScreen m_configMenuScreen = SettingsScreen(this->m_window, this->m_textures, this->m_Font);
        Game m_game = Game(this->m_window, this->m_textures, this->m_Font, false);
        Music m_mainMenuMusic;
        bool m_musciPlay = false;
        bool m_player1Pressed = false;
        bool m_player2Pressed = false;
        Image icone;
        Text pause = Text(this->m_Font, "Pause", 30);
    public : 
        Engine();
        void loop();
        void inputs();
        void update();
        void draw();
        void loadConfig();
        ~Engine();
};
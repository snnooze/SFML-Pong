#pragma once

class States
{
    private : 
       

    public : 
        States();
        struct
        {
            bool m_isPaused = false;
            bool m_isGameOver = false;
            bool m_isMainMenu = true;
            bool m_isInGame  = false;
        }currentGameState;
        void pause();
        void mainMenu();
        void game();
        void gameOver();
};
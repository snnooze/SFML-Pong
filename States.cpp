#include "States.hpp"

States::States()
{

}

void States::pause()
{
    if(this->currentGameState.m_isPaused)
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;

    }
    else
    {
        this->currentGameState.m_isPaused = true;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
    }
}

void States::mainMenu()
{
    if(this->currentGameState.m_isMainMenu)
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = true;
        this->currentGameState.m_isConfigMenu = false;
    }
}

void States::game()
{
    if(this->currentGameState.m_isInGame)
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
    }
}

void States::configMenu() {

    if(this->currentGameState.m_isConfigMenu)
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = true;
        this->currentGameState.m_isConfigMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = true;
    }

}

void States::gameOver()
{
    if(this->currentGameState.m_isGameOver)
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = true;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
    }
}
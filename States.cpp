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
    }
    else
    {
        this->currentGameState.m_isPaused = true;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
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
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = true;
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
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
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
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = true;
        this->currentGameState.m_isMainMenu = false;
    }
}
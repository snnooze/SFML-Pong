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
        this->currentGameState.m_isHighScoreMenu = false;

    }
    else
    {
        this->currentGameState.m_isPaused = true;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
        this->currentGameState.m_isHighScoreMenu = false;
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
        this->currentGameState.m_isHighScoreMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = true;
        this->currentGameState.m_isConfigMenu = false;
        this->currentGameState.m_isHighScoreMenu = false;
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
        this->currentGameState.m_isHighScoreMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
        this->currentGameState.m_isHighScoreMenu = false;
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
        this->currentGameState.m_isHighScoreMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = true;
        this->currentGameState.m_isHighScoreMenu = false;
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
        this->currentGameState.m_isHighScoreMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = true;
        this->currentGameState.m_isGameOver = true;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
        this->currentGameState.m_isHighScoreMenu = false;
    }
}

void States::highScores()
{
    if(this->currentGameState.m_isHighScoreMenu)
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
        this->currentGameState.m_isHighScoreMenu = false;
    }
    else
    {
        this->currentGameState.m_isPaused = false;
        this->currentGameState.m_isInGame = false;
        this->currentGameState.m_isGameOver = false;
        this->currentGameState.m_isMainMenu = false;
        this->currentGameState.m_isConfigMenu = false;
        this->currentGameState.m_isHighScoreMenu = true;
    }
}
#include "States.hpp"

States::States()
{
    
}

void States::pause()
{
    if(this->currentGameState.m_isPaused)
    {
        this->currentGameState.m_isPaused = false;
    }
    else
    {
        this->currentGameState.m_isPaused = true;
    }
}
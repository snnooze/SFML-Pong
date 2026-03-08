#include "Engine.hpp"

Engine::Engine()
{
    //TODO : Regarder ou placer et charger tous les sprites, début ?
    createWindow(m_windowWidth, m_windowHeight, m_GameName);

}

void Engine::createWindow(int m_windowWidth, int m_windowHeight, String m_GameName)
{
    VideoMode vm(Vector2u(m_windowWidth, m_windowHeight));

    m_window.create(vm, m_GameName, sf::State::Windowed);
}

//Boucle principale du jeu
void Engine::loop()
{

    while(m_window.isOpen())
    {

        inputs();        

        update();

        draw();

    }

}

void Engine::inputs()
{
    //Gestion des évènement utilisateur
    while(std::optional event = m_window.pollEvent())
        {
            //CLick sur la croix de fermeture de la fenêtre
            if(event->is<sf::Event::Closed>())
            {
                m_window.close();
            }

            //TODO : Passage en full screen

            //TODO : Bouton pause => redirection menu

        }
}

void Engine::update()
{
    //Recupération du deltatime
    m_dt = m_clock.restart();
    float deltaTime = m_dt.asSeconds();
    //Mise à jour du jeu

}

//Affichage
void Engine::draw()
{

    m_window.clear();

    //objets à dessiner

    m_window.display();

}
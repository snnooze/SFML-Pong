#include "Engine.hpp"

Engine::Engine()
{
    //chargement de police de texte
    if(!this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        return;
    }
    //TODO : Regarder ou placer et charger tous les sprites, début ?
    this->createWindow(this->m_windowWidth, this->m_windowHeight, this->m_GameName);

}

void Engine::createWindow(int m_windowWidth, int m_windowHeight, String m_GameName)
{
    //TODO : config file pour gestion du type et de la dimension de fenêtre ?
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

//Gestion des évènement utilisateur
void Engine::inputs()
{
    while(std::optional event = m_window.pollEvent())
        {
            //CLick sur la croix de fermeture de la fenêtre
            if(event->is<sf::Event::Closed>())
            {
                m_window.close();
            }

            if((event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::P))
            {
                this->m_GameState.pause();
            }

            //TODO : Passage en full screen

            //TODO : Bouton pause => redirection menu
            if(m_GameState.currentGameState.m_isPaused)
            {
                //Ne fait rien sur le jeu c'est en pause attends la commande de reprise

            }
            if(m_GameState.currentGameState.m_isGameOver)
            {
                //Affiche l'écran de fin attends la commande de retour au sommaire ou de quitter le jeu ?
            }
            if(m_GameState.currentGameState.m_isInGame)
            {
                //Intercepte les évènements joueur pour le jeu
            }
            if(m_GameState.currentGameState.m_isMainMenu)
            {
                //Intercepte les évènements joueur sur le menu (souris?)
            }

        }
}

//Mise à jour des éléments du jeu
void Engine::update()
{
    //Recupération du deltatime
    m_dt = m_clock.restart();
    float deltaTime = m_dt.asSeconds();
    //Mise à jour du jeu
    if(this->m_GameState.currentGameState.m_isPaused)
    {
        //Ne fait rien sur le jeu c'est en pause
        this->m_stateText.setFont(this->m_font);
        this->m_stateText.setCharacterSize(30);
        this->m_stateText.setFillColor(Color::White);
        float longueur = this->m_stateText.getLocalBounds().getCenter().x;
        float hauteur = this->m_stateText.getLocalBounds().getCenter().y;
        this->m_stateText.setPosition(Vector2f(this->m_windowWidth/2.f-longueur , this->m_windowHeight/2.F-hauteur));
        this->m_stateText.setString("Pause");

    }
    if(m_GameState.currentGameState.m_isGameOver)
    {
        //Affiche l'écran de fin
    }
    if(m_GameState.currentGameState.m_isInGame)
    {
        //Met à jour le jeu
    }
    if(m_GameState.currentGameState.m_isMainMenu)
    {
        //Met en pause le jeu et affiche le menu principal
    }


}

//Affichage des éléments
void Engine::draw()
{

    m_window.clear();

    //objets à dessiner
    if(m_GameState.currentGameState.m_isPaused)
    {
        //Ne fait rien sur le jeu c'est en pause
        m_window.draw(this->m_stateText);
    }
    if(m_GameState.currentGameState.m_isGameOver)
    {
        //Affiche l'écran de fin
    }
    if(m_GameState.currentGameState.m_isInGame)
    {
        //Met à jour le jeu
    }
    if(m_GameState.currentGameState.m_isMainMenu)
    {
        //Met en pause le jeu et affiche le menu principal
    }

    m_window.display();

}
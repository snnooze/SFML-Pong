#include "Engine.hpp"

Engine::Engine()
{

    if(this->m_Font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        if(this->texturesLoader())
        {

            this->createWindow(this->m_windowWidth, this->m_windowHeight, this->m_GameName);

            this->m_viewMMS.initialize(this->m_window, this->m_textures, this->m_Font); // Initialisation du Main Menu
            this->m_viewMMS.setSize(Vector2f(this->m_windowWidth, this->m_windowHeight));
            this->m_viewMMS.setCenter(Vector2f(this->m_windowWidth/2.f, this->m_windowHeight/2.f));

            this->m_PS.initialize(this->m_window);    //Initialisatin du menu de Pause   
            this->m_PS.setSize(Vector2f(this->m_windowWidth, this->m_windowHeight));
            this->m_PS.setCenter(Vector2f(this->m_windowWidth/2.f, this->m_windowHeight/2.f));

        }
        else
        {
            std::cout << "Textures loading Failed";
        }
        
    }
    else
    {
        std::cout << "Font loading Failed";
    }
    //TODO : Regarder ou placer et charger tous les sprites, début ?
   

    //this->m_MMS.initialize(this->m_window);   //Initialisation du menu principal

}

bool Engine::texturesLoader()
{
    if(!this->m_textures[0].loadFromFile("Assets/Graphics/logo.png"))
    {
        std::cout << "Logo loading Failed";
        return false;
    }

    if(!this->m_textures[1].loadFromFile("Assets/Graphics/Button.png"))
    {
        std::cout << "Button loading Failed";
        return false;
    }

    return true;
}

void Engine::createWindow(int m_windowWidth, int m_windowHeight, String m_GameName)
{
    //TODO : config file pour gestion du type et de la dimension de fenêtre ?
    VideoMode vm(Vector2u(m_windowWidth, m_windowHeight));

    this->m_window.create(vm, m_GameName, sf::State::Windowed);
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

            //Pendant le mode jeu et la pause la lettre P fait passer le jeu en pause ou hors pause
            if((this->m_GameState.currentGameState.m_isInGame || this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::P))
            {
                this->m_GameState.pause();
            }

            //La touche Escape fait pasculer en mode Main menu
            if((event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Escape))
            {
                this->m_GameState.mainMenu();
            }

            //TODO : Passage en full screen

            if(m_GameState.currentGameState.m_isPaused)
            {
                //Ne fait rien sur le jeu c'est en pause attends la commande de reprise

                //Intercepte les inputs utilisateur en mode Pause (faire passer les events en argument ? )
                this->m_PS.inputs();

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
        this->m_PS.update(deltaTime);

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
        //this->m_MMS.update(deltaTime);
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
       this->m_window.setView(this->m_PS); 
       this->m_PS.draw();
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
        this->m_window.setView(this->m_viewMMS);
        this->m_viewMMS.draw();
    }

    this->m_window.display();

}
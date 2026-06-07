#include <iostream>
#include "Engine.hpp"

Engine::Engine()
{

    if(this->m_Font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        if(this->texturesLoader())
        {
            if(this->m_mainMenuMusic.openFromFile("Assets/Sounds/music.mp3"))
            {
                this->createWindow(this->m_windowWidth, this->m_windowHeight, this->m_GameName);

                this->m_window.setVerticalSyncEnabled(true);

                //this->m_window.setFramerateLimit(60);

                this->m_viewMMS.setSize(Vector2f(this->m_windowWidth, this->m_windowHeight));
                this->m_viewMMS.setCenter(Vector2f(this->m_windowWidth/2.f, this->m_windowHeight/2.f));


                this->m_PS.setSize(Vector2f(this->m_windowWidth, this->m_windowHeight));
                this->m_PS.setCenter(Vector2f(this->m_windowWidth/2.f, this->m_windowHeight/2.f));

            }
            else
            {
                std::cout << "Music loading Failed";

            }

            

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
   

    this->m_window.setKeyRepeatEnabled(false);
    //this->m_MMS.initialize(this->m_window);   //Initialisation du menu principal

}

bool Engine::texturesLoader()
{
    if(!this->icone.loadFromFile("Assets/Graphics/icon.png"))
    {
        std::cout << "Icon loading Failed";
        return false;
    }

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

    if(!this->m_textures[2].loadFromFile("Assets/Graphics/background.png"))
    {
        std::cout << "Background loading Failed";
        return false;
    }

    if(!this->m_textures[3].loadFromFile("Assets/Graphics/ball.png"))
    {
        std::cout << "Ball loading Failed";
        return false;
    }

    if(!this->m_textures[4].loadFromFile("Assets/Graphics/paddle.png"))
    {
        std::cout << "Paddle loading Failed";
        return false;
    }

    return true;
}

void Engine::createWindow(int m_windowWidth, int m_windowHeight, String m_GameName)
{
    //TODO : config file pour gestion du type et de la dimension de fenêtre ?
    VideoMode vm(Vector2u(this->m_windowWidth, this->m_windowHeight));

    this->m_window.create(vm, m_GameName, sf::State::Windowed);

    this->m_window.setIcon(this->icone);
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

            if((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Space))
            {

                this->m_game.start();
            }

            //Touches pour Player 1;
            if((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Up || event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Down))
            {
                this->m_game.stopPlayer1();
                this->m_player1Pressed = false;
            }

            if ((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Up)) {
                if (!this->m_player1Pressed) {
                    this->m_game.movePlayer1Up();
                    this->m_player1Pressed = true;
                }
            }

            if ((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Down))
            {
                if (!this->m_player1Pressed) {
                    this->m_game.movePlayer1Down();
                    this->m_player1Pressed = true;
                }
            }

            //Touches pour Player 2
            if((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Z || event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::S))
            {
                this->m_game.stopPlayer2();
                this->m_player2Pressed = false;
            }

            if ((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Z)) {
                if (!this->m_player2Pressed) {
                    this->m_game.movePlayer2Up();
                    this->m_player2Pressed = true;
                }

            }

            if ((this->m_GameState.currentGameState.m_isInGame || !this->m_GameState.currentGameState.m_isPaused) && (event->is<sf::Event::KeyPressed>() && event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::S))
            {
                if (!this->m_player2Pressed) {
                    this->m_game.movePlayer2Down();
                    this->m_player2Pressed = true;
                }
            }

            //La touche Escape fait basculer en mode Main menu
            if((event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Escape))
            {
                if (this->m_GameState.currentGameState.m_isInGame) {
                    this->m_game.reset();
                    this->m_GameState.mainMenu();
                }
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
                if(!this->m_musciPlay)
                {
                    this->m_mainMenuMusic.play();
                    this->m_musciPlay = true;
                }

                //std::cout<< "Main menu \n";
                //Appuis sur la flèche du bas
                if(event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Down)
                {

                    this->m_viewMMS.m_menuPosition+=1;
                    std::cout<< "Main menu +1 \n";
                    if(this->m_viewMMS.m_menuPosition>5)
                    {
                        this->m_viewMMS.m_menuPosition=1;
                        std::cout<< "Main menu -> 1 \n";
                    }
                }
                //Appuis sur la flèche du haut
                if(event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Up)
                {
                    this->m_viewMMS.m_menuPosition-=1;
                    std::cout<< "Main menu -1 \n";
                    if(this->m_viewMMS.m_menuPosition<1)
                    {
                        this->m_viewMMS.m_menuPosition=5;
                        std::cout<< "Main menu -> 1 \n";
                    }
                }
                //Appuis sur Enter
                if (event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Enter) {
                    switch (this->m_viewMMS.m_menuPosition)
                    {
                        case 1 :
                            //Lance une partie à 1 joueur
                            this->m_game.set1PlayersMode();
                            this->m_game.resetScore();
                            this->m_GameState.game();
                            break;
                        case 2 :
                            //Lance une partie à 2 joueurs
                            this->m_game.set2PlayersMode();
                            this->m_game.resetScore();
                            this->m_GameState.game();
                            break;
                            break;
                        case 3 :
                            //Affiche les settings
                            break;
                        case 4 :
                            //Affiche les High scores
                            break;
                        case 5 :
                            m_window.close();
                            break;
                        default :
                            //Ne fait rien;
                            break;
                    }
                }
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
        //this->m_PS.update(deltaTime)
        this->pause.setOrigin(this->pause.getLocalBounds().getCenter());
        this->pause.setPosition({this->m_windowWidth/2.f,this->m_windowHeight/2.f});
        if(this->m_musciPlay)
        {
            this->m_mainMenuMusic.stop();
            this->m_musciPlay = false;
        }

    }
    if(m_GameState.currentGameState.m_isGameOver)
    {
        //Affiche l'écran de fin
    }
    if(m_GameState.currentGameState.m_isInGame) {
        //Met à jour le jeu
        if(this->m_musciPlay) {
            this->m_mainMenuMusic.stop();
            this->m_musciPlay = false;
        }

        this->m_game.update(deltaTime);
    }
    if(m_GameState.currentGameState.m_isMainMenu)
    {
        this->m_viewMMS.update();
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
       //this->m_PS.draw();
        this->m_game.draw();
        this->m_window.draw(pause);

    }
    if(m_GameState.currentGameState.m_isGameOver)
    {
        //Affiche l'écran de fin
    }
    if(m_GameState.currentGameState.m_isInGame)
    {
        //Met à jour le jeu
        this->m_game.draw();

    }
    if(m_GameState.currentGameState.m_isMainMenu)
    {
        //Met en pause le jeu et affiche le menu principal
        this->m_viewMMS.draw();
    }

    this->m_window.display();

}

Engine::~Engine() = default;
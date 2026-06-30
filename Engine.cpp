#include "Engine.hpp"

Engine::Engine() {
    if (this->m_Font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf")) {
        if (this->texturesLoader()) {
            if (this->m_mainMenuMusic.openFromFile("Assets/Sounds/music.mp3")) {
                this->loadConfig();

                this->createWindow(this->m_windowWidth, this->m_windowHeight, this->m_GameName);

                //Limit the Framerate
                this->m_window.setVerticalSyncEnabled(true);

                this->m_window.setFramerateLimit(60);

                this->m_window.setKeyRepeatEnabled(false);

                m_viewMMS = MainMenuScreen(m_window, m_textures);
                m_viewMMS.showMenu();

                m_game = Game(m_window, m_textures, m_Font, false);
                m_game.setGame();

            } else {
                std::cout << "Music loading Failed";
            }
        } else {
            std::cout << "Textures loading Failed";
        }
    } else {
        std::cout << "Font loading Failed";
    }
}

void Engine::loadConfig() {

    FILE *fichier;
    char line[20];
    size_t len;
    char conf[3][sizeof(line)];

    if (fichier = std::fopen("Assets/Resources/config.txt", "r")) {

        for (int i = 0; i < 3; i++) {
            fgets(conf[i], sizeof(line), fichier);
        }

    }
    else {
        std::cout << "COnfig File loading Failed...";
    }

    // for (int i = 0; i < 3; i++) {
    //     std::cout<<conf[i]<<std::endl;
    // }
    float vol = std::stof(conf[0]);
    this->m_mainMenuMusic.setVolume(vol);
    this->m_viewMMS.setVolumeBtn(std::stof(conf[1]));
     this->m_configMenuScreen.setVolumeBtn(std::stof(conf[1]));
     this->m_configMenuScreen.setVolumeMusic(vol);
     this->m_configMenuScreen.setVolumeButtons(std::stof(conf[1]));
     this->m_game.setStartingVolume(std::stof(conf[1]));
     this->m_game.setGameMode(std::stoi(conf[2]));
     this->m_configMenuScreen.setGameMode(std::stoi(conf[2]));
}

bool Engine::texturesLoader()
{
    if(!icone.loadFromFile("Assets/Graphics/icon.png"))
    {
        std::cout << "Icon loading Failed";
        return false;
    }

    if(!m_textures.loadFromFile("Assets/Graphics/atlas.png"))
    {
        std::cout << "Atlas loading Failed";
        return false;
    }
    else {

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
                this->m_window.close();
            }

            if(event->is<sf::Event::Resized>())
            {
                sf::Vector2u size({(unsigned)this->m_windowWidth, (unsigned)this->m_windowHeight});
                this->m_window.setMaximumSize(size);
                this->m_window.setMinimumSize(size);
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
                if (this->m_GameState.currentGameState.m_isConfigMenu) {
                    this->m_game.reset();
                    this->m_GameState.mainMenu();
                }
            }

            if(m_GameState.currentGameState.m_isPaused)
            {
                //Ne fait rien sur le jeu c'est en pause attends la commande de reprise

                //Intercepte les inputs utilisateur en mode Pause (faire passer les events en argument ? )
                //this->m_PS.inputs();

            }
            if(m_GameState.currentGameState.m_isGameOver)
            {
                //Affiche l'écran de fin attends la commande de retour au sommaire ou de quitter le jeu ?
            }
            if(m_GameState.currentGameState.m_isInGame)
            {
                //Intercepte les évènements joueur pour le jeu
            }
            if(m_GameState.currentGameState.m_isConfigMenu) {

                if(!this->m_musciPlay)
                {
                    this->m_mainMenuMusic.play();
                    this->m_musciPlay = true;
                }

                //std::cout<< "Main menu \n";
                //Appuis sur entrée

                if (event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Enter) {
                    switch (this->m_configMenuScreen.menuPosition.y) {
                        case 1: //Volume de la musique
                            if (this->m_configMenuScreen.menuPosition.x == 1) {
                                this->m_mainMenuMusic.setVolume(this->m_mainMenuMusic.getVolume() - 10.0);
                                this->m_configMenuScreen.storeVolumeMusic(-10.0);
                            }
                            else {
                                this->m_mainMenuMusic.setVolume(this->m_mainMenuMusic.getVolume() + 10.0);
                                this->m_configMenuScreen.storeVolumeMusic(+10.0);
                            }

                            if (this->m_mainMenuMusic.getVolume() > 100.0) {
                                this->m_mainMenuMusic.setVolume(100.0);
                            }
                            if (this->m_mainMenuMusic.getVolume() < 0.0) {
                                this->m_mainMenuMusic.setVolume(0.0);
                            }
                            break;
                        case 2: //volume des SFX
                            if (this->m_configMenuScreen.menuPosition.x == 1) {
                                this->m_configMenuScreen.setVolumeBtn(-10);
                                this->m_viewMMS.setVolumeBtn(-10);
                                this->m_game.setVolume(-10);
                                this->m_configMenuScreen.storeVolumeSFX(-10.0);
                            }
                            else {
                                this->m_configMenuScreen.setVolumeBtn(+10);
                                this->m_viewMMS.setVolumeBtn(+10);
                                this->m_game.setVolume(+10);
                                this->m_configMenuScreen.storeVolumeSFX(+10.0);
                            }
                            break;
                        case 3: //Bouton de changement de mode de jeu
                            this->m_configMenuScreen.switchGameMode();
                            break;
                        case 4 : //Bouton de sauvegarde
                            this->m_configMenuScreen.saveConfig();
                        default :
                            break;
                    }
                }

                //Appuis sur la flèche du bas
                if(event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Down)
                {
                    m_configMenuScreen.menuPosition.y+=1;
                     //std::cout<< "Main menu +1 ->  "<<this->m_viewMMS.m_menuPosition << "\n";
                     if(this->m_configMenuScreen.menuPosition.y>4)
                     {
                         this->m_configMenuScreen.menuPosition.y=1;
                       //  std::cout<< "Main menu -> 1 \n";
                     }
                     if (this->m_configMenuScreen.menuPosition.y > 2 && this->m_configMenuScreen.menuPosition.x != 1) {
                         this->m_configMenuScreen.menuPosition.x=1;
                     }
                }
                //Appuis sur la flèche du haut
                if(event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Up)
                {
                    this->m_configMenuScreen.menuPosition.y-=1;
                    //std::cout<< "Main menu -1 \n";
                    if(this->m_configMenuScreen.menuPosition.y<1)
                    {
                        this->m_configMenuScreen.menuPosition.y=4;
                        //std::cout<< "Main menu -> 1 \n";
                    }
                    if (this->m_configMenuScreen.menuPosition.y > 2 && this->m_configMenuScreen.menuPosition.x != 1) {
                        this->m_configMenuScreen.menuPosition.x=1;
                    }
                }
                if(event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Left)
                {
                    this->m_configMenuScreen.menuPosition.x-=1;
                    //std::cout<< "Main menu -1 \n";
                    if(this->m_configMenuScreen.menuPosition.x<1)
                    {
                        this->m_configMenuScreen.menuPosition.x=2;

                    }
                    if (this->m_configMenuScreen.menuPosition.y > 2 && this->m_configMenuScreen.menuPosition.x != 1) {
                        this->m_configMenuScreen.menuPosition.x=1;
                    }//std::cout<< "Main menu -> 1 \n";
                }
                if(event->is<sf::Event::KeyReleased>() && event->getIf<sf::Event::KeyReleased>()->code == sf::Keyboard::Key::Right)
                {
                     this->m_configMenuScreen.menuPosition.x+=1;
                     //std::cout<< "Main menu -1 \n";
                     if(this->m_configMenuScreen.menuPosition.x>2 )
                     {
                         this->m_configMenuScreen.menuPosition.x=1;

                     }
                     if (this->m_configMenuScreen.menuPosition.y > 2 && this->m_configMenuScreen.menuPosition.x != 1) {
                         this->m_configMenuScreen.menuPosition.x=1;
                     }
                }
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

                    m_viewMMS.m_menuPosition+=1;
                    std::cout<< "Main menu +1 ->  "<<this->m_viewMMS.m_menuPosition << "\n";
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
                            //Lance une partie SSSSSà 1 joueur
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
                            // this->m_GameState.currentGameState.m_isConfigMenu = true;
                            this->m_GameState.configMenu();
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
    if(m_GameState.currentGameState.m_isConfigMenu)
    {
        //Affiche l'écran de configuration
        this->m_configMenuScreen.update(deltaTime);
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
        this->m_viewMMS.update(deltaTime);
        //this->m_MMS.update(deltaTime);
        //Met en pause le jeu et affiche le menu principal
    }


}

//Affichage des éléments
void Engine::draw()
{

    m_window.clear(Color::Black);

    //objets à dessiner
    if(m_GameState.currentGameState.m_isPaused)
    {
        //Ne fait rien sur le jeu c'est en pause
       //this->m_PS.draw();
        // this->m_game.draw();
        this->m_window.draw(pause);

    }
    if(m_GameState.currentGameState.m_isGameOver)
    {
        //Affiche l'écran de fin
    }
    if(m_GameState.currentGameState.m_isConfigMenu)
    {
        //Affiche l'écran de COnfiguration
        this->m_configMenuScreen.draw();
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
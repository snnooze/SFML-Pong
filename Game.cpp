#include "Game.hpp"

#include <algorithm>
#include <iostream>

Game::Game(sf::RenderWindow &par, sf::Texture &textures, const sf::Font &font, bool is_2PlayersMode) {
    //Get the parent Window
    m_parent = &par;
    m_textures = textures;

    //Loading the font for writing text on the view
    if(!this->m_font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    this->m_parentWidth = this->m_parent->getSize().x;
    this->m_parentHeight = this->m_parent->getSize().y;

}

void Game::setGame() {

    m_background = sf::Sprite(m_textures, sf::IntRect({0,0},{1287, 726}));
    m_background.setOrigin(m_background.getLocalBounds().getCenter());
    m_background.setPosition({m_parent->getSize().x/2.f,m_parent->getSize().y/2.f});

    if (m_is2PlayersMode) {
        m_paddleLeft = Paddle(*m_parent, m_textures, true);
    }
    else {
        m_paddleLeft = Paddle(*m_parent, m_textures, true);
    }

    m_paddleRight = Paddle(*m_parent, m_textures, false);
    m_ball = Ball(*m_parent, m_textures);

    m_paddleLeft.setOrigin(m_paddleLeft.getLocalBounds().getCenter());
    m_paddleRight.setOrigin(m_paddleRight.getLocalBounds().getCenter());
    m_ball.setOrigin(this->m_ball.getLocalBounds().getCenter());

    this->m_scorePlayer1Lbl = sf::Text(this->m_font, "0", 45);
    this->m_scorePlayer2Lbl = sf::Text(this->m_font, "0", 45);

    m_EnduranceModeResult = sf::Text(m_font, "", 45);

    this->m_scorePlayer1Lbl.setFillColor(sf::Color::Transparent);
    this->m_scorePlayer2Lbl.setFillColor(sf::Color::Transparent);

    m_flash = sf::RectangleShape(sf::Vector2f(m_parent->getSize().x,m_parent->getSize().y));

    this->m_scorePlayer1Lbl.setOutlineThickness(1.5);
    this->m_scorePlayer2Lbl.setOutlineThickness(1.5);

    this->m_scorePlayer1Lbl.setOutlineColor(sf::Color::Black);
    this->m_scorePlayer2Lbl.setOutlineColor(sf::Color::Black);

    m_Player1Wins = sf::Sprite(m_textures, sf::IntRect({913,728},{829,94}));
    m_Player2Wins = sf::Sprite(m_textures, sf::IntRect({0,728},{911,94}));

    m_PlayerWin = sf::Sprite(m_textures, sf::IntRect({0, 824},{418,345}));
    m_PlayerLose = sf::Sprite(m_textures, sf::IntRect({1289,186},{545,265}));

    m_Player1Wins.setOrigin(m_Player1Wins.getLocalBounds().getCenter());
    m_Player2Wins.setOrigin(m_Player2Wins.getLocalBounds().getCenter());
    m_PlayerWin.setOrigin(m_PlayerWin.getLocalBounds().getCenter());
    m_PlayerLose.setOrigin(m_PlayerLose.getLocalBounds().getCenter());

    m_Player1Wins.setPosition(m_background.getLocalBounds().getCenter());
    m_Player2Wins.setPosition(m_background.getLocalBounds().getCenter());
    m_PlayerWin.setPosition(m_background.getLocalBounds().getCenter());
    m_PlayerLose.setPosition(m_background.getLocalBounds().getCenter());

    reset();
}

void Game::start()
{

    if (!this->m_isActive) {
        reset();
        m_isActive = true;
        m_isSaveNeeded = true;
        m_highscore = false;
        m_ball.startMove(m_isFirstPlayerTurn);
    }

    if (m_gameEnded) {
        m_Player1Victory = false;
        m_Player2Victory = false;
        m_YouWin = false;
        m_YouLose = false;
        m_gameEnded = false;
        m_highscore = false;
        resetScore();
    }

}

void Game::set2PlayersMode() {
    //this->m_paddleLeft = Paddle(*this->m_parent, this->m_textures, true);
    this->m_is2PlayersMode = true;
    this->stopPlayer2();
}

void Game::set1PlayersMode() {
    //this->m_paddleLeft = Paddle(*this->m_parent, this->m_textures, true);
    this->m_is2PlayersMode = false;
    //this->m_paddleLeft.move(0, 0);
}

void Game::update(float dtTime)
{
    if (this->m_isActive)
    {
    //Gestion du heurt de la balle sur les Paddles
        if (this->m_ball.getGlobalBounds().findIntersection(this->m_paddleRight.getGlobalBounds()) || this->m_ball.getGlobalBounds().findIntersection(this->m_paddleLeft.getGlobalBounds())) {

            this->m_ball.reverseDirection();
        }
        //Gestion de sortie de balle sur la gauche et droite et remise de la balle au centre
        if (this->m_ball.getGlobalBounds().position.x >= this->m_parent->getSize().x || this->m_ball.getGlobalBounds().position.x <= 0)
        {
            this->m_ball.emitOutSound();
            //Notation des scores
            if (this->m_ball.getGlobalBounds().position.x >= this->m_parent->getSize().x-25) {
                this->m_scorePlayer2+=1;

                    backgroundVibration();

                this->m_scorePlayer2Lbl.setString(std::to_string(m_scorePlayer2));
                this->m_isFirstPlayerTurn = true;
            }
            else {
                this->m_scorePlayer1+=1;
                this->m_scorePlayer1Lbl.setString(std::to_string(m_scorePlayer1));
                this->m_isFirstPlayerTurn = false;
                    backgroundVibration();
            }


            this->m_isActive = false;
            this->reset();
        }

        m_ball.update(dtTime);

        if (this->m_is2PlayersMode) {


            this->m_paddleLeft.move(this->movePlayer2, dtTime);

        }
        else {

            if (m_ball.getGlobalBounds().getCenter().y != m_paddleLeft.getPosition().y) {
                if (m_ball.getGlobalBounds().getCenter().y < m_paddleLeft.getPosition().y) {
                    movePlayer2 = -1;
                }
                else {
                    movePlayer2 = +1;
                }


                m_paddleLeft.move(movePlayer2, dtTime);

            }

        }
        // sf::Vector2f pdr = {this->m_paddleRight.getPosition().x, this->m_paddleRight.getPosition().y + (250 * dtTime )* this->movePlayer1};
        // this->m_paddleRight.setPosition(pdr);

        this->m_paddleRight.move(this->movePlayer1, dtTime);
        //
        //
        this->m_paddleLeft.update(dtTime);
        this->m_paddleRight.update(dtTime);



    }
    else {
        this->reset();
    }

    float centerTerrain = (float)this->m_parent->getSize().x/2.f;

    this->m_scorePlayer1Lbl.setLineAlignment(sf::Text::LineAlignment::Center);
    this->m_scorePlayer2Lbl.setLineAlignment(sf::Text::LineAlignment::Center);

    this->m_scorePlayer1Lbl.setPosition({ centerTerrain + 50.f, +20.f});
    this->m_scorePlayer2Lbl.setPosition({centerTerrain - 50.f , +20.f});
}

void Game::draw() {
    //Load the background image and set the positions

    //Draw the background of the view
    m_parent->draw(m_background);

    m_parent->draw(m_paddleLeft);
    m_parent->draw(m_paddleRight);
    m_parent->draw(m_ball);

    if (m_isFlashing == true) {
        m_flash.setFillColor(sf::Color::White);
        m_isFlashing = false;
    }
    else {
        m_flash.setFillColor(sf::Color::Transparent);
    }

    m_parent->draw(m_flash);

    if (m_Player1Victory || m_Player2Victory) {

        if (m_Player1Victory) {
            m_parent->draw(m_Player1Wins);
        }
        else {
            m_parent->draw(m_Player2Wins);
        }

    }

    if (m_YouWin || m_YouLose) {

        if (m_YouWin) {
            if (m_scorePlayer1 == 0 && m_gameMode == 2) {
                m_parent->draw(m_PlayerLose);
            }
            else {
                m_parent->draw(m_PlayerWin);
            }

        }
        else {
            m_parent->draw(m_PlayerLose);
        }

    }

    if (m_YouWin && m_gameMode == 2) {
        if (m_highscore) {
            m_EnduranceModeResult.setString("HighScore !! ");
        }
        m_EnduranceModeResult.setOrigin(m_EnduranceModeResult.getLocalBounds().getCenter());
        m_EnduranceModeResult.setPosition(m_PlayerWin.getGlobalBounds().getCenter());
        m_parent->draw(m_EnduranceModeResult);
    }

    m_parent->draw(m_scorePlayer1Lbl);
    m_parent->draw(m_scorePlayer2Lbl);
}

void Game::movePlayer1Up()
{
    if (this->m_isActive) {
        this->movePlayer1 = -1;
    }

}

void Game::movePlayer1Down()
{
    if (this->m_isActive) {
        this->movePlayer1 = 1;
    }

}

void Game::stopPlayer1() {
    if (this->m_isActive) {
        this->movePlayer1 = 0;
    }
}

void Game::reset() {
    m_isActive = false;
    m_paddleRight.setPosition({m_parent->getSize().x - 50.f - m_paddleRight.getLocalBounds().size.x, m_parent->getSize().y/2.f});
    m_ball.setPosition({(float)m_parent->getSize().x/2,(float)m_parent->getSize().y/2});
    m_paddleLeft.setPosition({m_paddleLeft.getLocalBounds().size.x +  50.f, (float)m_parent->getSize().y/2.f});
    movePlayer1 = 0;
    movePlayer2 = 0;
    stopPlayer1();
    stopPlayer2();

    checkVictoryConditions();

}

void Game::checkVictoryConditions() {

    //std::cout<<"Game Mode"<< m_gameMode <<"\n";
    //Si mode normal  et l'un des joueurs atteints le score max de la partie
    if ((m_scorePlayer1 >= m_endScore || m_scorePlayer2 >= m_endScore) && m_gameMode == 1) {

        m_isActive = false;;
        m_gameEnded = true;

        //Ecran de fin et de victoire ou défaite

        //En mode deux joueurs
        if (m_is2PlayersMode) {
            //Affiche le player victorieux
            if (m_scorePlayer1 > m_endScore) {
                //Affiche Player 1 Wins

                m_Player1Victory = true;

            }
            else {
                //Affiche Player 2 wins
                m_Player2Victory = true;

            }
        }
        else {//Mode 1 joueur affiche vistoire ou défaite
            if (m_scorePlayer1 > m_endScore) {
                //Affiche You win
                m_YouWin = true;
            }
            else {
                //Affiche You lose
                m_YouLose = true;
            }
        }

    }//En mode endurance à 1 joueur
    else if(m_scorePlayer1 < m_scorePlayer2 && m_gameMode > 1 && !m_mode2Players) {

        //std::cout<<"Game ended ... \n";

        m_isActive = false;
        m_gameEnded = true;

        //Le joueur 1 Perd en mode endurance, Affichage Game over et stockage du score si necessaire
        if (!m_isSaveNeeded) {

        }
            else {
                m_YouWin = true;
                int scoresOrdered[11];
                std::string scores[10];
                //int scores[10];

                std::ifstream fichier("Assets/Resources/scores.txt");
                //Récupère les scores
                if (fichier.is_open()) {
                    for (int i = 0; i<10; i++) {
                        std::getline(fichier, scores[i]);

                        //std::cout << "Récupéré : " << scores[i] << std::endl;

                    }
                }
                else {
                    std::cout<<"Erreur lecture fichier."<< std::endl;
                }

                for (int i = 0; i<10; i++) {
                    //     //scoresOrdered = atoi(scores[i].c_str());
                    //scoresOrdered[i] = std::stol(scores[i]);

                    std::string s = scores[i];

                    if (!s.empty()) {

                        scoresOrdered[i] = std::stoi(s);

                        //std::cout << "stocké : "<< scoresOrdered[i] << std::endl;

                    }
                    else {
                        scoresOrdered[i] = 0;

                        //std::cout << "stocké (vide) : "<< scoresOrdered[i] << std::endl;

                    }

                }

                scoresOrdered[10] = m_scorePlayer1;

                // Calculate the size of the array
                int n = sizeof(scoresOrdered) / sizeof(scoresOrdered[0]);

                // Sort the array using std::sort()
                std::sort(scoresOrdered, scoresOrdered + n);

                // std::sort(scoresOrdered, scoresOrdered+11);
                // qsort(scoresOrdered, )(std::greater<int>());

                fichier.close();

                std::ofstream fichierEcriture("Assets/Resources/scores.txt");

                std::string sauvegarde = "";

                if (fichierEcriture.is_open()) {
                    for (int i = 10; i>0; i--) {
                        //fichierEcriture<<scoresOrdered[i]<<std::endl;

                        if (m_scorePlayer1 > scoresOrdered[i]) {
                            this->m_highscore = true;
                        }

                        sauvegarde += std::to_string(scoresOrdered[i]) + "\n";

                        //std::cout<< "Ecriture : " <<scoresOrdered[i]<<std::endl;

                    }

                    fichierEcriture.write(sauvegarde.c_str(), size(sauvegarde));
                }
                else {
                    std::cout<<"File error"<<std::endl;
                }



                fichierEcriture.close();

                m_isSaveNeeded = false;
            }

    }

}

void Game::backgroundVibration() {


    m_isFlashing = true;


}

void Game::movePlayer2Up()
{
    if (this->m_isActive && this->m_is2PlayersMode) {
        this->movePlayer2 = -1;
    }

}

void Game::movePlayer2Down()
{
    if (this->m_isActive && this->m_is2PlayersMode) {
        this->movePlayer2 = 1;
    }

}

void Game::stopPlayer2() {
    if (this->m_isActive && this->m_is2PlayersMode) {
        this->movePlayer2 = 0;
    }
}

void Game::setVolume(float volume) {

    m_ball.setVolume(volume);

}

void Game::setStartingVolume(float volume) {
    m_ball.setVolume(volume);
}

void Game::resetScore() {
    m_scorePlayer1 = 0;
    m_scorePlayer2 = 0;

    m_scorePlayer1Lbl.setString(std::to_string(m_scorePlayer1));
    m_scorePlayer2Lbl.setString(std::to_string(m_scorePlayer2));
}

void Game::setGameMode(int mode) {

    std::cout << "set game mode to "<< mode << "\n";

    m_gameMode = mode;
}

Game::~Game() = default;
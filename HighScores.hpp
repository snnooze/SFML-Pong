#ifndef SFML_PONG_HIGHSCORES_HPP
#define SFML_PONG_HIGHSCORES_HPP
#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <iostream>
#include <fstream>

class HighScores {

    private:

    bool m_isScoreNeeded = true;

    std::string m_scores[10];

    sf::RenderWindow *m_parent;
    sf::Texture *m_textures;
    sf::Font m_Font;

    Button m_retour = Button(*this->m_textures, sf::IntRect(sf::Vector2i(0,0), sf::Vector2(150, 64)));

    sf::Text m_titleText = sf::Text(this->m_Font, "");
    sf::Text m_retourText = sf::Text(this->m_Font, "");
    sf::Text m_highScoresText = sf::Text(this->m_Font, "");

    void getScores();

    public:
    HighScores(sf::RenderWindow &par, sf::Texture &textures, sf::Font &font);
    void update(float dtTime);
    void draw();
    void closeScores();
    ~HighScores();
};


#endif //SFML_PONG_HIGHSCORES_HPP

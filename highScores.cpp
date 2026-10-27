#include "HighScores.hpp"

HighScores::HighScores(sf::RenderWindow &par, sf::Texture &textures, sf::Font &font) {
    this->m_parent = &par;
    this->m_textures = &textures;

    if(!this->m_Font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    this->m_highScoresText.setFont(this->m_Font);
    this->m_highScoresText.setCharacterSize(30);
    this->m_highScoresText.setFillColor(sf::Color::White);
    this->m_highScoresText.setString("High Scores");

    float longueur = this->m_highScoresText.getLocalBounds().getCenter().x;
    float hauteur = this->m_highScoresText.getLocalBounds().getCenter().y;
    this->m_highScoresText.setOrigin({longueur,hauteur});


}

void HighScores::update(float dtime) {

    if (m_isScoreNeeded) {
        this->getScores();
        m_isScoreNeeded = false;
    }

    std::string scores = "";
    int s = 1;

    for(int i  = 0; i<10; i++)
    {
        scores  += std::to_string(s) + ". " + this->m_scores[i] + "\n";

        s++;
    }

    this->m_titleText.setString(scores);

    std::cout<<scores;
}

void HighScores::draw() {
    sf::IntRect rectangle = sf::IntRect( {0,0},{1287, 726} );

    sf::Sprite background = sf::Sprite(*this->m_textures, rectangle);

    this->m_parent->draw(background);

    this->m_highScoresText.setPosition(sf::Vector2f(this->m_parent->getSize().x/2,35));
    this->m_parent->draw(this->m_highScoresText);

    this->m_titleText.setCharacterSize(24);
    this->m_titleText.setFillColor(sf::Color::White);
    this->m_titleText.setOutlineColor(sf::Color::Black);
    this->m_titleText.setOutlineThickness(1);

    this->m_titleText.setPosition(sf::Vector2f(this->m_parent->getSize().x/2 - (this->m_titleText.getLocalBounds().size.x/2),70));
    this->m_parent->draw(this->m_titleText);

    //this->m_retour.setPosition(sf::Vector2f(this->m_parent->getSize().x/2,this->m_parent->getSize().y -100));
}

void HighScores::getScores() {
    std::ifstream fichier("Assets/Resources/scores.txt");
    //Récupère les scores
    if (fichier.is_open()) {
        for (int i = 0; i<10; i++) {
            std::getline(fichier,this->m_scores[i]);
        }
    }

    for (int i = 0; i< 10; i++) {
        std::cout << this->m_scores[i];
    }

    fichier.close();
}

void HighScores::closeScores() {
    m_isScoreNeeded = true;

}

HighScores::~HighScores() = default;

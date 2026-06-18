#include "SettingsScreen.hpp"

SettingsScreen::SettingsScreen(sf::RenderWindow &par, sf::Texture textures[6], sf::Font &font)
{
    //Get the parent Window
    this->m_parent = &par;

    //Loading the font for writing text on the view
    if(!this->m_Font.openFromFile("Assets/Fonts/kenvector_future_thin.ttf"))
    {
        std::cout<<"Font could not be opened"<<std::endl;
    }

    //Get the textures loaded at the game launch
    for(int i = 0; i<=5; i++)
    {
        this->m_textures[i] = &textures[i];
    }


        this->m_stateText.setFont(this->m_Font);
        this->m_stateText.setCharacterSize(30);
        this->m_stateText.setFillColor(sf::Color::White);
        this->m_stateText.setString("Settings");
        float longueur = this->m_stateText.getLocalBounds().getCenter().x;
        float hauteur = this->m_stateText.getGlobalBounds().getCenter().y;
        this->m_stateText.setOrigin({longueur,hauteur});

        this->m_textMusicVolume.setFont(this->m_Font);
        this->m_textMusicVolume.setCharacterSize(20);
        this->m_textMusicVolume.setFillColor(sf::Color::White);
        this->m_textMusicVolume.setString("Music Volume");
        longueur = this->m_textMusicVolume.getLocalBounds().getCenter().x;
        hauteur = this->m_textMusicVolume.getGlobalBounds().getCenter().y;
        this->m_textMusicVolume.setOrigin({longueur,hauteur});

        this->m_textSFXVolume.setFont(this->m_Font);
        this->m_textSFXVolume.setCharacterSize(20);
        this->m_textSFXVolume.setFillColor(sf::Color::White);
        this->m_textSFXVolume.setString("SFX Volume");
        longueur = this->m_textSFXVolume.getLocalBounds().getCenter().x;
        hauteur = this->m_textSFXVolume.getGlobalBounds().getCenter().y;
        this->m_textSFXVolume.setOrigin({longueur,hauteur});

        this->m_textGameMode.setFont(this->m_Font);
        this->m_textGameMode.setCharacterSize(20);
        this->m_textGameMode.setFillColor(sf::Color::White);
        this->m_textGameMode.setString("Game mode");
        longueur = this->m_textGameMode.getLocalBounds().getCenter().x;
        hauteur = this->m_textGameMode.getGlobalBounds().getCenter().y;
        this->m_textGameMode.setOrigin({longueur,hauteur});

        this->m_buttonMoinsMusique.setTexture(*this->m_textures[5]);
        this->m_buttonPlusMusique.setTexture(*this->m_textures[5]);

        this->m_buttonMoinsSFX.setTexture(*this->m_textures[5]);
        this->m_buttonPlusSFX.setTexture(*this->m_textures[5]);

        this->m_textPlus1.setFont(this->m_Font);
        this->m_textPlus1.setCharacterSize(35);
        this->m_textPlus1.setFillColor(sf::Color::White);
        this->m_textPlus1.setString("+");
        longueur = this->m_textPlus1.getLocalBounds().getCenter().x;
        hauteur = this->m_textPlus1.getGlobalBounds().getCenter().y;
        this->m_textPlus1.setOrigin({longueur,hauteur});

        this->m_textMoins1.setFont(this->m_Font);
        this->m_textMoins1.setCharacterSize(35);
        this->m_textMoins1.setFillColor(sf::Color::White);
        this->m_textMoins1.setString("-");
        longueur = this->m_textMoins1.getLocalBounds().getCenter().x;
        hauteur = this->m_textMoins1.getGlobalBounds().getCenter().y;
        this->m_textMoins1.setOrigin({longueur,hauteur});

        this->m_textPlus2.setFont(this->m_Font);
        this->m_textPlus2.setCharacterSize(35);
        this->m_textPlus2.setFillColor(sf::Color::White);
        this->m_textPlus2.setString("+");
        longueur = this->m_textPlus2.getLocalBounds().getCenter().x;
        hauteur = this->m_textPlus2.getGlobalBounds().getCenter().y;
        this->m_textPlus2.setOrigin({longueur,hauteur});

        this->m_textMoins2.setFont(this->m_Font);
        this->m_textMoins2.setCharacterSize(35);
        this->m_textMoins2.setFillColor(sf::Color::White);
        this->m_textMoins2.setString("-");
        longueur = this->m_textMoins2.getLocalBounds().getCenter().x;
        hauteur = this->m_textMoins2.getGlobalBounds().getCenter().y;
        this->m_textMoins2.setOrigin({longueur,hauteur});

        this->m_textGameModeSelected.setFont(this->m_Font);
        this->m_textGameModeSelected.setCharacterSize(20);
        this->m_textGameModeSelected.setFillColor(sf::Color::White);
        this->m_textGameModeSelected.setString("Normal");
        longueur = this->m_textGameModeSelected.getLocalBounds().getCenter().x;
        hauteur = this->m_textGameModeSelected.getGlobalBounds().getCenter().y;
        this->m_textGameModeSelected.setOrigin({longueur,hauteur});

        this->m_buttonGameMode.setTexture(*this->m_textures[1]);
        this->m_buttonGameMode.setOrigin(this->m_buttonGameMode.getLocalBounds().getCenter());

        this->m_buttonSave.setTexture(*this->m_textures[1]);
        this->m_buttonSave.setOrigin(this->m_buttonSave.getLocalBounds().getCenter());

        this->m_textSave.setFont(this->m_Font);
        this->m_textSave.setCharacterSize(20);
        this->m_textSave.setFillColor(sf::Color::White);
        this->m_textSave.setString("Save");
        longueur = this->m_textSave.getLocalBounds().getCenter().x;
        hauteur = this->m_textSave.getGlobalBounds().getCenter().y;
        this->m_textSave.setOrigin({longueur,hauteur});

}

void SettingsScreen::switchGameMode() {

    if (this->m_textGameModeSelected.getString()  == "Normal") {
        this->m_textGameModeSelected.setString("Endurance");
    }
    else {
        this->m_textGameModeSelected.setString("Normal");
    }

}

void SettingsScreen::update(float dt) {

    switch (this->menuPosition.y) {
        case 1 :
            if (this->menuPosition.x == 1) {
                this->m_buttonMoinsMusique.m_position = 1;
                this->m_buttonPlusMusique.m_position = 0;
                this->m_buttonSave.m_position = 0;
                this->m_buttonGameMode.m_position = 0;
                this->m_buttonMoinsSFX.m_position = 0;
                this->m_buttonPlusSFX.m_position = 0;

            }
            else {
                this->m_buttonMoinsMusique.m_position = 0;
                this->m_buttonPlusMusique.m_position = 1;
                this->m_buttonSave.m_position = 0;
                this->m_buttonGameMode.m_position = 0;
                this->m_buttonMoinsSFX.m_position = 0;
                this->m_buttonPlusSFX.m_position = 0;
            }
            break;
            case 2 :
            if (this->menuPosition.x == 1) {

                this->m_buttonMoinsMusique.m_position = 0;
                this->m_buttonPlusMusique.m_position = 0;
                this->m_buttonSave.m_position = 0;
                this->m_buttonGameMode.m_position = 0;
                this->m_buttonMoinsSFX.m_position = 1;
                this->m_buttonPlusSFX.m_position = 0;

            }
            else {
                this->m_buttonMoinsMusique.m_position = 0;
                this->m_buttonPlusMusique.m_position = 0;
                this->m_buttonSave.m_position = 0;
                this->m_buttonGameMode.m_position = 0;
                this->m_buttonMoinsSFX.m_position = 0;
                this->m_buttonPlusSFX.m_position = 1;
            }
            break;
            case 3 :
            if (this->menuPosition.x == 1) {
                this->m_buttonMoinsMusique.m_position = 0;
                this->m_buttonPlusMusique.m_position = 0;
                this->m_buttonSave.m_position = 0;
                this->m_buttonGameMode.m_position = 1;
                this->m_buttonMoinsSFX.m_position = 0;
                this->m_buttonPlusSFX.m_position = 0;
            }
            break;
            case 4 :
            if (this->menuPosition.x == 1) {
                this->m_buttonMoinsMusique.m_position = 0;
                this->m_buttonPlusMusique.m_position = 0;
                this->m_buttonSave.m_position = 1;
                this->m_buttonGameMode.m_position = 0;
                this->m_buttonMoinsSFX.m_position = 0;
                this->m_buttonPlusSFX.m_position = 0;
            }
            break;
        default:
            this->m_buttonMoinsMusique.m_position = 1;
            this->m_buttonPlusMusique.m_position = 0;
            this->m_buttonSave.m_position = 0;
            this->m_buttonGameMode.m_position = 0;
            this->m_buttonMoinsSFX.m_position = 0;
            this->m_buttonPlusSFX.m_position = 0;
            break;
    }

    this->m_buttonMoinsMusique.setHover();
    this->m_buttonPlusMusique.setHover();
    this->m_buttonSave.setHover();
    this->m_buttonGameMode.setHover();
    this->m_buttonMoinsSFX.setHover();
    this->m_buttonPlusSFX.setHover();

    this->m_textGameModeSelected.setOrigin(this->m_textGameModeSelected.getLocalBounds().getCenter());
    this->m_textGameModeSelected.setPosition(this->m_buttonGameMode.getGlobalBounds().getCenter());



}

void SettingsScreen::setVolumeBtn(float volumeBtn) {
    this->m_buttonMoinsMusique.setVolumeBtn(volumeBtn);
    this->m_buttonPlusMusique.setVolumeBtn(volumeBtn);
    this->m_buttonSave.setVolumeBtn(volumeBtn);
    this->m_buttonGameMode.setVolumeBtn(volumeBtn);
    this->m_buttonMoinsSFX.setVolumeBtn(volumeBtn);
    this->m_buttonPlusSFX.setVolumeBtn(volumeBtn);
}

void SettingsScreen::storeVolumeMusic(float volumeMusic) {

    this->m_volumeMusic += volumeMusic;

    if (this->m_volumeMusic < 0) {
        this->m_volumeMusic = 0;
    }
    if (this->m_volumeMusic >100) {
        this->m_volumeMusic = 100;
    }
}

void SettingsScreen::storeVolumeSFX(float volumeSFX) {

    this->m_volumeSFX += volumeSFX;

    if (this->m_volumeSFX < 0) {
        this->m_volumeSFX = 0;
    }
    if (this->m_volumeSFX >100) {
        this->m_volumeSFX = 100;
    }

}

void SettingsScreen::draw() {

    sf::IntRect rectangle = sf::IntRect( {0,0},{1287, 726} );

    sf::Sprite background = sf::Sprite(*this->m_textures[2], rectangle);

    this->m_parent->draw(background);

    this->m_stateText.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,35));

    this->m_textMusicVolume.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,90));

    this->m_buttonMoinsMusique.setPosition(sf::Vector2f(this->m_parent->getSize().x/6,110));
    this->m_textMoins1.setPosition(this->m_buttonMoinsMusique.getGlobalBounds().getCenter());
    this->m_buttonPlusMusique.setPosition(sf::Vector2f((this->m_parent->getSize().x/6)*1.7,110));
    this->m_textPlus1.setPosition(this->m_buttonPlusMusique.getGlobalBounds().getCenter());

    this->m_textSFXVolume.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,200));

    this->m_buttonMoinsSFX.setPosition(sf::Vector2f(this->m_parent->getSize().x/6,215));
    this->m_textMoins2.setPosition(this->m_buttonMoinsSFX.getGlobalBounds().getCenter());
    this->m_buttonPlusSFX.setPosition(sf::Vector2f((this->m_parent->getSize().x/6)*1.7,215));
    this->m_textPlus2.setPosition(this->m_buttonPlusSFX.getGlobalBounds().getCenter());


    this->m_textGameMode.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,310));
    this->m_buttonGameMode.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,370));
    this->m_textGameModeSelected.setPosition(this->m_buttonGameMode.getGlobalBounds().getCenter());

    this->m_buttonSave.setPosition(sf::Vector2f(this->m_parent->getSize().x/4,this->m_parent->getSize().y -100));
    this->m_textSave.setPosition(this->m_buttonSave.getGlobalBounds().getCenter());

    this->m_parent->draw(this->m_stateText);

    this->m_parent->draw(this->m_textMusicVolume);

    this->m_parent->draw(this->m_buttonMoinsMusique);
    this->m_parent->draw(this->m_buttonPlusMusique);
    this->m_parent->draw(this->m_textPlus1);
    this->m_parent->draw(this->m_textMoins1);

    this->m_parent->draw(this->m_buttonMoinsSFX);
    this->m_parent->draw(this->m_buttonPlusSFX);
    this->m_parent->draw(this->m_textPlus2);
    this->m_parent->draw(this->m_textMoins2);

    this->m_parent->draw(this->m_textSFXVolume);

    this->m_parent->draw(this->m_textGameMode);
    this->m_parent->draw(this->m_buttonGameMode);
    this->m_parent->draw(this->m_textGameModeSelected);

    this->m_parent->draw(this->m_buttonSave);
    this->m_parent->draw(this->m_textSave);
}

void SettingsScreen::saveConfig() {

    float volumeMusique = this->m_volumeMusic;
    float volumeSFX = this->m_volumeSFX;
    int gameMode = 1;

    if (this->m_textGameModeSelected.getString() != "Normal") {
        gameMode = 2;
    }

    FILE *fichier;

    if (fichier = std::fopen("Assets/Resources/config.txt", "w")) {

        std::string sortie = std::to_string(volumeMusique) + "\n" + std::to_string(volumeSFX) + "\n" + std::to_string(gameMode);
        if (std::fprintf(fichier, sortie.c_str())) {
            this->m_textSave.setString("Saved");
        }
        else {
            this->m_textSave.setString("Error");
        }

    }
    else {
        this->m_textSave.setString("Error");
    }

    fclose(fichier);

}

SettingsScreen::~SettingsScreen() = default;
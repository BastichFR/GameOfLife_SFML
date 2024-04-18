#include "../../includes/Graphics/Class/Text.hpp"

//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● Public Functions ●                                ║
//  ║                                                                              ║
//  ║                             • • • • • • • •                                  ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝


Text::Text(){

    if (!this->font.loadFromFile(FONT)) {
        std::cerr << "Error: Invalid RenderWindow pointer!" << std::endl;
        return;
    }

    SetTitleText();
    SetTitleParams();

    SetFooterText();
    SetFooterParams();

    SetModeName();
    SetKeyBinds();
}

void Text::draw()
{
    
    for (int i = 0; i < 3; ++i) {
        this->Game::m_window->draw(this->TitleText[i]);
        this->Game::m_window->draw(this->TitleParams[i]);
    }

    
    for (int i = 0; i < 3; ++i) {
        this->Game::m_window->draw(this->FooterText[i]);
        this->Game::m_window->draw(this->FooterParams[i]);
    }

    this->Game::m_window->draw(this->ModeName);
    this->Game::m_window->draw(this->KeySet);
}

void Text::update() {
    SetTitleText();
    SetTitleParams();

    SetFooterText();
    SetFooterParams();

    SetModeName();
    SetKeyBinds();
}


//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● Private Functions ●                               ║
//  ║                                                                              ║
//  ║                             • • • • • • • •                                  ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝


void Text::SetTitleText() {
    sf::String Text[] = { "Rows: ", "Cols: "};

    for (int i = 0; i < 2; ++i){
        this->TitleText[i].setFont(this->font);
        this->TitleText[i].setString(Text[i]);
        this->TitleText[i].setCharacterSize(12);
        this->TitleText[i].setFillColor(sf::Color::Cyan);
        this->TitleText[i].setPosition(30.f + (100.f * i), 7.f);
    }
}

void Text::SetTitleParams() {
    sf::String Text[] = { std::to_string(this->Game::rows), std::to_string(this->Game::cols)};

    for (int i = 0; i < 2; ++i) {

        std::string formattedText = Text[i];
        formattedText.insert(0, 10 - formattedText.size(), ' ');

        this->TitleParams[i].setFont(this->font);
        this->TitleParams[i].setString(formattedText);
        this->TitleParams[i].setCharacterSize(12);
        this->TitleParams[i].setFillColor(sf::Color::White);
        this->TitleParams[i].setPosition(80.f + (100.f * i), 7.f);
    }    
}

void Text::SetFooterText(){
    sf::String Text[] = { "Generation: ", "Speed: " };

    for (int i = 0; i < 2; ++i) {
        this->FooterText[i].setFont(this->font);
        this->FooterText[i].setString(Text[i]);
        this->FooterText[i].setCharacterSize(12);
        this->FooterText[i].setFillColor(sf::Color::Cyan);

        this->FooterText[i].setPosition(30.f + (110.f * i), this->m_window->getSize().y - 3 * PADDING / 4);
    }
}

void Text::SetFooterParams(){
    sf::String Text[] = { std::to_string(this->Game::gen), std::to_string(this->Game::speed) };

    for (int i = 0; i < 2; ++i) {

        std::string formattedText = Text[i];
        formattedText.insert(0, 5 - formattedText.size(), ' ');

        this->FooterParams[i].setFont(this->font);
        this->FooterParams[i].setString(formattedText);
        this->FooterParams[i].setCharacterSize(12);
        this->FooterParams[i].setFillColor(sf::Color::White);
        this->FooterParams[i].setPosition(110.f + (90.f * i), this->m_window->getSize().y - 3 * PADDING / 4);
    }
}

void Text::SetModeName() {
    std::string Title = (this->gamemode == GameMode::Edit ? "Editing Mode" : "Play Mode");

    this->ModeName.setFont(font);
    this->ModeName.setString(Title);
    this->ModeName.setCharacterSize(30);
    this->ModeName.setFillColor(sf::Color(255, 155, 0));

    float textWidth = this->ModeName.getLocalBounds().width;
    float centerX = (this->m_window->getSize().x - TEXT_SPACE / 2) - (textWidth / 2);

    this->ModeName.setPosition(centerX, this->m_window->getSize().y / 10);
}

void Text::SetKeyBinds(){

    std::string EditkeyDescription = "'<' / '>' : Change mode\n'E' : Erase board\n'R' : Fill board\n'Left click' : Add cell\n'Right click' : Remove cell";
    std::string PlaykeyDescription = "'<' / '>' : Change mode\n'+' : Increase speed\n'-' Decrease speed\n'Espace' : Pause/NextGen";
    std::string keyDescription = (this->gamemode == GameMode::Edit ? EditkeyDescription : PlaykeyDescription);

    this->KeySet.setFont(this->font);
    this->KeySet.setString(keyDescription);
    this->KeySet.setCharacterSize(20);
    this->KeySet.setFillColor(sf::Color(30, 120, 30));

    float textWidth = this->KeySet.getLocalBounds().width;
    float centerX = (this->m_window->getSize().x - TEXT_SPACE / 2) - (textWidth / 2);

    this->KeySet.setPosition(centerX, this->m_window->getSize().y / 10 + 2 * PADDING);
}



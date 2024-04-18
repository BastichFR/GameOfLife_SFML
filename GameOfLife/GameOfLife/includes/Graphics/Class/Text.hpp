#ifndef TEXT_HPP
#define TEXT_HPP

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>

#include "Game.hpp"

#define FONT "./Assets/Fonts/arial.ttf"


/// <summary>
///		Get variables from <Game>
///		Display informations around the grid in SFML window
/// </summary>
class Text : Game{
private:
    sf::Font font;
    
    // Upper text
    sf::Text TitleText[3];
    sf::Text TitleParams[3];

    // Lower text
    sf::Text FooterText[3];
    sf::Text FooterParams[3];

    // Right Text
    sf::Text ModeName;
    sf::Text KeySet;


    void SetTitleText();
    void SetTitleParams();

    void SetFooterText();
    void SetFooterParams();

    void SetModeName();
    void SetKeyBinds();

public:
    Text();
    void update();
    void draw();
};


#endif // TEXT_HPP

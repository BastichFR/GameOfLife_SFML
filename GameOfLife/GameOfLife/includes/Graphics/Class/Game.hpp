#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>

#include "../../includes/Common/Files/Update.hpp"
#include "../../includes/Common/Class/Matrix.hpp"

#define PADDING 30
#define TEXT_SPACE 340

// Size of a cell in the window
#define SIZE_X ((m_window->getSize().x - 2 * PADDING - TEXT_SPACE) / rows)
#define SIZE_Y ((m_window->getSize().y - 2 * PADDING) / cols)

/// <summary>
///     Gamemode to separate the editing part , in whch you can add/remove cells,
///     and the game part in which you watch the cells evolving
/// </summary>
enum GameMode {
    Edit = 0,
    Play = 1
};


/// <summary>
///     Controls the evolution of the board
///     Contains informations about the evolution (used in SFML window)
///     Handle interaction events between the user and the window
/// </summary>
class Game {
private: 
    // for sfml actualisation
    sf::Clock clock;

protected:
    // common values (also used in SFML display)
    static sf::RenderWindow* m_window;
    static int rows;
    static int cols;
    static int gen;
    static int speed;
    static GameMode gamemode;
    static Matrix* mat;

public:

    Game(sf::RenderWindow* window, int rows, int cols);
    Game() = default;


    // ==========  Handle Matrix Updates  ========== //
    void FillBoard();
    void ClearBoard();

    void AddCell(int x, int y);
    void RemoveCell(int x, int y);

    void upgrade();
    void update();

    // ================  Get / Set  ================ //

    void SwitchGameMode()   { this->gamemode = (this->gamemode == GameMode::Edit) ? GameMode::Play : GameMode::Edit; }
    GameMode GetGameMode()  { return this->gamemode; }

    void SetSpeed(int speed){ this->speed = speed; }
    int GetSpeed()          { return this->speed; }

    void ResetGen()         { this->gen = 0; }
};

#endif // GAME_HPP

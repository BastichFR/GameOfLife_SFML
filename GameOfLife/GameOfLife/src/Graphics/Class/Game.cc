#include "../../includes/Graphics/Class/Game.hpp"


// Initialization for static values

sf::RenderWindow* Game::m_window = nullptr;
int Game::rows = 0;
int Game::cols = 0;
int Game::gen = 0;
int Game::speed = 0;
GameMode Game::gamemode = GameMode::Edit;
Matrix* Game::mat = nullptr;


//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● Public Functions ●                                ║
//  ║                                                                              ║
//  ║                             • • • • • • • •                                  ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝


Game::Game(sf::RenderWindow* window, int rows, int cols) {

    if (window == nullptr) {
        std::cerr << "Error: Invalid RenderWindow pointer!" << std::endl;
        return;
    }

    this->m_window = window;
    this->rows = rows;
    this->cols = cols;
    this->gen = 0;
    this->speed = 0;
    this->gamemode = GameMode::Edit;
    this->mat = new Matrix(this->rows, this->cols);
}

void Game::FillBoard()
{
	this->mat->FillMatrix();
}

void Game::ClearBoard()
{
	this->mat->ClearMatrix();
}


void Game::AddCell(int x, int y) {

	if (x < PADDING || x > PADDING + rows * SIZE_X || y < PADDING || y > PADDING + cols * SIZE_Y) {
		return;
	}

	int cellX = (x - PADDING) / SIZE_X;
	int cellY = (y - PADDING) / SIZE_Y;

	this->mat->data[cellX][cellY] = true;
}

void Game::RemoveCell(int x, int y) {

	if (x < PADDING || x > PADDING + rows * SIZE_X || y < PADDING || y > PADDING + cols * SIZE_Y) {
		return;
	}

	int cellX = (x - PADDING) / SIZE_X;
	int cellY = (y - PADDING) / SIZE_Y;

	this->mat->data[cellX][cellY] = false;
}


void Game::upgrade() {
	if (this->speed != 0) {
		this->speed = 0;
	}
	else {
		updateBoard(mat);
		this->gen += 1;
	}
}

void Game::update() {
	if ((this->gamemode == GameMode::Play) && (this->speed != 0) && (this->clock.getElapsedTime().asSeconds() >= 1.0f / this->speed)) {

		updateBoard(this->mat);
		this->gen += 1;

		clock.restart();
	}
}
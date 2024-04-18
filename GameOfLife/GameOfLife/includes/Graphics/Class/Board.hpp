#ifndef BOARD_HPP
#define BOARD_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Game.hpp"

/// <summary>
///		Get variables from <Game>
///		Display the grid and the cells on the SFML window
/// </summary>
class Board : public Game{
	private:
		std::vector<sf::RectangleShape> Lines;
		std::vector<sf::RectangleShape> Cells;

		void DrawGrid();
		void DrawCells();

	public:

		Board();
		void draw();
		void update();
};

#endif // BOARD_HPP
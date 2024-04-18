#include "../../includes/Graphics/Class/Board.hpp"


//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● Public Functions ●                                ║
//  ║                                                                              ║
//  ║                             • • • • • • • •                                  ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝


Board::Board() {
	update();
}

void Board::draw() {
	for (int i = 0; i < Cells.size(); i++) {
		this->m_window->draw(this->Cells[i]);
	}

	for (int i = 0; i < Lines.size(); i++) {
		this->m_window->draw(this->Lines[i]);
	}
}

void Board::update(){
	DrawGrid();
	DrawCells();
}


//  ╔══════════════════════════════════════════════════════════════════════════════╗
//  ║                          ● Private Functions ●                               ║
//  ║                                                                              ║
//  ║                             • • • • • • • •                                  ║
//  ╚══════════════════════════════════════════════════════════════════════════════╝


void Board::DrawGrid() {
	this->Lines.clear();

	float x = PADDING;
	for (int i = 0; i <= rows; ++i) {
		sf::RectangleShape Line;
		Line.setPosition(x, PADDING);
		Line.setSize(sf::Vector2f(1.f, SIZE_Y * cols));
		Line.setFillColor(sf::Color(128, 128, 128));

		this->Lines.push_back(Line);
		x += SIZE_X;
	}

	float y = PADDING;
	for (int i = 0; i <= cols; ++i) {
		sf::RectangleShape Line;
		Line.setPosition(PADDING, y);
		Line.setSize(sf::Vector2f(SIZE_X * rows, 1.f));
		Line.setFillColor(sf::Color(128, 128, 128));

		this->Lines.push_back(Line);
		y += SIZE_Y;
	}
}

void Board::DrawCells() {
	this->Cells.clear();

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (mat->data[i][j] == 1) {
				int x = PADDING + i * SIZE_X;
				int y = PADDING + j * SIZE_Y;

				sf::RectangleShape Cell;
				Cell.setPosition(x, y);
				Cell.setSize(sf::Vector2f(SIZE_X, SIZE_Y));
				Cell.setFillColor(sf::Color::White);

				this->Cells.push_back(Cell);
			}
		}
	}
}


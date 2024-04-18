#include "../../includes/Common/Class/Matrix.hpp"

Matrix::Matrix(int r, int c) : rows(r), cols(c) {

	data = new bool* [rows];
	for (int i = 0; i < rows; ++i) {
		data[i] = new bool[cols];
		for (int j = 0; j < cols; ++j) {
			data[i][j] = false;
		}
	}
}

Matrix::~Matrix(){

	if (data != nullptr) {
		for (int i = 0; i < rows; ++i) {
			delete[] data[i];
		}
		delete[] data;
	}
}

void Matrix::FillMatrix()
{
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			data[x][y] = (rand() % 4 == 0);
		}
	}
}

void Matrix::ClearMatrix()
{
	for (int x = 0; x < rows; x++) {
		for (int y = 0; y < cols; y++) {
			data[x][y] = false;
		}
	}
}
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>


/// <summary>
///		The structure that represent the board.
/// </summary>
struct Matrix {
	int rows;
	int cols;
	bool** data;

	Matrix(int r, int c);
	~Matrix();

	void FillMatrix();
	void ClearMatrix();
};

#endif // MATRIX_HPP

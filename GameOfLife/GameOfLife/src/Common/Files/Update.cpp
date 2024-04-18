#include "../../includes/Common/Files/Update.hpp"

/// <summary>
///		Get neighbours around a given cell of a board
/// </summary>
/// <param name="mat"> The matrix in which we get the neighbours </param>
/// <param name="x"> The x coordonate of the cell </param>
/// <param name="y"> The y coordonate of the cell </param>
/// <returns> the numbers of nneighbours alive </returns>
int getNeighbours(Matrix* mat, int x, int y) {
	int nb = 0;

	for (int i = x - 1; i <= x + 1; i++) {
		if (i >= 0 && i < mat->rows) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (j >= 0 && j < mat->cols && !(i == x && j == y)) {
					nb += mat->data[i][j];
				}
			}
		}
	}
	return nb;
}

/// <summary>
///		Get neighbours around the given cell and apply changes in a new board
/// </summary>
/// <param name="new_mat"> The new board for the next generation </param>
/// <param name="mat"> The actual board befora actualisation </param>
/// <param name="x"> The x coordonate of the cell </param>
/// <param name="y"> The y coordonate of the cell </param>
void updateCell(Matrix* new_mat, Matrix* mat, int x, int y) {
	int nb = getNeighbours(mat, x, y);

	switch (nb) {
	case 3:
		new_mat->data[x][y] = 1;
		break;
	case 2:
		new_mat->data[x][y] = mat->data[x][y];
		break;
	default:
		new_mat->data[x][y] = 0;
	}
}

/// <summary>
///		Create a new board for the next generation.
///		Fill the new board for the next generation and transfere its value in the actual board
/// </summary>
/// <param name="mat"> The board we will update </param>
void updateBoard(Matrix* mat) { 

	Matrix* new_mat = new Matrix(mat->rows, mat->cols);

	for (int x = 0; x < mat->rows; x++) {
		for (int y = 0; y < mat->cols; y++) {
			updateCell(new_mat, mat, x, y);
		}
	}

	for (int x = 0; x < mat->rows; x++) {
		for (int y = 0; y < mat->cols; y++) {
			mat->data[x][y] = new_mat->data[x][y];
		}
	}

	delete new_mat;
}
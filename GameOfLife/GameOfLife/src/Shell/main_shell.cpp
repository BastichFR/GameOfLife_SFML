#include "../../includes/Shell/main_shell.hpp"

/// <summary>
///		Handler for the shell game of life 
///		Ask user for the size of the board
///		Refresh while user type 1
/// </summary>
/// <returns></returns>
int main_shell() {

	int x = GetInput("Board size (nb celles) : \nx (10 - 50) : ", 10, 50);
	int y = GetInput("y (10 - 50) : ", 10, 50);

	Matrix* mat = new Matrix(x, y);
	mat->FillMatrix();

	do {
		DisplayMatrix(mat);
		updateBoard(mat);
	} while (GetInput("Continue (1/0) : ", 0, 1) == 1);

	delete mat;

	return 0;
}
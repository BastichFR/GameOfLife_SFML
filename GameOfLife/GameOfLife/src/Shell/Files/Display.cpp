#include "../../includes/Shell/Files/Display.hpp"

/// <summary>
///		Display the given matrix to the user using the shell
/// </summary>
/// <param name="mat"> The matrix that will be display </param>
void DisplayMatrix(Matrix* mat) {
	for (int x = 0; x < mat->rows; x++) {
		for (int y = 0; y < mat->cols; y++) {
			cout << (mat->data[x][y] == false ? '_' : '*');
		}
		cout << endl;
	}
}
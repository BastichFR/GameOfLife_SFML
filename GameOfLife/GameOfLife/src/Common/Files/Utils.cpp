#include "../../includes/Common/Files/Utils.hpp"

/// <summary>
///		Display a text input and wait for the user to provide a valid value
///		between min and max.
/// </summary>
/// <param name="input"> The string we will display </param>
/// <param name="min"> The min value </param>
/// <param name="max"> The max value </param>
/// <returns> Returns the given valid value </returns>
int GetInput(std::string input, int min, int max) {
	int out = 0;

	do {
		std::cout << input;
		std::cin >> out;
	} while (out < min || max < out);

	return out;
}
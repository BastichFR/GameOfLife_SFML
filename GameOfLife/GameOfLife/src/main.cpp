#include "../includes/main.hpp"


/// <summary>
///		Redirect you depending on whether or not you have choosen the graphical interface
/// </summary>
/// <returns> Returns the result of the called functions </returns>
int main() {
	if (GetInput("Use graphical interface (1/0) : ", 0, 1) == 1) {
		return main_graph();
	}

	return main_shell();
}
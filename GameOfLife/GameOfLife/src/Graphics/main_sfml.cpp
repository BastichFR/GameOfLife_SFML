#include "../../includes/Graphics/main_sfml.hpp"

/// <summary>
///		Get all the events from the window and apply changes on the given game
/// </summary>
/// <param name="window"> The window we get the events from </param>
/// <param name="game"> The game handler we apply changes </param>
void handleEvents(sf::RenderWindow& window, Game& game) {

	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

		if (event.type == sf::Event::Resized) {
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(visibleArea));
		}

		if (event.type == sf::Event::KeyPressed) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))			{
				game.SwitchGameMode();
			}

			if (game.GetGameMode() == GameMode::Play) {
				if (event.key.code == sf::Keyboard::Space) {
					game.upgrade();
				}

				else if (event.key.code == sf::Keyboard::Add) {
					game.SetSpeed(game.GetSpeed() + 1);
				}

				else if (event.key.code == sf::Keyboard::Subtract) {
					game.GetSpeed() == 0 ? game.SetSpeed(0) : game.SetSpeed(game.GetSpeed() - 1);
				}
			}

			if (game.GetGameMode() == GameMode::Edit) {
				game.SetSpeed(0);

				if (event.key.code == sf::Keyboard::R) {
					game.FillBoard();
					game.ResetGen();
				}

				if (event.key.code == sf::Keyboard::E) {
					game.ClearBoard();
					game.ResetGen();
				}

			}
		}

		if (event.type == sf::Event::MouseButtonPressed) {

			if (game.GetGameMode() == GameMode::Edit) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i position = sf::Mouse::getPosition(window);
					game.AddCell(position.x, position.y);
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					sf::Vector2i position = sf::Mouse::getPosition(window);
					game.RemoveCell(position.x, position.y);
				}
			}
		}
	}
}

/// <summary>
///		Get board size from user
///		Refresh and update the window with SFML
/// </summary>
/// <returns></returns>
int main_graph() {

	std::cout << "Board size (nb celles) :" << std::endl;
	int x = GetInput("x (10 - 300) : ", 10, 300);
	int y = GetInput("y (10 - 300) : ", 10, 300);

	sf::RenderWindow window(sf::VideoMode(1300, 960), "Game of life !");

	window.setFramerateLimit(120);

	Game game(&window, x, y);
	Board board = Board();
	Text text = Text();

	while (window.isOpen())	{

		handleEvents(window, game);

		window.clear();

		game.update();
		board.update();
		text.update();

		board.draw();
		text.draw();

		window.display();
	}

	return 0;
}
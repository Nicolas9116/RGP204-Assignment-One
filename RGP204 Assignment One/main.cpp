#include "Game.hpp"
#include "Menu.hpp"

enum class gameState
{
	Menu,
	Playing,
};


int main() 
{
	gameState state = gameState::Menu;
	sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1920, 1080), "One Button Knight");
		
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					state = gameState::Playing;
				}
			}
		}

		window.clear();

		if (state == gameState::Menu)
		{
			Menu menu(window);
			menu.ShowMenu();

			state = gameState::Playing;
		}
		else if (state == gameState::Playing)
		{
			// Create a new instance of the game
			Game game(window);
			// Run the game
			game.Run();
			// Set the state back to the menu
			state == gameState::Menu;
		}

		window.display();
	}

	return 0;
}
#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode(1920, 1080), "One Button Game"), gameTextures(), player(gameTextures.playerTex), stageManager()
{
	window.setFramerateLimit(60);

}

void Game::Run()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Space)
				{
					std::cout << "Space key pressed" << std::endl;
					player.DoOneButtonAction();
				}
			}
		}
		stageManager.Update();

		window.clear();

		
		stageManager.Draw(window);
		window.draw(player.GetPlayerSprite());


		window.display();
	}

}

const GameTextures& Game::GetGameTextures() const
{
	return gameTextures;
}

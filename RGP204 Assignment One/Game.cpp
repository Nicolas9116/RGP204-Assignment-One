#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode(1920, 1080), "One Button Game"), gameTextures(), player(gameTextures.playerTex, groundLevel),groundLevel(800), stageManager(groundLevel), gravity(0, 9.8)
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
					player.DoOneButtonAction(stageManager.GetCurrentStage());
				}
			}
		}

		if (!player.isGrounded(groundLevel))
		{
			player.UpdatePlayerAcceleration(gravity);
			player.UpdatePlayerPosition();
		}
		else
		{
			player.ResetPlayerAcceleration();
			player.ResetPlayerVelocity();
		}

		

		stageManager.Update(player);

		window.clear();

		
		stageManager.Draw(window);
		player.Draw(window);
		window.display();
	}

}

const GameTextures& Game::GetGameTextures() const
{
	return gameTextures;
}

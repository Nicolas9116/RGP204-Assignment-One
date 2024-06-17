#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode(1920, 1080), "One Button Game"), gameTextures(), player(gameTextures.playerSpriteMap, groundLevel),groundLevel(900), stageManager(groundLevel), gravity(0,1), playerAnimation(&gameTextures.playerSpriteMap,sf::Vector2u (6,3),0.08f)
{
	window.setFramerateLimit(60);
}

void Game::Run()
{
	stageManager.InitialStageSetup();
	sf::Clock frameClock;

	while (window.isOpen())
	{

		float m_frame_Time = frameClock.restart().asSeconds();

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
		player.UpdatePlayerVelocity(player.GetPlayerAcceleration());	
		player.UpdatePlayerPosition(m_frame_Time);

		if (!player.isGrounded(groundLevel))
		{
			player.UpdatePlayerAcceleration(gravity);
			player.UpdatePlayerPosition(m_frame_Time);
		}
		else
		{
			player.ResetPlayerAcceleration();
			player.ResetPlayerVelocity();
		}

		playerAnimation.Update(0, m_frame_Time);
		stageManager.Update(player);

		window.clear();
		
		stageManager.Draw(window);
		player.Draw(window, playerAnimation.GetUVRect());

		window.display();
	}

}

const GameTextures& Game::GetGameTextures() const
{
	return gameTextures;
}

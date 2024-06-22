#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow& window) : window(window), gameTextures(), player(gameTextures.playerSpriteMap,gameTextures.playerAttackTex,gameTextures.playerJumpTex, groundLevel),groundLevel(900), stageManager(groundLevel), gravity(0,1)
{
	window.setFramerateLimit(60);
}

void Game::Run()
{
	stageManager.InitialStageSetup();
	sf::Clock frameClock;
	window.setMouseCursorVisible(true);

	while (!player.isDeadCheck())
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

		if (!player.isGrounded(groundLevel, stageManager.GetCurrentStage()))
		{
			player.UpdatePlayerAcceleration(gravity);
			player.UpdatePlayerPosition(m_frame_Time);
		}
		else
		{
			player.ResetPlayerAcceleration();
			player.ResetPlayerVelocity();
		}

		window.clear();

		stageManager.Update(player);
		stageManager.Draw(window, m_frame_Time);

		player.Draw(window, m_frame_Time);


		window.display();
	}

}

const GameTextures& Game::GetGameTextures() const
{
	return gameTextures;
}

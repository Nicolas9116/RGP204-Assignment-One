#include "Game.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

Game::Game(sf::RenderWindow& window) : window(window), gameTextures(), player(gameTextures.playerSpriteMap,gameTextures.playerAttackTex,gameTextures.playerJumpTex, groundLevel),groundLevel(900), stageManager(groundLevel), gravity(0,9.8f)
{
}

void Game::Run()
{
	stageManager.InitialStageSetup();
	window.setMouseCursorVisible(true);	
	sf::Clock frameClock;
	
	while (!player.isDead)
	{	

		std::cout << "Player is dead?" << player.isDead <<std::endl;	
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


			player.Update(player, gravity, m_frame_Time, stageManager);
		

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

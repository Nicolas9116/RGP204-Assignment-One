#pragma once
#include <SFML/Graphics.hpp>
#include "GameTextures.hpp"
#include "Player.hpp"
#include "StageManager.hpp"


class Game
{
public:
	Game();
	void Run();

	const GameTextures& GetGameTextures() const;
	const Player& GetPlayer() const { return player; }
	const sf::RenderWindow& GetWindow() const { return window; }

private:
	const int groundLevel;
	sf::RenderWindow window;
	GameTextures gameTextures;
	Player player;
	sf::Vector2f gravity;
	StageManager stageManager;
};


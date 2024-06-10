#pragma once
#include <SFML/Graphics.hpp>
#include "GameTextures.hpp"
#include "Player.hpp"


class Game
{
public:
	Game();
	void Run();

	const GameTextures& GetGameTextures() const;
	const Player& GetPlayer() const { return player; }
	const sf::RenderWindow& GetWindow() const { return window; }
private:
	sf::RenderWindow window;
	GameTextures gameTextures;
	Player player;
};


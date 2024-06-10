#pragma once
#include <SFML/Graphics.hpp>

enum class equippedItem
{
	none,
	sword,
	shield,
	bow,
	arrow
};

class Player
{
public:
	Player(sf::Texture& playerTex);
	const sf::Sprite& GetPlayerSprite() const { return playerSprite; }
	void DoOneButtonAction();
	void SetEquippedItem(equippedItem item) { equipped = item; }

private:
	sf::Sprite playerSprite;
	equippedItem equipped;
};


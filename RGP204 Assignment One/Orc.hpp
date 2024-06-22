#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.hpp"

class Player;


class Orc
{
public:
	Orc(sf::Texture* orcTex, sf::Texture* orcDeathTex, int spawnX, int spawnY);

	void Update(int stageScrollSpeed, Player& player);
	void Draw(sf::RenderWindow& window, float frame_Time);
	void CheckForPlayerOverlap(Player& player);
	void SetIsDead(bool dead) { isDead = dead; }
	sf::Sprite& GetOrcSprite() { return orcSprite; }

private:

	bool isDead = false;
	sf::Sprite orcSprite;
	Animation orcIdleAnimator;
	Animation orcDeathAnimator;
};


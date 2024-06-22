#include "Orc.hpp"
#include <iostream>
#include "Player.hpp"

Orc::Orc(sf::Texture* orcTex, sf::Texture* orcDeathTex, int spawnX, int spawnY) : orcIdleAnimator(orcTex, sf::Vector2u(3, 1), 0.08f), orcDeathAnimator(orcDeathTex, sf::Vector2u(6, 1), 0.08f)
{
	orcSprite.setTexture(*orcTex);
	orcSprite.setScale(1.0f, 1.0f);
	orcSprite.setPosition(spawnX, spawnY);
}


void Orc::Update(int stageScrollSpeed, Player player)
{
	orcSprite.move(stageScrollSpeed, 0.0f);
	CheckForPlayerOverlap(player);
}

void Orc::Draw(sf::RenderWindow& window, float frame_Time)
{
	if(isDead)
	{
		orcSprite.setTexture(*orcDeathAnimator.GetTexture());
		orcDeathAnimator.Update(0, frame_Time);
		orcSprite.setTextureRect(orcDeathAnimator.GetUVRect());
		window.draw(orcSprite);
		return;
	}
	orcSprite.setTexture(*orcIdleAnimator.GetTexture());
	orcIdleAnimator.Update(0, frame_Time);
	orcSprite.setTextureRect(orcIdleAnimator.GetUVRect());
	window.draw(orcSprite);
}

void Orc::CheckForPlayerOverlap(Player& player)
{
	if (player.GetPlayerSprite().getGlobalBounds().intersects(orcSprite.getGlobalBounds()) && !isDead)
	{
		player.SetIsDead(true);
	}
}

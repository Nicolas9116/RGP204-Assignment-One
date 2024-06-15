#include "Stage.hpp"
#include <iostream>
#include "Player.hpp"
#include <SFML/Graphics.hpp>

RedStage::RedStage(const int& groundLevel) : m_groundLevel(groundLevel)
{
	LoadTextures();
	SetupSprites();
	SetupFakeFloor(m_groundLevel);
}

//void LoadAssets() override;
void RedStage::Update(Player& player)
{
	for (auto& sprite : backgroundSprites)
	{
		sprite.move(stageScrollSpeed, 0);
	}

	for (auto& sprite : enemySprites)
	{
		sprite.move(stageScrollSpeed * 2, 0);
	}

	stageItemSprite.move(stageScrollSpeed, 0);

	CheckForItemPickup(player);
	if (itemPickedUp)
	{
	}

	if (spawnClock.getElapsedTime().asSeconds() > 2)
	{
		SpawnEnemy();
		spawnClock.restart();
	}
}

void RedStage::Draw(sf::RenderWindow& window)
{
	for (auto& sprite : backgroundSprites)
	{
		window.draw(sprite);
	}

	for (auto& sprite : enemySprites)
	{
		window.draw(sprite);
	}

	if (!itemPickedUp)
	{
		window.draw(stageItemSprite);
	}

	window.draw(fakeFloor);
}

void RedStage::LoadTextures()
{
	backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Red.png");
	stageItemTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Items_On_Ground/Sword.png");
	enemyTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Enemies/Enemy.png");
}

void RedStage::SetupSprites()
{
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(1, 1);
	backgroundSprite.setOrigin(backgroundSprite.getGlobalBounds().width / 2, backgroundSprite.getGlobalBounds().height / 2);
	backgroundSprite.setPosition(960, 540);
	backgroundSprites.push_back(backgroundSprite);

	stageItemSprite.setTexture(stageItemTexture);
	stageItemSprite.setScale(1, 1);
	//stageItemSprite.setOrigin(stageItemSprite.getGlobalBounds().width / 2, stageItemSprite.getGlobalBounds().height / 2);
	stageItemSprite.setPosition(500, m_groundLevel - stageItemSprite.getGlobalBounds().height);
}

void RedStage::SetupFakeFloor(const int m_groundLevel)
{
	fakeFloor.setSize(sf::Vector2f(1920, 100));
	fakeFloor.setFillColor(sf::Color::Green);
	fakeFloor.setPosition(0, m_groundLevel);
}

void RedStage::CheckForItemPickup(Player& player)
{
	if (!itemPickedUp && stageItemSprite.getGlobalBounds().intersects(player.GetPlayerSprite().getGlobalBounds()))
	{
		player.EquipItem(equippedItem::sword);
		itemPickedUp = true;
	}
}

void RedStage::SpawnEnemy()
{
	enemySprite.setTexture(enemyTexture);
	enemySprite.setScale(1, 1);
	enemySprite.setPosition((backgroundSprites[0].getGlobalBounds().left + backgroundSprites[0].getGlobalBounds().width), m_groundLevel - enemySprite.getGlobalBounds().height);
	std::cout << enemySprite.getPosition().x << std::endl;
	enemySprites.push_back(enemySprite);
}

void RedStage::IsOffScreen()
{
	if (backgroundSprites.back().getGlobalBounds().left + backgroundSprites.back().getGlobalBounds().width < 0)
	{
		isOffScreen = true;
	}

}

void RedStage::LoadToBack()
{
	int xOffset = 0;
	for (auto& sprite : backgroundSprites)
	{
		sprite.setPosition(1920, 540);
		xOffset += 1920;
	}
}

std::string RedStage::GetStageType()
{
	return stageType;
}

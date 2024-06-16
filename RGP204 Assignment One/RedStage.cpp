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
	/*for (auto& sprite : backgroundSprites)
	{
		sprite.move(stageScrollSpeed, 0);
	}*/

	auto newEnd = std::remove_if(enemySprites.begin(), enemySprites.end(),
		[this](const sf::Sprite& enemy) {
			bool isOutOfBounds = enemy.getPosition().x < backgroundSprite.getPosition().x;
			if (isOutOfBounds) {
				std::cout << "Enemy Out of Bounds" << std::endl;
			}
			return isOutOfBounds; // Remove the sprite if it intersects with the sword hitbox
		});

	backgroundSprite.move(stageScrollSpeed, 0);

	for (auto& sprite : enemySprites)
	{
		sprite.move(stageScrollSpeed * 2, 0);
	}

	stageItemSprite.setPosition(backgroundSprite.getPosition().x + 100, m_groundLevel - stageItemSprite.getGlobalBounds().height);

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
	//for (auto& sprite : backgroundSprites)
	//{
	//	window.draw(sprite);
	//}

	window.draw(backgroundSprite);

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
	//backgroundSprites.push_back(backgroundSprite);

	stageItemSprite.setTexture(stageItemTexture);
	stageItemSprite.setScale(1, 1);
	//stageItemSprite.setOrigin(stageItemSprite.getGlobalBounds().width / 2, stageItemSprite.getGlobalBounds().height / 2);
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
	enemySprite.setScale(2, 2);
	enemySprite.setPosition((backgroundSprite.getGlobalBounds().left + backgroundSprite.getGlobalBounds().width), m_groundLevel - enemySprite.getGlobalBounds().height);
	enemySprites.push_back(enemySprite);
}

void RedStage::IsOffScreen()
{
	if (backgroundSprite.getPosition().x <= -1920)
	{
		isOffScreen = true;
		std::cout << "RED STAGE HAS GONE OFF SCREEN" << std::endl;
	}

}

void RedStage::LoadToBack()
{
	backgroundSprite.setPosition(3840, 0);
	//int xOffset = 0;
	//for (auto& sprite : backgroundSprites)
	//{
	//	sprite.setPosition(1920, 540);
	//	xOffset += 1920;
	//}
}

std::string RedStage::GetStageType()
{
	return stageType;
}

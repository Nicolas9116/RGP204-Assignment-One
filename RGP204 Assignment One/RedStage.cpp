#include "Stage.hpp"
#include <iostream>
#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Orc.hpp"
#include "Item.hpp"


RedStage::RedStage(const int& groundLevel) : 
	m_groundLevel(groundLevel), 
	numberOfEnemies(3), 
	enemies(new std::vector<Orc>),
	sword(stageItemTexture),
	itemPickedUp(false)
{	//SetupFakeFloor(m_groundLevel);
}
//void LoadAssets() override;
void RedStage::Update(Player& player)
{
	backgroundSprite.move(stageScrollSpeed, 0);

	for (auto& enemy : *enemies)
	{
		enemy.Update(stageScrollSpeed, player);
	}

	sword.Update(stageScrollSpeed);
	CheckForItemPickup(player);
}

void RedStage::Draw(sf::RenderWindow& window, float frame_Time)
{
	window.draw(backgroundSprite);

	for (auto& Orc : *enemies)
	{
		Orc.Draw(window, frame_Time);
	}
	
	if (!itemPickedUp)
	{
		sword.Draw(window, frame_Time);
	}


}

void RedStage::LoadTextures()
{
	backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Sword_Stage_Background.png");
	stageItemTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Items_On_Ground/Sword Item.png");
	orcTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Enemies/Orc Idle.png");
	orcDeathTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Enemies/Orc Death.png");
}

void RedStage::SetupSprites()
{
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(1, 1);
}

void RedStage::SetupFakeFloor(const int m_groundLevel)
{
	fakeFloor.setSize(sf::Vector2f(1920, 100));
	fakeFloor.setFillColor(sf::Color::Green);
	fakeFloor.setPosition(0, m_groundLevel);
}

void RedStage::CheckForItemPickup(Player& player)
{
	if (!itemPickedUp && sword.GetSwordSprite().getGlobalBounds().intersects(player.GetPlayerSprite().getGlobalBounds()))
	{
		player.EquipItem(equippedItem::sword);
		this->itemPickedUp = true;
	}
}

void RedStage::SpawnEnemy()
{
	int spawnLocationX = backgroundSprite.getGlobalBounds().left + backgroundSprite.getGlobalBounds().width;
	int spawnLocationY = m_groundLevel - orcTexture.getSize().y;

	for (int i = 0; i < numberOfEnemies; i++)
	{
		spawnLocationX -= 250;
		enemies->emplace_back(&orcTexture, &orcDeathTexture, spawnLocationX, spawnLocationY);
	}
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

void RedStage::SpawnItem()
{
	sword = Sword(stageItemTexture);
	sword.GetSwordSprite().setTexture(stageItemTexture);
	sword.GetSwordSprite().setPosition(backgroundSprite.getPosition().x + 250, m_groundLevel - sword.GetSwordSprite().getGlobalBounds().height);
}

void RedStage::DelayedSetupCall()
{
	LoadTextures();
	SetupSprites();
	SpawnEnemy();
	SpawnItem();
}

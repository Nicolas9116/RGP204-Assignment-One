#include "Stage.hpp"
#include <iostream>
#include "Player.hpp"	
#include "Ground.hpp"

BlueStage::BlueStage(const int& groundLevel) :
	boots(bootsTexture),
	groundLevel(groundLevel),
	numberOfPlatforms(3),
	ground(std::vector<Ground>())
{

}

//void LoadAssets() override;
void BlueStage::Update(Player& player)
{
	boots.Update(stageScrollSpeed);
	backgroundSprite.move(stageScrollSpeed, 0);
	CheckForItemPickup(player);

	for (auto& ground : ground)
	{
		ground.GroundUpdate(0);
	}
}
void BlueStage::Draw(sf::RenderWindow& window, float frame_Time)
{
	window.draw(backgroundSprite);


	if (!itemPickedUp)
	{
		boots.Draw(window, frame_Time);
	}

	for (int i = 0; i < 3; i++)
	{
		ground[i].Draw(window);
	}
}

void BlueStage::LoadTextures()
{
	bootsTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Items_On_Ground/Boots Item.png");
	backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Boots_Stage_Background.png");
	groundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Jumping Block.png");
}

void BlueStage::SetupSprites()
{
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setScale(1, 1);
}

void BlueStage::SetupFakeFloor(const int m_groundLevel)
{

}

void BlueStage::CheckForItemPickup(Player& player)
{
	if (!itemPickedUp && boots.GetBootsSprite().getGlobalBounds().intersects(player.GetPlayerSprite().getGlobalBounds()))
	{
		player.EquipItem(equippedItem::boots);
		this->itemPickedUp = true;
	}
}

void BlueStage::IsOffScreen()
{
	if (backgroundSprite.getPosition().x < -1920)
	{
		isOffScreen = true;
		std::cout << "BLUE STAGE HAS GONE OFF SCREEN" << std::endl;
	}
}

void BlueStage::LoadToBack()
{
	backgroundSprite.setPosition(3840, 0);
}

std::string BlueStage::GetStageType()
{
	return stageType;
}

void BlueStage::SpawnItem()
{
	boots = Boots(bootsTexture);
	boots.GetBootsSprite().setTexture(bootsTexture);
	boots.GetBootsSprite().setPosition(this->backgroundSprite.getPosition().x + 75, groundLevel - boots.GetBootsSprite().getGlobalBounds().height);
}

void BlueStage::DelayedSetupCall()
{
	LoadTextures();
	SetupSprites();
	SpawnItem();
	SpawnPlatforms();
	SpawnBaseGround();
}

//void BlueStage::SpawnPlatforms()
//{
//	for (int i=0; i < numberOfPlatforms; i++)
//	{
//		platforms->emplace_back(positions[i], stageScrollSpeed);
//	}
//}

void BlueStage::SpawnPlatforms()
{
	// First, create and add platforms to the vector
	for (int i = 0; i < numberOfPlatforms; i++)
	{
		ground.emplace_back(stageScrollSpeed, groundTexture);
	}

	// Variables to determine the spawn location of each platform
	int spawnLocationX = this->backgroundSprite.getGlobalBounds().left + 450;
	int spawnLocationY = 850;

	// Now, set up each platform with its spawn location
	for (int i = 0; i < numberOfPlatforms; i++)
	{
		// Calculate the spawn location for the current platform
		sf::Vector2f spawnLocation = sf::Vector2f(spawnLocationX, spawnLocationY);

		// Set up the current platform
		ground[i].SetupPlatforms(spawnLocation);

		spawnLocationX += 400; // Increase X to create a gap between platforms horizontally
		spawnLocationY -= 50;  // Optional: Adjust Y if you want the platforms to have different heights
	}
}

void BlueStage::SpawnBaseGround()
{
	int spawnLocationXLeft = this->backgroundSprite.getGlobalBounds().left;
	int spawnLocationYLeft = 900;
	int spawnLocationXRight = this->backgroundSprite.getGlobalBounds().left + this->backgroundSprite.getGlobalBounds().width - 250;
	int spawnLocationYRight = 900;

	Ground groundLeft(stageScrollSpeed, groundTexture);
	Ground groundRight(stageScrollSpeed, groundTexture);	
	groundLeft.SetupPlatforms(sf::Vector2f(spawnLocationXLeft, spawnLocationYLeft));
	groundLeft.GetSprite().setScale(1.5, 1);
	this->ground.push_back(groundLeft);
	groundRight.SetupPlatforms(sf::Vector2f(spawnLocationXRight, spawnLocationYRight));
	groundRight.GetSprite().setScale(1.5, 1);
	this->ground.push_back(groundRight);

	//std::cout << "Ground size: " << this->ground.size() << std::endl;
	//std::cout << "Ground position: " << this->ground.back().GetSprite().getPosition().x << std::endl;
}
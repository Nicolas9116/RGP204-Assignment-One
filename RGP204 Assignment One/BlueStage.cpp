#include "Stage.hpp"
#include <iostream>
#include "Player.hpp"	

	BlueStage::BlueStage(const int& groundLevel) :
		boots(bootsTexture),
		groundLevel(groundLevel)
	{

=======
		backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Blue.png");
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(1, 1);
		backgroundSprite.setOrigin(backgroundSprite.getGlobalBounds().width / 2, backgroundSprite.getGlobalBounds().height / 2);
		backgroundSprite.sePosition(960, 540);
		
		SpawnPlatforms();
	}

	//void LoadAssets() override;
	void BlueStage::Update(Player& player)
	{
		boots.Update(stageScrollSpeed);
		backgroundSprite.move(stageScrollSpeed, 0);
		CheckForItemPickup(player);
	}
	void BlueStage::Draw(sf::RenderWindow& window, float frame_Time)
	{
		window.draw(backgroundSprite);


		if (!itemPickedUp)
		{
			boots.Draw(window, frame_Time);
		}

	}

	void BlueStage::LoadTextures()
	{		
		bootsTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Items_On_Ground/Boots Item.png");
		backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Boots_Stage_Background.png");
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
		boots.GetBootsSprite().setPosition(this->backgroundSprite.getPosition().x + 250, groundLevel - boots.GetBootsSprite().getGlobalBounds().height);
	}

	void BlueStage::DelayedSetupCall()
	{
		LoadTextures();
		SetupSprites();
		SpawnItem();
	}

	}

	void BlueStage::SpawnPlatforms();
{ 	for(int i; i < numberOfPlatforms; i++)
		{ positions.emplace(positions[i]); }

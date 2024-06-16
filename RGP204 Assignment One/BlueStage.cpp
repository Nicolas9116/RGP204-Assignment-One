#include "Stage.hpp"
#include <iostream>

	BlueStage::BlueStage()
	{
		backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Blue.png");
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(1, 1);
	}

	//void LoadAssets() override;
	void BlueStage::Update(Player& player)
	{
		backgroundSprite.move(stageScrollSpeed, 0);
	}
	void BlueStage::Draw(sf::RenderWindow& window)
	{
		window.draw(backgroundSprite);
	}

	void BlueStage::LoadTextures()
	{
	}

	void BlueStage::SetupSprites()
	{
	}

	void BlueStage::SetupFakeFloor(const int m_groundLevel)
	{

	}

	void BlueStage::CheckForItemPickup(Player& player)
	{

	}

	void BlueStage::IsOffScreen()
	{
		if (backgroundSprite.getPosition().x < -1920)
		{
			isOffScreen = true;
			std::cout << "BLUE STAGE HAS GONE OFF SCREEN" << std::endl;
		}
	}

	std::vector<sf::Sprite>& BlueStage::GetEnemySprites()
	{
		return enemySprites;
	}

	void BlueStage::LoadToBack()
	{
		backgroundSprite.setPosition(3840, 0);
	}

	std::string BlueStage::GetStageType()
	{
		return stageType;
	}

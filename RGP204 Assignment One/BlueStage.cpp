#include "Stage.hpp"
#include <iostream>

	BlueStage::BlueStage()
	{
		backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Blue.png");
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(1, 1);
		backgroundSprite.setOrigin(backgroundSprite.getGlobalBounds().width / 2, backgroundSprite.getGlobalBounds().height / 2);
		backgroundSprite.setPosition(960, 540);
	}

	//void LoadAssets() override;
	void BlueStage::Update(Player& player)
	{
		backgroundSprite.move(-4, 0);
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
	}

	bool BlueStage::GetIsOffScreen()
	{
		return false;
	}

	std::vector<sf::Sprite>& BlueStage::GetEnemySprites()
	{
		return enemySprites;
	}

	void BlueStage::LoadToBack()
	{
		backgroundSprite.setPosition(1920 + 980, 540);
	}

	std::string BlueStage::GetStageType()
	{
		return stageType;
	}

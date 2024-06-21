#include "Stage.hpp"
#include <iostream>
	BlueStage::BlueStage()
	{
		backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Blue.png");
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(1, 1);
		backgroundSprite.setOrigin(backgroundSprite.getGlobalBounds().width / 2, backgroundSprite.getGlobalBounds().height / 2);
		backgroundSprite.setPosition(960, 540);
		
		SpawnPlatforms();
	}

	//void LoadAssets() override;
	void BlueStage::Update()
	{
		backgroundSprite.move(-4, 0);
		std::cout << backgroundSprite.getPosition().x << std::endl;
	}
	void BlueStage::Draw(sf::RenderWindow& window)
	{
		window.draw(backgroundSprite);
	}

	void BlueStage::SpawnPlatforms();
{ 	for(int i; i < numberOfPlatforms; i++)
		{ positions.emplace(positions[i]); }

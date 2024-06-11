#include "Stage.hpp"
#include <iostream>

RedStage::RedStage()
	{
		backgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Red.png");
		backgroundSprite.setTexture(backgroundTexture);
		backgroundSprite.setScale(1, 1);
		backgroundSprite.setOrigin(backgroundSprite.getGlobalBounds().width / 2, backgroundSprite.getGlobalBounds().height / 2);
		backgroundSprite.setPosition(960, 540);
	}

	//void LoadAssets() override;
	void RedStage::Update()
	{
		backgroundSprite.move(-4, 0);
		std::cout << backgroundSprite.getPosition().x << std::endl;
	}

	void RedStage::Draw(sf::RenderWindow& window)
	{
		window.draw(backgroundSprite);
	}


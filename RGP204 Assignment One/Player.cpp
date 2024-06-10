#include "Player.hpp"
#include <iostream>

Player::Player(sf::Texture& playerTex)  : playerSprite(playerTex), equipped(equippedItem::none)	
{
	playerSprite.setOrigin(playerTex.getSize().x / 2, playerTex.getSize().y / 2);
	playerSprite.setPosition(500, 500);
	playerSprite.setScale(.1,.1);
}

void Player::DoOneButtonAction()
{
	if(equipped == equippedItem::none)
	{
		std::cout << "Player has no equipped item" << std::endl;
	}
	else if(equipped == equippedItem::sword)
	{
		std::cout << "Player swings sword" << std::endl;
	}
	else if(equipped == equippedItem::shield)
	{
		std::cout << "Player raises shield" << std::endl;
	}
	else if(equipped == equippedItem::bow)
	{
		std::cout << "Player draws bow" << std::endl;
	}
	else if(equipped == equippedItem::arrow)
	{
		std::cout << "Player nocks arrow" << std::endl;
	}
}



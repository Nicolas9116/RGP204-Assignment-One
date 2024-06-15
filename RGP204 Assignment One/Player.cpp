#include "Player.hpp"
#include <iostream>
#include "StageManager.hpp"

Player::Player(sf::Texture& playerTex, const int& groundLevel)  : playerSprite(playerTex), equipped(equippedItem::none), m_groundLevel(groundLevel)
{	
	playerSprite.setScale(.1, .1);
	playerSprite.setPosition(100, (m_groundLevel - playerSprite.getGlobalBounds().height));

	swordHitBox.setFillColor(sf::Color::Black);
	swordHitBox.setSize(sf::Vector2f(25, 50));
	swordHitBox.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width, playerSprite.getPosition().y + playerSprite.getGlobalBounds().height / 2);

}

void Player::DoOneButtonAction(std::shared_ptr<Stage> currentStage)
{
	if(equipped == equippedItem::none)
	{
		std::cout << "Player has no equipped item" << std::endl;
	}
	else if(equipped == equippedItem::sword)
	{
		if (coolDownTimer.getElapsedTime().asSeconds() > 1.5)
		{
			coolDownTimer.restart();
			CheckSwordCollision(currentStage->GetEnemySprites());
			std::cout << "Player swings sword" << std::endl;
		}
		//change player sprite to sword wielding sprite
		//play sword swinging sound
		//play sword swinging animation
		//check for enemy collision with sword hitbox

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

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite);
	window.draw(swordHitBox);
}

bool Player::isGrounded(int groundlevel)
{
	if(GetPlayerSprite().getPosition().y >= groundlevel - playerSprite.getGlobalBounds().height)
	{
		m_isGrounded = true;
	}
	else
	{
		m_isGrounded = false;
	}

	return m_isGrounded;
}

void Player::UpdatePlayerPosition()
{
	playerVelocity += playerAcceleration;
	playerSprite.move(playerVelocity);
}

void Player::UpdatePlayerAcceleration(sf::Vector2f accelerationToAdd)
{
	playerAcceleration += accelerationToAdd;

}

void Player::UpdatePlayerVelocity(sf::Vector2f velocityToAdd)
{
	playerVelocity += velocityToAdd;
}

void Player::CheckSwordCollision(std::vector<sf::Sprite>& enemysprites)
{
	for(auto& enemy : enemysprites)
	{
		if(swordHitBox.getGlobalBounds().intersects(enemy.getGlobalBounds()))
		{
			std::cout << "Enemy hit" << std::endl;
		}
	}
}



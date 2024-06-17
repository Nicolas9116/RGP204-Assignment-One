#include "Player.hpp"
#include <iostream>
#include "StageManager.hpp"

Player::Player(sf::Texture& playerTex, const int& groundLevel) : playerSprite(playerTex), equipped(equippedItem::none), m_groundLevel(groundLevel)
{
	playerSprite.setTextureRect(sf::IntRect(0, 0, 192, 192));//establish the default rect to avoid the full texture being used in the first frame
	playerSprite.setScale(.5, .8);
	playerSprite.setPosition(100, (m_groundLevel));
	std::cout << m_groundLevel << std::endl;
	std::cout << playerSprite.getGlobalBounds().height << std::endl;
	std::cout << "player position: " << playerSprite.getPosition().x << " " << playerSprite.getPosition().y << std::endl;

	swordHitBox.setFillColor(sf::Color::Black);
	swordHitBox.setSize(sf::Vector2f(50, 75));
	swordHitBox.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width, playerSprite.getPosition().y - playerSprite.getGlobalBounds().height / 2);
}

void Player::DoOneButtonAction(std::shared_ptr<Stage> currentStage)
{
	if (equipped == equippedItem::sword && currentStage->GetStageType() == "Sword Stage")
	{
		if (coolDownTimer.getElapsedTime().asSeconds() > .5)
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
	if (equipped == equippedItem::shield)
	{
		std::cout << "Player raises shield" << std::endl;
	}
	if (equipped == equippedItem::bow)
	{
		std::cout << "Player draws bow" << std::endl;
	}
	if (equipped == equippedItem::arrow)
	{
		std::cout << "Player nocks arrow" << std::endl;
	}
	if (currentStage->GetStageType() == "Blue Stage" && m_isGrounded)
	{
		UpdatePlayerAcceleration(sf::Vector2f(0, -10));
		std::cout << "Player puts on boots" << std::endl;
	}
	if (equipped == equippedItem::none)
	{
		std::cout << "Player has no item equipped" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow& window, sf::IntRect uvrect)
{
	playerSprite.setTextureRect(uvrect);
	window.draw(playerSprite);
	//window.draw(swordHitBox);
}

bool Player::isGrounded(int groundlevel)
{
	if (GetPlayerSprite().getPosition().y >= groundlevel - playerSprite.getGlobalBounds().height)
	{
		m_isGrounded = true;
		playerSprite.setPosition(playerSprite.getPosition().x, groundlevel - playerSprite.getGlobalBounds().height);
	}
	else
	{
		m_isGrounded = false;
	}

	return m_isGrounded;
}

void Player::UpdatePlayerPosition(float m_frame_Time)
{
	playerVelocity += playerAcceleration;
	playerSprite.move(playerVelocity * m_frame_Time);
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
	auto newEnd = std::remove_if(enemysprites.begin(), enemysprites.end(),
		[this](const sf::Sprite& enemy) {
			bool isHit = swordHitBox.getGlobalBounds().intersects(enemy.getGlobalBounds());
			if (isHit) {
				std::cout << "Enemy hit" << std::endl;
			}
			return isHit; // Remove the sprite if it intersects with the sword hitbox
		});

	enemysprites.erase(newEnd, enemysprites.end()); // Erase the removed elements
}

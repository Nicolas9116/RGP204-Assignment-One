#include "Player.hpp"
#include <iostream>
#include "StageManager.hpp"
#include "Orc.hpp"

Player::Player(sf::Texture& playerTex, sf::Texture& playerAttackTex,sf::Texture& playerJumpTex, const int& groundLevel) : playerSprite(playerTex), equipped(equippedItem::none), m_groundLevel(groundLevel), playerAnimation(&playerTex, sf::Vector2u(6, 9), 0.08f), animationRow(0), playerAnimationAttack(&playerAttackTex, sf::Vector2u(4, 1), .08f), playerJumpAnimation(&playerJumpTex, sf::Vector2u(6, 1), .08f)
{	
	playerSprite.setTextureRect(sf::IntRect(0, 0, 192, 192));//establish the default rect to avoid the full texture being used in the first frame
	playerSprite.setScale(.8, .8);
	playerSprite.setPosition(100, (m_groundLevel));

	swordHitBox.setFillColor(sf::Color::Black);
	swordHitBox.setSize(sf::Vector2f(50, 75));
	swordHitBox.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width, playerSprite.getPosition().y - playerSprite.getGlobalBounds().height / 2);
	
	playerAnimationAttack.SetOneTimeLoop(true);
}

void Player::DoOneButtonAction(std::shared_ptr<Stage>& currentStage)
{
	if (equipped == equippedItem::sword && currentStage->GetStageType() == "Sword Stage")
	{
		if (coolDownTimer.getElapsedTime().asSeconds() > .5)
		{
			coolDownTimer.restart();
			CheckSwordCollision(currentStage->GetEnemiesVector());
			std::cout << "Player swings sword" << std::endl;
			m_isAttacking = true;
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
		m_isGrounded = false;	
		UpdatePlayerAcceleration(sf::Vector2f(0, -10));
		std::cout << "Player puts on boots" << std::endl;
	}
	if (equipped == equippedItem::none)
	{
		std::cout << "Player has no item equipped" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow& window, float frame_Time)
{
	std::cout << "Grounded: " << m_isGrounded << ", Attacking: " << m_isAttacking << ", Animation Row: " << animationRow << std::endl;

	// First, determine the player's current state and set the appropriate animation row
	if (!m_isGrounded)
	{
		animationRow = 0; // Assuming this is the jump animation row
	}
	else if (m_isAttacking)
	{
		animationRow = 0; // Assuming this is the attack animation row
	}
	else if (equipped == equippedItem::none)
	{
		animationRow = 0; // Default animation row
	}
	else if (equipped == equippedItem::sword)
	{
		animationRow = 1; // Sword equipped animation row
	}
	else if (equipped == equippedItem::boots)
	{
		animationRow = 2; // Boots equipped animation row
	}

	// Then, based on the current state, update and draw the appropriate animation
	if (!m_isGrounded)
	{
		// Jumping state
		playerSprite.setTexture(*playerJumpAnimation.GetTexture());
		playerJumpAnimation.Update(animationRow, frame_Time);
		playerSprite.setTextureRect(playerJumpAnimation.GetUVRect());
	}
	else if (m_isAttacking)
	{
		// Attacking state
		playerSprite.setTexture(*playerAnimationAttack.GetTexture());
		playerAnimationAttack.Update(animationRow, frame_Time);
		playerSprite.setTextureRect(playerAnimationAttack.GetUVRect());
	}
	else
	{
		// Default state (running, idle, etc.)
		playerSprite.setTexture(*playerAnimation.GetTexture());
		playerAnimation.Update(animationRow, frame_Time);
		playerSprite.setTextureRect(playerAnimation.GetUVRect());
	}

	// Finally, draw the player sprite in its current state
	window.draw(playerSprite);

	// Reset the attacking state if the cooldown has elapsed
	if (coolDownTimer.getElapsedTime().asSeconds() > .3)
	{
		m_isAttacking = false;
		playerAnimationAttack.ResetCurrentFrame();
	}
}


bool Player::isGrounded(int groundlevel)
{
	if (GetPlayerSprite().getPosition().y >= groundlevel - playerSprite.getGlobalBounds().height)
	{
		m_isGrounded = true;
		playerSprite.setPosition(playerSprite.getPosition().x, groundlevel - playerSprite.getGlobalBounds().height);
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

void Player::EquipItem(equippedItem item)
{
	equipped = item;
}

void Player::CheckSwordCollision(std::vector<Orc>& Orcs)
{
	for (auto& Orc : Orcs)
	{
		if (swordHitBox.getGlobalBounds().intersects(Orc.GetOrcSprite().getGlobalBounds()))
		{
			Orc.SetIsDead(true);
			std::cout<< "enemy is dead" << std::endl;
		}
	}
}

void Player::SetIsDead(bool isDead)
{
	this->isDead = isDead;
}

void CheckForGround(std::shared_ptr<Stage>& currentStage)
{
	if (currentStage->GetStageType() == "Boots Stage")
		{
			auto platforms = currentStage->GetPlatforms();
			for (int i; i< platforms.size(); i++
				if ({playerSprite.GetGlobalBounds().intersects(platforms[i].getGlobalBounds()))
				{	playerSprite.setPosition.y(platforms[i].getposition().y - playerSprite.GetGlobalBounds().height)	}
	player.m_isGrounded = true; //Need to check if the x or the y length of the intersecting rectange are bigger to see if should fall or should be on top
		}
}

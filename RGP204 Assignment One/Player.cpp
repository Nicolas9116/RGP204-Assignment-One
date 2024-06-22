#include "Player.hpp"
#include <iostream>
#include "StageManager.hpp"
#include "Orc.hpp"
#include "Ground.hpp"

Player::Player(sf::Texture& playerTex, sf::Texture& playerAttackTex, sf::Texture& playerJumpTex, const int& groundLevel) : playerSprite(playerTex), equipped(equippedItem::none), groundLevel(groundLevel), playerAnimation(&playerTex, sf::Vector2u(6, 9), 0.08f), animationRow(0), playerAnimationAttack(&playerAttackTex, sf::Vector2u(4, 1), .08f), playerJumpAnimation(&playerJumpTex, sf::Vector2u(6, 1), .08f), isDead(false)	
{
	playerSprite.setTextureRect(sf::IntRect(0, 0, 192, 192));//establish the default rect to avoid the full texture being used in the first frame
	playerSprite.setScale(.8, .8);
	playerSprite.setPosition(100, (900));

	swordHitBox.setFillColor(sf::Color::Black);
	swordHitBox.setSize(sf::Vector2f(50, 75));
	swordHitBox.setPosition(playerSprite.getPosition().x + playerSprite.getGlobalBounds().width, playerSprite.getPosition().y - playerSprite.getGlobalBounds().height / 2);

	playerAnimationAttack.SetOneTimeLoop(true);
}

void Player::Update(Player& player, sf::Vector2f& gravity, float& deltaTime, StageManager& stageManager)
{
	UpdateAcceleration(gravity);
	//accel will also have jump added to accel but this happens in the player class
	UpdateVelocity(GetplayerAcceleration());
	ResetAcceleration();
	UpdatePosition(GetplayerVelocity(), deltaTime);

	CheckForGround(stageManager);
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
	if (equipped == equippedItem::boots && playerIsGrounded)
	{
		playerIsGrounded = false;
		UpdateAcceleration(sf::Vector2f(0, -1 * jumpForce));
		std::cout << "Player puts on boots" << std::endl;
	}
	if (equipped == equippedItem::none)
	{
		std::cout << "Player has no item equipped" << std::endl;
	}
}

void Player::Draw(sf::RenderWindow& window, float frame_Time)
{

	// First, determine the player's current state and set the appropriate animation row
	if (!playerIsGrounded)
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
	if (!playerIsGrounded)
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

void Player::UpdateAcceleration(sf::Vector2f acceleration)
{
	playerAcceleration += acceleration;

}

void Player::UpdateVelocity(sf::Vector2f velocityToAdd)
{
	playerVelocity += playerAcceleration;
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
			std::cout << "enemy is dead" << std::endl;
		}
	}
}

void Player::SetIsDead(bool isDead)
{
	this->isDead = isDead;
}

void Player::UpdatePosition(sf::Vector2f& velocity, float& deltaTime)
{
	playerSprite.move(velocity * deltaTime);
}

void Player::CheckForGround(StageManager& stageManager)
{
	std::cout << playerIsGrounded << std::endl;	
	std::cout << GetPlayerSprite().getPosition().x << " , "<< GetPlayerSprite().getPosition().y << std::endl;
	auto& allStages = stageManager.GetAllStages();

	for (auto& stage : allStages)
	{
		auto& ground = stage->GetGround();

		for (int i = 0; i < ground.size(); i++)
		{
			auto groundBounds = ground[i].GetSprite().getGlobalBounds();


			auto groundSpritePos = ground[i].GetSprite().getPosition();
			if (playerSprite.getGlobalBounds().intersects(groundBounds))
			{
				std::cout << "Collision with ground detected" << std::endl;
				playerVelocity.y = 0;
				playerSprite.setPosition(playerSprite.getPosition().x, groundSpritePos.y - playerSprite.getGlobalBounds().height);
				playerIsGrounded = true;
			}
		}
	}
}





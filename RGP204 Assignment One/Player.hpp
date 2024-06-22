#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"
#include "StageManager.hpp"

class Stage;
class Orc;

enum class equippedItem
{
	none,
	sword,
	shield,
	bow,
	boots,
	arrow
};

class Player
{
public:
	Player(sf::Texture& playerTex, sf::Texture& playerAttackTex, sf::Texture& playerJumpTex, const int& groundLevel);
	void Update(Player& player, sf::Vector2f& gravity, float& deltaTime, StageManager& stageManager);
	const sf::Sprite& GetPlayerSprite() const { return playerSprite; }
	void DoOneButtonAction(std::shared_ptr<Stage>& currentStage);
	void Draw(sf::RenderWindow& window, float frame_Time);

	void EquipItem(equippedItem item);
	void CheckSwordCollision(std::vector<Orc>& Orcs);

	void SetIsDead(bool isDead);
	bool isDeadCheck() { return isDead; }

	Animation playerAnimation;
	Animation playerAnimationAttack;
	Animation playerJumpAnimation;

	//NEW FROM HERE DOWN

	void UpdateAcceleration(sf::Vector2f acceleration);
	void ResetAcceleration() { playerAcceleration = sf::Vector2f(0, 0); }
	void UpdateVelocity(sf::Vector2f acceleration);
	void UpdatePosition(sf::Vector2f& velocity, float& deltaTime);

	void CheckForGround(StageManager& stageManager);

	void Jump() { playerAcceleration.y = -1 * jumpForce; playerIsGrounded = false; }

	bool& isGrounded() { return playerIsGrounded; }

	sf::Vector2f& GetplayerPosition() { return playerPosition; }
	sf::Vector2f& GetplayerVelocity() { return playerVelocity; }
	sf::Vector2f& GetplayerAcceleration() { return playerAcceleration; }

	bool isDead = false;
private:

	sf::Clock coolDownTimer;

	sf::Sprite playerSprite;

	equippedItem equipped;

	sf::RectangleShape swordHitBox;

	sf::Vector2f playerAcceleration;
	sf::Vector2f playerVelocity;
	sf::Vector2f playerPosition;

	int groundLevel;
	int animationRow;
	int jumpForce = 350;
	bool playerIsGrounded = false;
	bool m_isAttacking;
};


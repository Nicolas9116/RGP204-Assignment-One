#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

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
	const sf::Sprite& GetPlayerSprite() const { return playerSprite; }
	void DoOneButtonAction(std::shared_ptr<Stage>& currentStage);
	void Draw(sf::RenderWindow& window, float frame_Time);
	bool isGrounded(int groundLevel);
	void UpdatePlayerPosition(float m_frame_Time);
	void UpdatePlayerAcceleration(sf::Vector2f accelerationToAdd);
	void UpdatePlayerVelocity(sf::Vector2f velocityToAdd);

	void ResetPlayerAcceleration() { playerAcceleration = sf::Vector2f(0, 0); }
	void ResetPlayerVelocity() { playerVelocity = sf::Vector2f(0, 0); }

	void EquipItem(equippedItem item);
	void CheckSwordCollision(std::vector<Orc>& Orcs);

	void SetIsDead(bool isDead);
	bool isDeadCheck() { return isDead; }

	sf::Vector2f GetPlayerAcceleration() { return playerAcceleration; }	
	Animation playerAnimation;
	Animation playerAnimationAttack;
	Animation playerJumpAnimation;
private:
	int animationRow;
	sf::Clock coolDownTimer;
	sf::Sprite playerSprite;
	equippedItem equipped;
	sf::RectangleShape swordHitBox;
	int m_groundLevel;
	bool m_isGrounded;
	bool m_isAttacking;
	sf::Vector2f playerVelocity;
	sf::Vector2f playerAcceleration;
	bool isDead = false;

};


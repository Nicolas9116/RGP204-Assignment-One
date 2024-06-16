#pragma once
#include <SFML/Graphics.hpp>

class Stage;

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
	Player(sf::Texture& playerTex, const int& groundLevel);
	const sf::Sprite& GetPlayerSprite() const { return playerSprite; }
	void DoOneButtonAction(std::shared_ptr<Stage> currentStage);
	void Draw(sf::RenderWindow& window);
	bool isGrounded(int groundLevel);
	void UpdatePlayerPosition(float m_frame_Time);
	void UpdatePlayerAcceleration(sf::Vector2f accelerationToAdd);
	void UpdatePlayerVelocity(sf::Vector2f velocityToAdd);

	void ResetPlayerAcceleration() { playerAcceleration = sf::Vector2f(0, 0); }
	void ResetPlayerVelocity() { playerVelocity = sf::Vector2f(0, 0); }

	void EquipItem(equippedItem item) { equipped = item; }
	void CheckSwordCollision(std::vector<sf::Sprite>& enemysprites);

	sf::Vector2f GetPlayerAcceleration() { return playerAcceleration; }	

private:
	sf::Clock coolDownTimer;
	sf::Sprite playerSprite;
	equippedItem equipped;
	sf::RectangleShape swordHitBox;
	int m_groundLevel;
	bool m_isGrounded;
	sf::Vector2f playerVelocity;
	sf::Vector2f playerAcceleration;
};


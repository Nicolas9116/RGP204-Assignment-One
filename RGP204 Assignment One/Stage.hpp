// Stage.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Player;

class Stage {
public:
	//virtual void LoadAssets() = 0; // Load the assets for the stage
	virtual void Update(Player& player) = 0; // Update the stage
	virtual void Draw(sf::RenderWindow& window) = 0; // Draw the stage
	virtual sf::Sprite& GetSprite() = 0;
	virtual void LoadTextures() = 0;
	virtual void SetupSprites() = 0;
	virtual void SetupFakeFloor(const int m_groundLevel) = 0;
	virtual void CheckForItemPickup(Player& player) = 0;
	virtual void IsOffScreen() = 0;
	virtual bool GetIsOffScreen() = 0;
	virtual std::vector<sf::Sprite>& GetEnemySprites() = 0;
	virtual void LoadToBack() = 0;
	virtual std::string GetStageType() = 0;
private:

};

class BlueStage : public Stage {
public:
	BlueStage();

	//void LoadAssets() override;
	void Update(Player& player) override;
	void Draw(sf::RenderWindow& window) override;
	sf::Sprite& GetSprite() { return backgroundSprite; }
	void LoadTextures() override;
	void SetupSprites() override;
	void SetupFakeFloor(const int m_groundLevel);
	void CheckForItemPickup(Player& player);
	void IsOffScreen() override;
	virtual bool GetIsOffScreen() override;
	virtual std::vector<sf::Sprite>& GetEnemySprites() override;
	virtual void LoadToBack() override;
	std::string GetStageType() override;
private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	std::vector<sf::Sprite> enemySprites;
	std::string stageType = "Sword Stage";
};

class RedStage : public Stage {
public:
	RedStage(const int& groundLevel);

	//void LoadAssets() override;
	void Update(Player& player) override;
	void Draw(sf::RenderWindow& window) override;
	sf::Sprite& GetSprite() { return backgroundSprite; }
	void LoadTextures() override;
	void SetupSprites() override;
	void SetupFakeFloor(const int m_groundLevel);
	void CheckForItemPickup(Player& player);
	void SpawnEnemy();
	void IsOffScreen() override;
	bool GetIsOffScreen() override { return isOffScreen; }
	std::vector<sf::Sprite>& GetEnemySprites() { return enemySprites; }
	virtual void LoadToBack() override;
	std::string GetStageType() override;

private:
	sf::Clock spawnClock;

	std::vector<sf::Sprite> backgroundSprites;
	std::vector<sf::Sprite> enemySprites;

	sf::Texture backgroundTexture;
	sf::Texture stageItemTexture;

	sf::Texture enemyTexture;

	sf::Sprite backgroundSprite;
	sf::Sprite stageItemSprite;

	sf::Sprite enemySprite;

	sf::RectangleShape fakeFloor;

	const int m_groundLevel;
	int stageScrollSpeed = -4;

	bool itemPickedUp = false;
	bool isOffScreen;

	std::string stageType = "Sword Stage";
};
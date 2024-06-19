// Stage.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Animation.hpp"
#include "Orc.hpp"
#include "Item.hpp"

class Player;


class Stage {
public:
	//virtual void LoadAssets() = 0; // Load the assets for the stage
	virtual void Update(Player& player) = 0; // Update the stage
	virtual void Draw(sf::RenderWindow& window, float frame_Time) = 0; // Draw the stage
	virtual sf::Sprite& GetSprite() = 0;
	virtual void LoadTextures() = 0;
	virtual void SetupSprites() = 0;
	virtual void SetupFakeFloor(const int m_groundLevel) = 0;
	virtual void CheckForItemPickup(Player& player) = 0;
	virtual void IsOffScreen() = 0;
	virtual bool GetIsOffScreen() = 0;
	virtual void LoadToBack() = 0;
	virtual std::string GetStageType() = 0;
	virtual std::vector<Orc>& GetEnemiesVector() = 0;
	virtual void SpawnItem() = 0;
	virtual void DelayedSetupCall() = 0;
private:

};

class BlueStage : public Stage {
public:
	BlueStage(const int& groundLevel);

	//void LoadAssets() override;
	void Update(Player& player) override;
	void Draw(sf::RenderWindow& window, float frame_Time) override;
	sf::Sprite& GetSprite() { return backgroundSprite; }
	void LoadTextures() override;
	void SetupSprites() override;
	void SetupFakeFloor(const int m_groundLevel);
	void CheckForItemPickup(Player& player);
	void IsOffScreen() override;
	bool GetIsOffScreen() override { return isOffScreen; }
	virtual void LoadToBack() override;
	std::string GetStageType() override;
	std::vector<Orc>& GetEnemiesVector() override { return enemies; }
	void SpawnItem() override;
	virtual void DelayedSetupCall() override;
private:
	std::vector<Orc> enemies;
	sf::Texture backgroundTexture;
	sf::Texture bootsTexture;

	sf::Sprite backgroundSprite;
	std::vector<sf::Sprite> enemySprites;
	std::string stageType = "Blue Stage";
	bool itemPickedUp = false;	
	bool isOffScreen = false;
	int stageScrollSpeed = -4;
	const int groundLevel;
	Boots boots;
};

class RedStage : public Stage {
public:
	RedStage(const int& groundLevel);

	//void LoadAssets() override;
	void Update(Player& player) override;
	void Draw(sf::RenderWindow& window, float frame_Time) override;
	sf::Sprite& GetSprite() { return backgroundSprite; }
	void LoadTextures() override;
	void SetupSprites() override;
	void SetupFakeFloor(const int m_groundLevel);
	void CheckForItemPickup(Player& player);
	void SpawnEnemy();
	void IsOffScreen() override;
	bool GetIsOffScreen() override { return isOffScreen; }
	std::vector<Orc>& GetEnemiesVector() override { return *enemies; }
	virtual void LoadToBack() override;
	std::string GetStageType() override;
	void SpawnItem() override;
	virtual void DelayedSetupCall() override;

private:
	

	sf::Clock spawnClock;

	std::vector<sf::Sprite> backgroundSprites;
	std::vector<Orc>* enemies;

	sf::Texture orcDeathTexture;
	sf::Texture orcTexture;
	sf::Texture backgroundTexture;
	sf::Texture stageItemTexture;

	sf::Sprite backgroundSprite;
	sf::Sprite stageItemSprite;

	sf::RectangleShape fakeFloor;

	Sword sword;

	int numberOfEnemies;

	const int m_groundLevel;
	int stageScrollSpeed = -4;

	bool itemPickedUp = false;
	bool isOffScreen = false;

	std::string stageType = "Sword Stage";
};
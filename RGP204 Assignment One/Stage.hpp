// Stage.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Stage {
public:
	//virtual void LoadAssets() = 0; // Load the assets for the stage
	virtual void Update() = 0; // Update the stage
	virtual void Draw(sf::RenderWindow& window) = 0; // Draw the stage
	virtual sf::Sprite& GetSprite() = 0;

private:
};

class BlueStage : public Stage {
public:
	BlueStage();

	//void LoadAssets() override;
	void Update() override;
	void Draw(sf::RenderWindow& window) override;
	sf::Sprite& GetSprite() { return backgroundSprite; }

private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};

class RedStage : public Stage {
public:
	RedStage();

	//void LoadAssets() override;
	void Update() override;
	void Draw(sf::RenderWindow& window) override;
	sf::Sprite& GetSprite() { return backgroundSprite; }

private:
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
};
#pragma once
#include <SFML/Graphics.hpp>

class Animation
{

public:	
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void Update(int row, float deltaTime);
	void Recalculate();
	sf::IntRect& GetUVRect() { return uvRect; }
	sf::Texture* GetTexture() { return texture; }
	void SetOneTimeLoop(bool loop) { OneTimeLoop = loop; }
	void ResetCurrentFrame() { currentFrame = sf::Vector2u(0, 0); }
	void SetTexture(sf::Texture* texture) { this->texture = texture; }	
private:
	bool OneTimeLoop = false;

	float totalTime;
	float switchTime;

	int spriteWidth;
	int spriteHeight;

	sf::Texture* texture;

	sf::Vector2u animationLength;
	sf::Vector2u currentFrame;

	sf::IntRect uvRect;
};

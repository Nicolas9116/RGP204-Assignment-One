#pragma once
#include <SFML/Graphics.hpp>

class Animation
{

public:	
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	void Update(int row, float deltaTime);
	sf::IntRect& GetUVRect() { return uvRect; }

private:
	float totalTime;
	float switchTime;

	int spriteWidth;
	int spriteHeight;

	sf::Vector2u animationLength;
	sf::Vector2u currentFrame;

	sf::IntRect uvRect;
};

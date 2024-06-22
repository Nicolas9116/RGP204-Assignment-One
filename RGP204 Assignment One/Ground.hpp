#pragma once
#include <SFML/Graphics.hpp>

class Ground
{
public:

	Ground(int& stageScrollSpeed);

	void LoadTextures();
	void SetupSprite(sf::Vector2f position);
	void GroundUpdate(float frame_Time);
	void Draw(sf::RenderWindow& window);
	void SetupPlatforms(sf::Vector2f& position);
	sf::Sprite& GetSprite() { return groundSprite; }


private:

	int stageScrollSpeed;
	sf::Texture groundTex;
	sf::Sprite groundSprite;
};
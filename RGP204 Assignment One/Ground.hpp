#pragma once
#include <SFML/Graphics.hpp>

class Ground
{
public:

	Ground(sf::Vector2f position, int stageScrollSpeed);

	void LoadTextures();
	void SetupSprite(sf::Vector2f position);
	void GroundUpdate(float frame_Time);
	void Draw(sf::RenderWindow window);


private:
	int stageScrollSpeed;
	sf::Texture groundTex;
	sf::Sprite groundSprite;
}
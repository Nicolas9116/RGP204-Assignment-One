#include "Ground.hpp"
#include <iostream>

Ground::Ground(int& stageScrollSpeed, sf::Texture& groundTexture) : stageScrollSpeed(stageScrollSpeed), groundTex(groundTexture)
{
}

void Ground::SetupSprite(sf::Vector2f position, sf::Texture& groundTex)
{
    groundSprite.setTexture(groundTex);
    groundSprite.setPosition(position);
}

void Ground::GroundUpdate(float frame_Time)
{
    groundSprite.move(stageScrollSpeed, 0);
}

void Ground::Draw(sf::RenderWindow& window)
{
    window.draw(groundSprite);
}

void Ground::SetupPlatforms(sf::Vector2f position)
{
    SetupSprite(position, groundTex);
}
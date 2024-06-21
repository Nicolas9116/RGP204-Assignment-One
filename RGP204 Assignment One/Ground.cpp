#include "Ground.hpp"

Ground::Ground(sf::Vector2f position, int stageScrollSpeed) : stageScrollSpeed(stageScrollSpeed)
{
    LoadTextures();
    SetupSprite(position);
}

void Ground::LoadTextures()
{
    groundTex.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Jumping Block.png");
}

void Ground::SetupSprite(sf::Vector2f position)
{
    groundSprite.setTexture(groundTex);
    groundSprite.setPosition(position);
}

void Ground::GroundUpdate(float frame_Time)
{
    groundSprite.move(stageScrollSpeed, 0);
}

void Ground::Draw(sf::RenderWindow window)
{
    window.draw(groundSprite);
}
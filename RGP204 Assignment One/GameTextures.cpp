#include "GameTextures.hpp"

GameTextures::GameTextures()
{
	playerTex.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Textures/player.png");
	textureMap.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Sprite_Map.png");
	playerSpriteMap.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Sprite Atlas.png");
	playerAttackTex.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Player Attack.png");
	playerJumpTex.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Jump Tex Two.png");
}

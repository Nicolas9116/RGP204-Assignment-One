#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.hpp"	

class Menu
{
public:
	Menu(sf::RenderWindow& window);

	void LoadTextures();
	void ShowMenu();
	void SetupSprites();
	void UpdateCursor();
	void UpdateMenuKnight(float frame_Time);
	void UpdateMenuOrc(float frame_Time);
	void SetupText();
	void isPlayTime() { playTime = true; }
	bool getPlayTime() { return playTime; }

private:
	Animation playerMenuAnimation;
	Animation orcMenuAnimation;

	sf::Texture menuOrcTexture;
	sf::Sprite menuOrcSprite;	

	sf::Texture playerMenuAnimationTexture;
	sf::Sprite playerMenuAnimationSprite;

	sf::Texture swordCursor;
	sf::Sprite swordCursorSprite;

	sf::Texture menuBackgroundTexture;
	sf::Sprite menuBackgroundSprite;

	sf::Texture menuPlayButtonTexture;
	sf::Sprite menuPlayButtonSprite;

	sf::Texture exitButtonTexture;
	sf::Sprite exitButtonSprite;

	sf::Font font;
	sf::Text text;

	sf::RenderWindow& window;


	bool playTime = false;
};



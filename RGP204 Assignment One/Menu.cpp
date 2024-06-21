#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Menu::Menu(sf::RenderWindow& window) :window(window), playerMenuAnimation(&playerMenuAnimationTexture, sf::Vector2u(6, 1), .08f), orcMenuAnimation(&menuOrcTexture, sf::Vector2u(6, 1), .08f)
{
	LoadTextures();
	SetupSprites();
	SetupText();
}

void Menu::ShowMenu()
{
	sf::Clock frameClock;
	
	while (!getPlayTime())
	{
		
	float m_frame_Time = frameClock.restart().asSeconds();

		window.setMouseCursorVisible(false);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) // Check if the left button was pressed
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (menuPlayButtonSprite.getGlobalBounds().contains(mousePosF))
					{
						std::cout << "Play Button Pressed" << std::endl;
						isPlayTime();
					}
				}
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) // Check if the left button was pressed
				{
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
					if (exitButtonSprite.getGlobalBounds().contains(mousePosF))
					{
						std::cout << "Exit Button Pressed" << std::endl;
						window.close();
					}
				}
			}
		}

		UpdateCursor();

		UpdateMenuOrc(m_frame_Time);
		UpdateMenuKnight(m_frame_Time);

		window.clear();

		window.draw(menuBackgroundSprite);
		window.draw(menuPlayButtonSprite);
		window.draw(exitButtonSprite);

		window.draw(playerMenuAnimationSprite);
		window.draw(menuOrcSprite);

		window.draw(swordCursorSprite);
		window.display();
	}
}

void Menu::LoadTextures()
{
	menuOrcTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Menu Button/Menu Orc.png");
	playerMenuAnimationTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Menu Button/Menu Knight.png");
	menuBackgroundTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/MenuBackground.png");
	menuPlayButtonTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Play.png");
	exitButtonTexture.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Backgrounds/Exit.png");
	swordCursor.loadFromFile("C:/Users/vampi/source/repos/RGP204 Assignment One/Assets/Menu Button/Sword Cursor.png");

	playerMenuAnimation.SetTexture(&playerMenuAnimationTexture);
	playerMenuAnimation.Recalculate();

	orcMenuAnimation.SetTexture(&menuOrcTexture);
	orcMenuAnimation.Recalculate();
}

void Menu::SetupSprites()
{	
	menuOrcSprite.setTexture(*orcMenuAnimation.GetTexture());
	menuOrcSprite.setScale(2, 2);
	menuOrcSprite.setPosition(1270, 340);

	playerMenuAnimationSprite.setTexture(*playerMenuAnimation.GetTexture());
	playerMenuAnimationSprite.setScale(2, 2);
	playerMenuAnimationSprite.setPosition(250, 340);	

	swordCursorSprite.setTexture(swordCursor);
	swordCursorSprite.setScale(2, 2);

	menuBackgroundSprite.setTexture(menuBackgroundTexture);
	menuBackgroundSprite.setScale(10, 10);

	menuPlayButtonSprite.setTexture(menuPlayButtonTexture);
	menuPlayButtonSprite.setOrigin(menuPlayButtonSprite.getGlobalBounds().width / 2, menuPlayButtonSprite.getGlobalBounds().height / 2);
	menuPlayButtonSprite.setScale(10,10);
	menuPlayButtonSprite.setPosition(960, 440);

	exitButtonSprite.setTexture(exitButtonTexture);
	exitButtonSprite.setOrigin(exitButtonSprite.getGlobalBounds().width / 2, exitButtonSprite.getGlobalBounds().height / 2);
	exitButtonSprite.setScale(10,10);
	exitButtonSprite.setPosition(960, 640);
}

void Menu::UpdateCursor()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	swordCursorSprite.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}

void Menu::UpdateMenuKnight(float frame_Time)
{
	playerMenuAnimation.Update(0, frame_Time);
	playerMenuAnimationSprite.setTextureRect(playerMenuAnimation.GetUVRect());
}

void Menu::UpdateMenuOrc(float frame_Time)
{
	orcMenuAnimation.Update(0, frame_Time);
	menuOrcSprite.setTextureRect(orcMenuAnimation.GetUVRect());
}

void Menu::SetupText() 
{

}

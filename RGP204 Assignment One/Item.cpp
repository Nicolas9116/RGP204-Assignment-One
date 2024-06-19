#include "Item.hpp"
#include <iostream>
//SWORD//

void Sword::Update(int scrollSpeed)
{
    GetSwordSprite().move(scrollSpeed, 0);
}

void Sword::Draw(sf::RenderWindow& window, float frame_Time)
{
    // Update the animation based on the frame time
    itemAnimator.Update(0, frame_Time);

    // Apply the current frame's texture rectangle to the sword sprite
    swordSprite.setTextureRect(itemAnimator.GetUVRect());

    std::cout << swordSprite.getTextureRect().left << std::endl;

    // Draw the sword sprite to the window
    window.draw(swordSprite);
}


//BOOTS//

void Boots::Update(int scrollSpeed)
{
    GetBootsSprite().move(scrollSpeed, 0);
}

void Boots::Draw(sf::RenderWindow& window, float frame_Time)
{
    // Update the animation based on the frame time
    itemAnimator.Update(0, frame_Time);

    // Apply the current frame's texture rectangle to the sword sprite
    bootsSprite.setTextureRect(itemAnimator.GetUVRect());

    std::cout << bootsSprite.getTextureRect().left << std::endl;

    // Draw the sword sprite to the window
    window.draw(bootsSprite);
}

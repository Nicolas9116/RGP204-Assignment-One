#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.hpp"

class Item {
public:
    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Item() {}
    virtual void Draw(sf::RenderWindow& window, float frame_Time) = 0;
    virtual void Update(int scrollSpeed) = 0;
protected:
    // Protected constructor that takes animation parameters
    Item(sf::Texture& itemTex, sf::Vector2u imageCount, float switchTime)
        : itemAnimator(&itemTex, imageCount, switchTime) {}

    Animation itemAnimator;
};

class Sword : public Item {
public:
    // Sword constructor passes its specific animation parameters to the Item constructor
    Sword(sf::Texture& itemTex)
        : Item(itemTex, sf::Vector2u(7, 1), 0.08f) {}
    void Update(int scrollSpeed) override; 
    void Draw(sf::RenderWindow& window, float frame_Time) override;
    sf::Sprite& GetSwordSprite() { return swordSprite; }
private:
    sf::Sprite swordSprite;
};

class Boots : public Item {
public:
    // Sword constructor passes its specific animation parameters to the Item constructor
    Boots(sf::Texture& itemTex)
        : Item(itemTex, sf::Vector2u(6, 1), 0.08f) {}
    void Update(int scrollSpeed) override;
    void Draw(sf::RenderWindow& window, float frame_Time) override;
    sf::Sprite& GetBootsSprite() { return bootsSprite; }
private:
    sf::Sprite bootsSprite;
};

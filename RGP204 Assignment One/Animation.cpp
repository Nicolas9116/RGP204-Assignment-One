#include "Animation.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->animationLength = imageCount;//number of frames in the animation
	this->switchTime = switchTime;//time between each frame
	totalTime = 0.0f;//start at the beginning of the animation
	currentFrame.x = 0;//start at the first frame

	uvRect.width = texture->getSize().x / float(imageCount.x);//width of each frame
	std::cout << "Width: " << uvRect.width << std::endl;
	uvRect.height = texture->getSize().y / float(imageCount.y);//height of each frame
	std::cout << "Height: " << uvRect.height << std::endl;
}

void Animation::Update(int row, float deltaTime)
{
	currentFrame.y = row;//set the row of the animation

	totalTime += deltaTime;//add the time since the last frame to the total time

	if (totalTime >= switchTime)//if the total time is greater than the switch time
	{
		totalTime -= switchTime;//subtract the switch time from the total time
		currentFrame.x++;//move to the next frame

		if (currentFrame.x >= animationLength.x)//if the current frame is greater than the number of frames
		{
			currentFrame.x = 0;//start at the beginning of the animation
		}
	}

	uvRect.left = currentFrame.x * uvRect.width;//set the left of the uvRect to the left of the current frame
	uvRect.top = currentFrame.y * uvRect.height;//set the top of the uvRect to the top of the current frame
}
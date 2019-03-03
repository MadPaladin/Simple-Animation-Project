#include "stdafx.h"
#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	currentImage.x = 0;
	currentImage.y = 0;
	elapsedTime = 0;

	textureRect.width = texture->getSize().x / float(this->imageCount.x);
	textureRect.height = texture->getSize().y / float(this->imageCount.y);
}

void Animation::update(float deltaTime)
{
	elapsedTime += deltaTime;
	if (elapsedTime >= switchTime)
	{
		elapsedTime -= switchTime;
		++currentImage.x;
		if (currentImage.x >= imageCount.x)
		{
			currentImage.x = 0;
		}

	}
	textureRect.left = currentImage.x * textureRect.width;
	textureRect.top = currentImage.y * textureRect.height;
}


Animation::~Animation()
{
}
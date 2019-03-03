#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();

	void update(float deltaTime);

	sf::IntRect textureRect;
private:

	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float elapsedTime;
	float switchTime;

};
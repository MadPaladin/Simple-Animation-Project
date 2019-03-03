#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "animation.h"
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>

#define GRAPHICS_PATH "graphics/"
#define FPS 0.1f


int main()
{

	sf::Clock clock;
	sf::Keyboard keyboard;
	//window
	sf::RenderWindow window(sf::VideoMode (800, 600), "Window animation");
	window.setFramerateLimit(200);
	//shapes
	sf::RectangleShape player(sf::Vector2f(100.f, 150.f));
	sf::RectangleShape background(sf::Vector2f(800.0f, 600.0f));
	//texture
	sf::Texture Tex;
	sf::Texture Tex2;
	//texutre load
	Tex2.loadFromFile(GRAPHICS_PATH "forest.png");
	background.setTexture(&Tex2);

	player.setPosition(600, 400);
	Tex.loadFromFile(GRAPHICS_PATH  "idle.png");
	player.setTexture(&Tex);

	sf::Vector2u textureSize = Tex.getSize();
	//rescale 
	player.setScale(sf::Vector2f(1.9f, 1.8f));
	sf::RectangleShape player2(sf::Vector2f(100.f, 150.f));
	sf::Texture Tex3;

	Tex3.loadFromFile(GRAPHICS_PATH "idle.png");
	player2.setTexture(&Tex3);
	player2.setPosition(100, 400);

	textureSize.x /= 7;
	textureSize.y /= 3;
	
	
	
	float deltaTime = 0.0f;
	player.setTextureRect(sf::IntRect(textureSize.x , textureSize.y ,textureSize.x ,textureSize.y));
	player.setTexture(&Tex);
		
	player2.setTextureRect(sf::IntRect(textureSize.x , textureSize.y , textureSize.x, textureSize.y));
	Animation animation2(&Tex3, sf::Vector2u(1, 1), FPS);

	Animation animation(&Tex, sf::Vector2u(6, 1), FPS);
    
	//kontrole
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player.move(-1, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player.move(0, 1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player.move(1, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player.move(0, -1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player2.move(-1, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player2.move(0, 1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player2.move(1, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player2.move(0, -1);
		}
		//draw stuff
		animation.update(deltaTime);
		player.setTextureRect(animation.textureRect);
		player2.setTextureRect(animation.textureRect);
		window.display();
		window.clear();
		window.draw(background);
		window.draw(player2);
		window.draw(player);
		
	}

	
	system("pause");
	return 0;
}
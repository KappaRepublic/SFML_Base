#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>

#include "GameObject.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void setupWindowBackground();

int main()
{

	// Comment
	int backgroundId = 1;

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML_Base");
	
	GameObject objTest;
	objTest.init(128, 64, "res/textures/tex_shulk.png");

	// Set up the example window image
	sf::Texture tex1, tex2, tex3;
	if (!tex1.loadFromFile("res/textures/tex_background1.png"))
	{
		// Provide error details
	}
	if (!tex2.loadFromFile("res/textures/tex_background2.png"))
	{
		// Provide error details
	}
	if (!tex3.loadFromFile("res/textures/tex_background3.png"))
	{
		// Provide error details
	}

	sf::Sprite spr1, spr2, spr3;
	spr1.setTexture(tex1);
	spr2.setTexture(tex2);
	spr3.setTexture(tex3);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			backgroundId = 1;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			backgroundId = 2;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			backgroundId = 3;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			objTest.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
		}

		window.clear();

		objTest.update(0);
		
		switch (backgroundId)
		{
		case 1:
			window.draw(spr1);
			break;
		case 2:
			window.draw(spr2);
			break;
		case 3:
			window.draw(spr3);
			break;
		default:
			break;
		}
		

		objTest.draw(&window);
		window.display();
	}

	return 0;
}

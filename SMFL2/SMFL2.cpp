#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "./GameObject.h"
#include <stdlib.h>

int main()
{
	// Initialisation de sprite, texture, velocity, acceleration, etc.
	sf::RenderWindow window;

	int _Fw = 1080;
	int _Fh = 720;
	window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
	window.setFramerateLimit(60);
	GameObject Ocircle(0,0,10, sf::Color::Red);
	

	GameObject oRect1(_Fw /2, 100, 50, 50, sf::Color::Red);
	GameObject oRect2(50, 100, 100, 20, sf::Color::Green);


	sf::FloatRect coRect1 = oRect1.Forms->getGlobalBounds();
	sf::FloatRect coRect2 = oRect2.Forms->getGlobalBounds();
	sf::RectangleShape rect;
	std::vector<sf::FloatRect> rectanglesVector;
	rectanglesVector.push_back(coRect1);
	rectanglesVector.push_back(coRect2);

	sf::Vector2f velocity(1.0f, 1.0f);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Ocircle.move(velocity);

		Ocircle.checkCollisionWithBounds(window.getSize(), velocity);
		std::cout << "exte" << velocity.x << ";" << velocity.y << std::endl;
		Ocircle.Forms->move(velocity);
		Ocircle.checkCollisionWithRect(rectanglesVector, velocity);
		
	    window.clear();

		window.draw(*Ocircle.Forms);
	    window.draw(*oRect1.Forms);
		window.draw(*oRect2.Forms);

		window.display();
	}

	return 0;
}
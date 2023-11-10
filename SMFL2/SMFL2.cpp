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
	//circle.getCircleCollider();


	GameObject oRect1(_Fw / 2, 100, 500, 500, sf::Color::Red);
	GameObject oRect2(50, 100, 100, 20, sf::Color::Green);
	//GameObject oRect3(100, 200, 100, 20, sf::Color::Green);
	//GameObject oCircle1(500, 500, 50, sf::Color::Yellow);

	sf::RectangleShape rect;
	std::vector<GameObject> rectanglesVector;
	rectanglesVector.push_back(oRect1);
	rectanglesVector.push_back(oRect2);

	while (window.isOpen())

	{



		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//
		//EVENT

		// si on utilise la fleche vers le haut
		//oRect1.move(0,-1);

		//UPDATE
		//si oRect1.collide(oRect2)
		//on affiche : collision !
		sf::Vector2f velocity(7.0f, 4.0f);
		Ocircle.move(velocity);

		Ocircle.checkCollisionWithBounds(window.getSize(), velocity);
		std::cout << "exte" << velocity.x << ";" << velocity.y << std::endl;
		Ocircle.Forms->move(velocity);
		//Ocircle.checkCollisionWithRect(rectanglesVector, velocity);
		//DRAW
	    window.clear();

		window.draw(*Ocircle.Forms);
	  //  window.draw(*oRect1.Forms);
		//window.draw(oRect2.rectangle);
		//window.draw(oRect3.rectangle);
		/*
		draw oRect1
		draw oRect2
		draw oCircle1
		*/

		

		//sf::FloatRect rectangle(100, 150, 100, 50);
		//sf::FloatRect rectangle2(500, 500, 100, 50);
		//sf::FloatRect rectangle3(300, 700, 100, 50);
		//sf::FloatRect rectangle4(900, 850, 100, 50);
		//sf::FloatRect rectangle5(200, 600, 100, 100);


		//std::vector<sf::FloatRect> rectanglesVector;
		//rectanglesVector.push_back(oRect1);
		//rectanglesVector.push_back(rectangle2);
		//rectanglesVector.push_back(rectangle3);
		//  rectanglesVector.push_back(rectangle4);
		//rectanglesVector.push_back(rectangle5);

		//circle.move(velocity);
		//circle.checkCollisionWithBounds(window.getSize(), velocity);
		//circle.checkCollisionWithRect(rectanglesVector, velocity);

		//window.clear();
		//for (const sf::FloatRect& rect : rectanglesVector) {
		//	sf::RectangleShape rectangle;
		//	rectangle.setSize(sf::Vector2f(rect.width, rect.height));
		//	rectangle.setPosition(rect.left, rect.top);
		//	window.draw(rectangle);
		//}
		//window.draw(circle.cir);
		window.display();
	}
	// window.draw(Quads);
	return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <stdlib.h>
#include "GameObject.h"
#include "GameManager.h"
#include "brique.h"

void rectanglesEtCercleEnMouvement(sf::RenderWindow& window) {
	std::vector<sf::FloatRect> rectangles;
	const int numRectangles = 20;
	const int rectangleSize = 40;
	const int xSpacing = 60;
	const int ySpacing = 60;
	const int initialX = 300;
	const int initialY = 100;

	for (int i = 0; i < numRectangles; ++i) {
		sf::RectangleShape rect(sf::Vector2f(rectangleSize, rectangleSize));
		rect.setPosition(initialX + (xSpacing * i), initialY + (ySpacing * i));
		rectangles.push_back(rect.getGlobalBounds());
	}

	GameObject Circle(0, 0, 10, sf::Vector2f(1.f, 1.f), 5, sf::Color::Red);

	sf::Clock deltaTime;
	float speed = 1;

	int _Fw = 1080;
	int _Fh = 720;
	GameObject Canon(_Fw / 2, _Fh, 25, 75, sf::Color(155, 50, 155, 255));

	GameManager input;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		Canon.rotate(window);

		Circle.updatePosition();
		Circle.checkCWB(window.getSize());
		//Circle.checkCWS(rectangles);
		Circle.draw(window);

		for (const auto& rect : rectangles) {
			sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
			shape.setPosition(rect.left, rect.top);
			window.draw(shape);
		}


		Canon.draw(window);

		window.display();
	}
}

//tentative colisions entres cercles
void rectanglesEtDeuxCerclesEnMouvement(sf::RenderWindow& window) {
	std::vector<sf::FloatRect> rectangles;
	const int numRectangles = 20;
	const int rectangleSize = 40;
	const int xSpacing = 60;
	const int ySpacing = 60;
	const int initialX = 300;
	const int initialY = 100;

	//for (int i = 0; i < numRectangles; ++i) {
	//    sf::RectangleShape rect(sf::Vector2f(rectangleSize, rectangleSize));
	//    rect.setPosition(initialX + (xSpacing * i), initialY + (ySpacing * i));
	//    rectangles.push_back(rect.getGlobalBounds());
	//}

	std::vector<sf::FloatRect> cerles;
	GameObject Circle1(0, 0, 20, sf::Vector2f(1.f, 1.f), 10, sf::Color::Red);
	GameObject Circle2(300, 600, 15, sf::Vector2f(-1.f, 1.f), 10, sf::Color::Blue);
	GameObject Circle3(700, 200, 10, sf::Vector2f(-1.f, 1.f), 10, sf::Color::Blue);


	const sf::CircleShape& circle1 = Circle1.getCircle();
	const sf::CircleShape& circle2 = Circle2.getCircle();
	const sf::CircleShape& circle3 = Circle3.getCircle();

	//cerles.push_back(circle1.getGlobalBounds());
	cerles.push_back(circle2.getGlobalBounds());
	cerles.push_back(circle3.getGlobalBounds());


	sf::Clock deltaTime;
	float speed = 5;

	std::vector<sf::FloatRect> circles;
	// rectangles.push_back(circle1.getGlobalBounds());
	// rectangles.push_back(circle1.getGlobalBounds());


	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		// Circle1.checkCircleCollisions(bounds1, bounds2);
		 //Circle1.checkCircleCollisions(bounds1, bounds3);
		 //Circle2.checkCircleCollisions(bounds1, bounds3);

		Circle1.updatePosition();
		Circle2.updatePosition();
		Circle3.updatePosition();

		Circle1.checkCWB(window.getSize());
		//Circle1.checkCWS(rectangles);
		//Circle1.checkCircleCollisions(cerles);

		Circle2.checkCWB(window.getSize());
		// Circle2.checkCWS(rectangles, cerles);

		Circle3.checkCWB(window.getSize());
		// Circle3.checkCWS(rectangles, cerles);




		Circle1.draw(window);
		Circle2.draw(window);
		Circle3.draw(window);

		//for (const auto& rect : rectangles) {
		//    sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
		//   shape.setPosition(rect.left, rect.top);
		//    window.draw(shape);
	  // }

		window.display();
	}
}

//grille 
void drawHalfGrid(sf::RenderWindow& window) {

	Brique grille;
	grille.createBrique(window);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		grille.drawGrille(window);
		window.display();
	}
}

void HP(sf::RenderWindow& window) {

	GameObject Canon(1080 / 2, 720, 25, 75, sf::Color(96, 96, 96, 255)); // Construis le canon
	GameObject Barillé1(1080 / 2, 720, 20, 85, sf::Color(255, 0, 0, 255)); // Construis le canon
	GameObject Barillé2(1080 / 2, 720, 3, 75, sf::Color(255, 0, 0, 255)); // Construis le canon
	GameObject BaseCI(1080 / 2 - 25, 720 - 30, 25, sf::Vector2f(0, 0), 0, sf::Color(0, 128, 255, 255));// Construis le canon
	GameObject BaseCO(1080 / 2 - 20, 720 - 25, 20, sf::Vector2f(0, 0), 0, sf::Color(32, 32, 32, 255));// Construis le canon

	Brique grille;
	std::vector<sf::FloatRect> _grille = grille.createBrique(window);

	GameObject Circle(Canon.getEndX(), Canon.getEndY(), 10, sf::Vector2f(-1.f, -1.f), 10, sf::Color::Red);

	GameManager gameManager;
	bool ball = false;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				if (!ball)
				{
					float angleRadians = Canon.Forms->getRotation() * 3.14159265358979323846 / 180.0;
					Circle.setDirection(sf::Vector2f(cos(angleRadians), sin(angleRadians)));
					Circle.Forms->setPosition(Canon.getEndX() - 10, Canon.getEndY() - 20);
					ball = true;
				}
			}
		}

		window.clear();

		//affichage grille
		grille.drawGrille(window);

		//rotation Canon
		Canon.rotate(window);
		Barillé1.rotate(window);
		Barillé2.rotate(window);

		//affichage canon
		BaseCI.draw(window);
		Barillé1.draw(window);
		Canon.draw(window);
		BaseCO.draw(window);
		Barillé2.draw(window);

		//affichage balle
		if (ball == true)
		{
			Circle.updatePosition();
		}
		Circle.draw(window);
		Circle.checkCWB(window.getSize());
	
		//mise à jour grille
		grille.deleteBrique(window, _grille, Circle);

		window.display();
	}
}

/*
void balleClass(sf::RenderWindow& window) {
	Brique grille;
	grille.createBrique(window);

	Balle balle(0, 0, 10, sf::Vector2f(1.f, 1.f), 5, sf::Color::Red);
	std::vector<sf::FloatRect> rectanglesInCollision;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		grille.deleteBrique(window, rectanglesInCollision);

		balle.updatePosition();
		balle.checkCWB(window.getSize());
		balle.draw(window);

		window.display();
	}
}*/



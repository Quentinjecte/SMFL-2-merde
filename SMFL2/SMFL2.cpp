#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "GameObject.h"




//temporaire
/*struct GameObjects {
	sf::RectangleShape rectangle;
	sf::FloatRect collider;
	

	GameObjects(sf::Vector2f size, sf::Vector2f position) {
		rectangle.setSize(size);
		rectangle.setPosition(position);
		collider = rectangle.getGlobalBounds();
	}

	void move(const sf::Vector2f& velocity) {
		rectangle.move(velocity);
		collider = rectangle.getGlobalBounds();
	}
};*/
//temporaire

int main()
{
	int _h = 150;
	int _w = 50;
	//sf::Style::Fullscreen;
	sf::RenderWindow window(sf::VideoMode(1080, 1080), "SFML works!");
	window.setFramerateLimit(60); //Windows
	//sf::RectangleShape rectangle(sf::Vector2f(_h, _w));
	//rectangle.setFillColor(sf::Color(125, 0, 0, 200));

   // rectangle.setOutlineThickness(10); // Size out line
   // rectangle.setOutlineColor(sf::Color(145, 0, 0, 200)); // color out line
	//sf::Mouse::setPosition(sf::Vector2i(_h / 2, _w / 2));
	//rectangle.setPosition(0, 0);

	//sf::Transform t;
	//t.translate(10, 10);

	//std::cout << sf::Mouse::getPosition().x << " ; " << sf::Mouse::getPosition().y;


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // sf::VertexArray Quads(sf::Quads, 4);

	// on définit la position des sommets du triangle
	//Quads[0].position = sf::Vector2f(700, 700);
	//Quads[1].position = sf::Vector2f(700, 800);
	//Quads[2].position = sf::Vector2f(800, 800);
	//Quads[3].position = sf::Vector2f(800, 700);

	// on définit la couleur des sommets du triangle
	//Quads[0].color = sf::Color::Red;
   // Quads[1].color = sf::Color::Blue;
   // Quads[2].color = sf::Color::Red;
	//Quads[3].color = sf::Color::Blue;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//sf::CircleShape octagon(80.f,6); -------------- Size + Form
	//octagon.setFillColor(sf::Color::White); -------------- Color
	//octagon.setPosition(50,50);-------------- Position


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	GameObjects object1(sf::Vector2f(100, 50), sf::Vector2f(100, 100));
	GameObjects object2(sf::Vector2f(80, 50), sf::Vector2f(100, 200));


	GameObjects windowRect(sf::Vector2f(1080, 1080), sf::Vector2f(0, 0));
	*/
	


		GameObject circle;
		circle.drawcircle(30);
		circle.setPosition(100, 50);
		sf::Vector2f velocity(2.0f, 1.0f);  // Vitesse initiale du cercle

		std::vector<sf::FloatRect> rectanglesVector;
		sf::FloatRect rect1(100, 200, 50, 50);  
		sf::FloatRect rect2(300, 400, 60, 60); 
		rectanglesVector.push_back(rect1);
		rectanglesVector.push_back(rect2);

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// Mettez à jour la position du cercle en fonction de sa vitesse
			circle.move(velocity);

			// Vérifiez les collisions avec les bords de la fenêtre
			circle.checkCollisionWithBounds(window.getSize());
	
			circle.move(velocity);
			// Vérifiez les collisions avec les rectangles
			/*for (const sf::FloatRect& rect : rectanglesVector) {
				if (circle.checkCollisionWithRect(rect)) {
					// Réagissez à la collision avec le rectangle
					// Par exemple, inversez la direction du cercle
					velocity.x = -velocity.x;
					velocity.y = -velocity.y;
				}
			}*/

			window.clear();

			// Dessinez les rectangles
			for (const sf::FloatRect& rect : rectanglesVector) {
				sf::RectangleShape rectangle;
				rectangle.setSize(sf::Vector2f(rect.width, rect.height));
				rectangle.setPosition(rect.left, rect.top);
				window.draw(rectangle);
			}

			// Dessinez le cercle
			window.draw(circle.getCircle());
			window.display();
		}

		return 0;
	}

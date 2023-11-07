#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>




//temporaire
struct GameObjects {
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
};
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

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	GameObjects object1(sf::Vector2f(100, 50), sf::Vector2f(100, 100));
	GameObjects object2(sf::Vector2f(80, 80), sf::Vector2f(100, 200));


	GameObjects windowRect(sf::Vector2f(1080, 1080), sf::Vector2f(0, 0));

	sf::Vector2f velocity1(1.0f, 0.0f); // Vecteur de déplacement du premier rectangle
	sf::Vector2f velocity2(0.0f, -2.0f); // Vecteur de déplacement du deuxième rectangle










	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//sf::CircleShape octagon(80.f,6); -------------- Size + Form
	//octagon.setFillColor(sf::Color::White); -------------- Color
	//octagon.setPosition(50,50);-------------- Position

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			//object1.move(velocity1);
			object2.move(velocity2);

			sf::Vector2f object2Position = object2.rectangle.getPosition();
			if (object2.collider.intersects(object1.collider)) {


				//sf::Vector2f velocity2(0.0f, 1.0f);
				//object2.move(velocity2);
				velocity2 = -velocity2;
				printf("Coucou \n");
			}

			else if (!windowRect.collider.contains(object2Position))//object2.collider.intersects(windowRect.getGlobalBounds()))
			{
				velocity2 = -velocity2;
				printf("coucou 2 \n");

			}
			window.clear();
			window.draw(object1.rectangle);
			window.draw(object2.rectangle);
			window.display();

		}


		// rectangle.setRotation(sf::Mouse::getPosition().x); //--------------- Rotate

		 //rectangle.setPosition(sf::Mouse::getPosition().x - 428, sf::Mouse::getPosition().y - 31);// ------------ Mouse Position rect

		// window.draw(rectangle);
		// window.draw(Quads);

		 //window.draw(octagon);



		 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






	}

	return 0;

}
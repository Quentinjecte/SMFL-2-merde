#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "GameObject.h"
#include <stdlib.h>
#include "GameManager.h"
#include "test.h"

int main()
{

    // Initialisation de sprite, texture, velocity, acceleration, etc.
    //Creation de la fenetre
    sf::RenderWindow window;
    int _Fw = 1080;
    int _Fh = 720;
    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);

    

    //rectanglesEtCercleEnMouvement(window);

    //rectanglesEtDeuxCerclesEnMouvement(window);

    //drawHalfGrid(window);

   HP(window);

    //balleClass(window);

    /*
    GameObject Canon(_Fw / 2, _Fh, 25, 75, sf::Color(155,50,155,255));
    GameObject Rect2(50, 100, 100, 20, sf::Color::Green);

    GameObject Circle(0, 0, 10, sf::Vector2f(1.f, 1.f),sf::Color::Red);
    

    //GameManager input;

    sf::Clock deltaTime;
    
    float speed = 5;
    std::vector<sf::FloatRect> rectangles;
    const int numRectangles = 20;
    const int rectangleSize = 40;
    const int xSpacing = 60; // Espacement horizontal
    const int ySpacing = 60; // Espacement vertical
    const int initialX = 300;
    const int initialY = 100;

    for (int i = 0; i < numRectangles; ++i) {
        sf::RectangleShape rect(sf::Vector2f(rectangleSize, rectangleSize));
        rect.setPosition(initialX + (xSpacing * i), initialY + (ySpacing * i)); // Positionnement
        rectangles.push_back(rect.getGlobalBounds());
    }
    while (window.isOpen())
    {
       

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
       // input.moveCanon(Canon);

        window.clear();
        Circle.updatePosition(deltaTime.getElapsedTime(), speed);
       
        Circle.checkCWB(window.getSize());
        Canon.rotate(window);
        Circle.checkCWS(rectangles);

        Circle.draw(window);
        Canon.draw(window);
        for (const auto& rect : rectangles) {
            sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
            shape.setPosition(rect.left, rect.top);
            window.draw(shape);
        }

        window.display();
        //deltaTime.restart();
    }
    */
    return 0;
}
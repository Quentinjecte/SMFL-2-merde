#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <stdlib.h>
#include "GameObject.h"



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

    GameObject Circle(0, 0, 10, sf::Vector2f(1.f, 1.f), sf::Color::Red);

    sf::Clock deltaTime;
    float speed = 5;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Circle.updatePosition(deltaTime.getElapsedTime(), speed);
        Circle.checkCWB(window.getSize());
        Circle.checkCWS(rectangles);
        Circle.draw(window);

        for (const auto& rect : rectangles) {
            sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
            shape.setPosition(rect.left, rect.top);
            window.draw(shape);
        }

        window.display();
    }
}

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
     //   rect.setPosition(initialX + (xSpacing * i), initialY + (ySpacing * i));
     //   rectangles.push_back(rect.getGlobalBounds());
    //}

    GameObject Circle1(0, 0, 10, sf::Vector2f(1.f, 1.f), sf::Color::Red);
    GameObject Circle2(500, 200, 15, sf::Vector2f(-1.f, 1.f), sf::Color::Blue);
    GameObject Circle3(700, 200, 30, sf::Vector2f(-1.f, 1.f), sf::Color::Blue);

    const sf::CircleShape& circle1 = Circle1.getCircle();
    const sf::CircleShape& circle2 = Circle2.getCircle();
    const sf::CircleShape& circle3 = Circle3.getCircle();

    sf::FloatRect Ccirle1 = circle1.getGlobalBounds();
    sf::FloatRect Ccirle2 = circle2.getGlobalBounds();
    sf::FloatRect Ccirle3 = circle3.getGlobalBounds();

    sf::Clock deltaTime;
    float speed = 5;

    std::vector<sf::FloatRect> circles;
    circles.push_back(Ccirle1);
    circles.push_back(Ccirle2);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        Circle1.checkCircleCollisions(circles);

        Circle1.updatePosition(deltaTime.getElapsedTime(), 5);
        Circle2.updatePosition(deltaTime.getElapsedTime(), 3);
        Circle3.updatePosition(deltaTime.getElapsedTime(), 3);

        Circle1.checkCWB(window.getSize());
        Circle1.checkCWS(rectangles);

        Circle2.checkCWB(window.getSize());
        Circle2.checkCWS(rectangles);

        Circle3.checkCWB(window.getSize());
        Circle3.checkCWS(rectangles);
       

     

        Circle1.draw(window);
        Circle2.draw(window);
        Circle3.draw(window);

        //for (const auto& rect : rectangles) {
       //     sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
      //      shape.setPosition(rect.left, rect.top);
            //window.draw(shape);
      //  }

        window.display();
    }
}



#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "GameObject.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 1080), "SFML works!");
    window.setFramerateLimit(60);

    GameObject circle;
    //circle.getCircleCollider();
    circle.drawcircle(10);
    circle.setPosition(100, 50);

    
    sf::Vector2f velocity(7.0f, 4.0f);

    sf::FloatRect rectangle(100, 150, 100, 50);
    sf::FloatRect rectangle2(500, 500, 100, 50);
    sf::FloatRect rectangle3(300, 700, 100, 50);
    //sf::FloatRect rectangle4(900, 850, 100, 50);
    sf::FloatRect rectangle5(200, 600, 100, 100);
    

   std::vector<sf::FloatRect> rectanglesVector;
   rectanglesVector.push_back(rectangle);
   rectanglesVector.push_back(rectangle2);
   rectanglesVector.push_back(rectangle3);
 //  rectanglesVector.push_back(rectangle4);
   rectanglesVector.push_back(rectangle5);



  


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        circle.move(velocity);
        circle.checkCollisionWithBounds(window.getSize(), velocity);
        circle.checkCollisionWithRect(rectanglesVector, velocity);

        window.clear();
        for (const sf::FloatRect& rect : rectanglesVector) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(rect.width, rect.height));
            rectangle.setPosition(rect.left, rect.top);
            window.draw(rectangle);
        }
        window.draw(circle.getCircle());
        window.display();
    }

    return 0;
}

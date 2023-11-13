#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "./GameObject.h"
#include <stdlib.h>


int main()
{
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    sf::RenderWindow window;
    sf::Event event;

    int _Fw = 1080;
    int _Fh = 720;
    bool y = false;
    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);

    GameObject Rect1(_Fw / 2, _Fh, 25, 75, sf::Color(155,50,155,255));
    GameObject Rect2(50, 100, 100, 20, sf::Color::Green);
    GameObject Circle(Rect1.Forms->getPosition().x, Rect1.Forms->getPosition().y - 75, 10, sf::Color::Red);


    sf::FloatRect coRect1 = Rect1.Forms->getGlobalBounds();
    sf::FloatRect coRect2 = Rect2.Forms->getGlobalBounds();

    std::vector<sf::FloatRect> rectanglesVector;
    rectanglesVector.push_back(coRect1);
    rectanglesVector.push_back(coRect2);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "rentre dedans";
                y = true;
            }
        }

        window.clear();

        Rect1.rotate(window);

        Rect1.draw(window);
        Rect2.draw(window);
        Circle.draw(window);
        Circle.move(window);

        window.display();

    }

    return 0;
}

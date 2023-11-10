#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "GameObject.h"
#include <stdlib.h>


int main()
{
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    sf::RenderWindow window;

    int _Fw = 1080;
    int _Fh = 720;
    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);

    GameObject Rect1(_Fw / 2, _Fh, 25, 75, sf::Color(155,50,155,255));
    GameObject Rect2(50, 100, 100, 20, sf::Color::Green);

    GameObject Circle(0, 0, 10, sf::Color::Red);
    sf::Vector2f velocity(1.0f, 1.0f);

    sf::FloatRect coRect1 = Rect1.Forms->getGlobalBounds();
    sf::FloatRect coRect2 = Rect2.Forms->getGlobalBounds();
    sf::RectangleShape rect;

    std::vector<sf::FloatRect> rectanglesVector;
    rectanglesVector.push_back(coRect1);
    rectanglesVector.push_back(coRect2);
    //GameObject Circle1(500, 500, 50, sf::Color::Yellow);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        Circle.move(velocity);
        Circle.checkCWB(window.getSize(), velocity);
        Rect1.rotate(window);
        Circle.checkCWS(rectanglesVector, velocity);

        Circle.draw(window);
        Rect1.draw(window);
        Rect2.draw(window);

        window.display();

    }

    return 0;
}


//sf::VertexArray Quads(sf::Quads, 4);
//
//Quads[0].position = sf::Vector2f(0, _fh - 20);
//Quads[1].position = sf::Vector2f(0, _fh + 80);
//Quads[2].position = sf::Vector2f(_fw + 80, _fh + 80);
//Quads[3].position = sf::Vector2f(_fw + 80, _fh - 20);

//window.draw(Quads);

//sf::Texture texture;
//if (texture.loadFromFile("./pixil.png")) {
//    rectangle.setTexture(&texture);
//}

//if (timer == 25)
//{
//    Quads[0].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//    Quads[1].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//    Quads[2].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//    Quads[3].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//}
//if (timer == 75)
//{
//    Quads[0].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//    Quads[1].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//    Quads[2].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//    Quads[3].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
//}
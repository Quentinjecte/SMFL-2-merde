#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "./GameObject.h"
#include <stdlib.h>


int main()
{

    int _fw = 1080;
    int _fh = 720;
    int _h = 150;
    int _w = 50;
    sf::RenderWindow window(sf::VideoMode(_fw, _fh), "SFML works!");
    window.setFramerateLimit(60);

    sf::RectangleShape rectangle(sf::Vector2f(_h, _w));
    rectangle.setFillColor(sf::Color(125, 0, 0, 255));
    rectangle.setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color(145, 0, 0, 255));

    sf::Vector2i center(_fw / 2, _fh / 2);
    sf::Mouse::setPosition(center, window);

    rectangle.setPosition(_fw / 2, _fh);
    rectangle.setOrigin(0, _w / 2);




    int timer = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.close();
        }

        // Obtenir la position de la souris
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        // Calculer l'angle entre le centre du rectangle et la position de la souris
        sf::Vector2f rectangleCenter = rectangle.getPosition() + sf::Vector2f(rectangle.getSize().x / 2, 0);
        sf::Vector2f direction = sf::Vector2f(mousePosition) - rectangleCenter;
        float angle = atan2(direction.y, direction.x) * 180 / 3.14159265;

        // Définir la rotation du rectangle en fonction de l'angle
        rectangle.setRotation(angle);

        window.clear();
        window.draw(rectangle);

        if (timer == 100)
        {
            std::cout << "Rotation du rectangle : " << angle << std::endl;
            //std::cout << "Position cursor : " << localPosition.x << " ; " << localPosition.y << std::endl;
            timer = 0;
        }

        timer += 1;

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
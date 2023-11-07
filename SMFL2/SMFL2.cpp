#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "./GameObject.h"
#include <stdlib.h>



//temporaire

//temporaire

int main()
{

    int _fw = 720;
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

    rectangle.setPosition(_fw / 2 ,_fh);
    rectangle.setOrigin(0, _w/2);

    sf::VertexArray Quads(sf::Quads, 4);

    Quads[0].position = sf::Vector2f(0, 700);
    Quads[1].position = sf::Vector2f(0, 800);
    Quads[2].position = sf::Vector2f(800, 800);
    Quads[3].position = sf::Vector2f(800, 700);



    int timer = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        // Obtenir la position de la souris
        float angle = static_cast<float>(sf::Mouse::getPosition().y); // Convertir la position X de la souris en un angle

        rectangle.setRotation(angle); // Définir la rotation du rectangle en fonction de l'angle

        window.clear();
        window.draw(Quads);
        window.draw(rectangle);
        if (timer == 25)
        {
            Quads[0].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
            Quads[1].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
            Quads[2].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
            Quads[3].color = sf::Color(rand() % 255, rand() % 255, rand() % 255, 255);
            timer = 0;
        }
        if (timer == 100)
        {
            std::cout << "Rotation du rectangle : " << angle << std::endl;
            timer = 0;
        }

        timer += 1;

        window.display();
    }

    return 0;
}

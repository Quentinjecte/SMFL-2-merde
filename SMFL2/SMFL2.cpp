#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "./GameObject.h"
#include <stdlib.h>


int main()
{
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    sf::RenderWindow window;

    int _Fw = 1080;
    int _Fh = 720;
    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);

    GameObject oRect1(_Fw / 2, _Fh, 75, 25, sf::Color::Red);
    //GameObject oRect2(50, 100, 100, 20, sf::Color::Green);
    //GameObject oRect3(100, 200, 100, 20, sf::Color::Green);
    GameObject oCircle1(500, 500, 50, sf::Color::Yellow);

    while (window.isOpen())
    {
        //
        //EVENT

        // si on utilise la fleche vers le haut
        //oRect1.move(0,-1);

        //UPDATE
        //si oRect1.collide(oRect2)
        //on affiche : collision !

        //DRAW
        window.clear();
        //oRect1.draw(window);
        //window.draw(oCircle1.circle);
        oRect1.draw(window);
        oCircle1.draw(window);
        //window.draw(oRect2.rectangle);
        //window.draw(oRect3.rectangle);
        /*
        draw oRect1
        draw oRect2
        draw oCircle1
        */

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
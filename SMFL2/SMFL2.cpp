#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "GameObject.h"
#include <stdlib.h>
#include "GameManager.h"
#include "test.h"

int main()
{
    srand(time(0));
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    //Creation de la fenetre
    sf::RenderWindow window;
    int _Fw = 1080;
    int _Fh = 720;
    bool ball = false;
    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);

    //rectanglesEtCercleEnMouvement(window);

    //rectanglesEtDeuxCerclesEnMouvement(window);

    //drawHalfGrid(window);

    HP(window);
    //debugBrique(window);
    
    //GameObject Canon(_Fw / 2, _Fh, 25, 75, sf::Color(155,50,155,255)); // Construis le canon
    //GameObject Rect2(50, 100, 100, 20, sf::Color::Green);
    //GameObject Circle(Canon.getEndX(), Canon.getEndY(), 10, sf::Vector2f(-1.f, -1.f), 10, sf::Color::Red);


    //while (window.isOpen())
    //{

    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        if (event.type == sf::Event::Closed)
    //            window.close();
    //            
    //        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    //        {
    //            if (!ball)
    //            {
    //                float angleRadians = Canon.Forms->getRotation() * 3.14159265358979323846 / 180.0;
    //                Circle.setDirection(sf::Vector2f(cos(angleRadians), sin(angleRadians)));
    //                Circle.Forms->setPosition(Canon.getEndX() - 10, Canon.getEndY() - 20);
    //                ball = true;
    //            }
    //        }
    //    }

    //    

    //        window.clear();

    //        Canon.rotate(window);
    //        Canon.draw(window);

    //        if (ball == true)
    //        {
    //            Circle.updatePosition();
    //        }

    //        Circle.draw(window);
    //        Rect2.draw(window);
    //        Circle.checkCWB(window.getSize()); 

    //        window.display();
    //}
    
    return 0;

}
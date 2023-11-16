#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "GameObject.h"
#include <stdlib.h>
#include "GameManager.h"
#include "Ball.h"

int main()
{
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    //Creation de la fenetre
    sf::RenderWindow window;
    int _Fw = 1080;
    int _Fh = 720;
    bool ball = false;
    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);
    //drawHalfGrid(window);
    HP(window);
    //Design canon
    GameObject Canon(_Fw / 2, _Fh, 25, 75, sf::Color(96,96,96,255)); // Construis le canon
    GameObject Barillé1(_Fw / 2, _Fh, 20, 85, sf::Color(255,0,0,255)); // Construis le canon
    GameObject Barillé2(_Fw / 2, _Fh, 3, 75, sf::Color(255,0,0,255)); // Construis le canon
    GameObject BaseCI(_Fw / 2 - 25, _Fh- 30, 25, sf::Vector2f(0, 0), 0, sf::Color(50, 120, 250, 255));// Construis le canon
    GameObject BaseCO(_Fw / 2 - 20, _Fh - 25, 20, sf::Vector2f(0, 0), 0, sf::Color(32, 32, 32, 255));// Construis le canon

    GameObject Rect2(50, 100, 100, 20, sf::Color::Green);

    Ball Bullet(Canon.getEndX(), Canon.getEndY(), 10, sf::Vector2f(-1.f, -1.f), 10, sf::Color::Red);

    //GameObject Rect2(50, 100, 100, 20, sf::Color::Green);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                if (!ball)
                {
                    float angleRadians = Canon.Forms->getRotation() * 3.14159265358979323846 / 180.0;
                    Bullet.setDirection(sf::Vector2f(cos(angleRadians), sin(angleRadians)));
                    Bullet.Forms->setPosition(Canon.getEndX() - 10, Canon.getEndY() - 20);
                    ball = true;
                }
            }
        }

    //    window.clear();

    //    Canon.rotate(window);
    //    Barillé1.rotate(window);
    //    Barillé2.rotate(window);

    //    BaseCI.draw(window);
    //    Barillé1.draw(window);
    //    Canon.draw(window);
    //    BaseCO.draw(window);
    //    Barillé2.draw(window);

        if (ball == true)
        {
            Bullet.updatePosition();
        }

        Bullet.DrawB(window);

        Rect2.draw(window);
        //Bullet.Teasing();

    //    window.display();
    //}
    
    return 0;

}
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "GameManager.h"
#include "Ball.h"
#include "Brique.h"

int main()
{
    sf::RenderWindow window;
    int _Fw = 1080;
    int _Fh = 720;
    window.create(sf::VideoMode(_Fw, _Fh), "SFML Window");
    window.setFramerateLimit(60);

    // GameManager
    GameManager Master;

    // Cr�ation du canon
    GameObject Canon(_Fw / 2, _Fh, 25, 75, sf::Color(96, 96, 96, 255)); // Construis le canon
    GameObject Barill�1(_Fw / 2, _Fh, 20, 85, sf::Color(255, 0, 0, 255)); // Construis le canon
    GameObject Barill�2(_Fw / 2, _Fh, 3, 75, sf::Color(255, 0, 0, 255)); // Construis le canon
    GameObject BaseCI(_Fw / 2 - 25, _Fh - 30, 25, sf::Vector2f(0, 0), 0, sf::Color(50, 120, 250, 255));// Construis le canon
    GameObject BaseCO(_Fw / 2 - 20, _Fh - 25, 20, sf::Vector2f(0, 0), 0, sf::Color(32, 32, 32, 255));// Construis le canon

    // Cr�ation des briques
    Master.createGrilles(window);

    // Cr�ation de la balle
    Ball Bullet(Canon.getEndX(), Canon.getEndY(), 10, sf::Vector2f(-1.f, -1.f), 10, sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
                if (!Bullet.Bullet)
                {
                    float angleRadians = Canon.Forms->getRotation() * 3.14159265358979323846 / 180.0;
                    Bullet.setDirection(sf::Vector2f(cos(angleRadians), sin(angleRadians)));
                    Bullet.Forms->setPosition(Canon.getEndX() - 10, Canon.getEndY() - 20);
                    Bullet.Bullet = true;
                }
            }
        }

        window.clear();

        Canon.rotate(window);

        // D�placement du canon
        Canon.rotate(window);
        Barill�1.rotate(window);
        Barill�2.rotate(window);

        BaseCI.draw(window);
        Barill�1.draw(window);
        Canon.draw(window);
        BaseCO.draw(window);
        Barill�2.draw(window);

        Master.moveRL(Canon);

        if (Bullet.Bullet)
        {
            Bullet.updatePosition();

            // Gestion des collisions avec les briques et les bords
            int collisionType = Master.checkCWS(Bullet, window);

            // Mettez � jour la derni�re collision dans la balle
            Bullet.setLastCollisionType(collisionType);

            // Gestion des collisions avec les briques
            Master.handleBriqueCollision(Bullet, Master.getBriques());
            Bullet.collisionSide(window);

            // V�rification si la balle est sortie de l'�cran ou a touch� une brique
            if (collisionType == 4)
            {
                std::cout << "Collision!" << std::endl;
            }
        }


        // Dessiner les briques
        Master.drawGrille(window);

        // Dessiner le canon et la balle
        Bullet.DrawB(window);

        window.display();
    }

    return 0;
}

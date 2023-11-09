#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "./GameObject.h"
#include <stdlib.h>


int main()
{
    GameObject gameObj;
    //std::cout << GameObject::_Fh

    while (gameObj.getWindow().isOpen())
    {
        while (gameObj.getWindow().isOpen())
        {
            gameObj.handleEvents();

            // Reste du code...
        }


        gameObj.getWindow().clear();
        gameObj.getWindow().draw();

        //if (timer == 100)
        //{
        //    std::cout << "Rotation du rectangle : " << angle << std::endl;
        //    //std::cout << "Position cursor : " << localPosition.x << " ; " << localPosition.y << std::endl;
        //    timer = 0;
        //}


        gameObj.getWindow().display();
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
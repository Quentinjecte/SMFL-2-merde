#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>

int main()
{
    int _h = 150;
    int _w = 50;
    //sf::Style::Fullscreen;
    sf::RenderWindow window(sf::VideoMode(1080, 1080), "SFML works!"); //Windows
    sf::RectangleShape rectangle(sf::Vector2f(_h, _w));
    rectangle.setFillColor(sf::Color(125, 0, 0, 200));

    rectangle.setOutlineThickness(10); // Size out line
    rectangle.setOutlineColor(sf::Color(145, 0, 0, 200)); // color out line
    sf::Mouse::setPosition(sf::Vector2i(_h / 2, _w / 2));
    rectangle.setPosition(0, 0);

    //sf::Transform t;
    //t.translate(10, 10);

    std::cout << sf::Mouse::getPosition().x << " ; " << sf::Mouse::getPosition().y;


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    sf::VertexArray Quads(sf::Quads, 4);

    // on définit la position des sommets du triangle
    Quads[0].position = sf::Vector2f(700, 700);
    Quads[1].position = sf::Vector2f(700, 800);
    Quads[2].position = sf::Vector2f(800, 800);
    Quads[3].position = sf::Vector2f(800, 700);

    // on définit la couleur des sommets du triangle
    Quads[0].color = sf::Color::Red;
    Quads[1].color = sf::Color::Blue;
    Quads[2].color = sf::Color::Red;
    Quads[3].color = sf::Color::Blue;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////










    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //sf::CircleShape octagon(80.f,6); -------------- Size + Form
    //octagon.setFillColor(sf::Color::White); -------------- Color
    //octagon.setPosition(50,50);-------------- Position

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        rectangle.setRotation(sf::Mouse::getPosition().x); //--------------- Rotate

        rectangle.setPosition(sf::Mouse::getPosition().x - 428, sf::Mouse::getPosition().y - 31);// ------------ Mouse Position rect

        window.clear();
        window.draw(rectangle);
        window.draw(Quads);

        //window.draw(octagon);
        window.display();
    }

    return 0;
}
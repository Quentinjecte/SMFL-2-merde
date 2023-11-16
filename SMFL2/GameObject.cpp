#include "GameObject.h"
#include <cmath>

GameObject::GameObject()
{
}

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color _color)
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
    Forms->setPosition(_x, _y);
    Forms->setRotation(angle);
    Forms->setFillColor(_color);

    x = _x;
    y = _y;
    w = _w;
    h = _h;

    updateEndPosition();
}

GameObject::GameObject(int _x, int _y, float _r, sf::Vector2f _direction,float _speed, sf::Color _color)
{
    Forms = new sf::CircleShape(_r);

    updateEndPosition();
}

GameObject::~GameObject()
{
    // Lib�ration des ressources, si n�cessaire
    delete Forms;

}

void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(*Forms);
}

void GameObject::updateEndPosition()
{
    endX = x + (w + r) * cos(angle * 3.14159265358979323846 / 180);
    endY = y + (w + r) * sin(angle * 3.14159265358979323846 / 180);
}

void GameObject::move(const sf::Vector2f& direction)
{
    Forms->move(direction);
}

void GameObject::rotate(sf::RenderWindow& window)
{
    //Set the origine
    Forms->setOrigin(0, h / 2);
    //Get la position du cursor
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    // Calculer l'angle entre le centre du rectangle et la position de la souris
    sf::Vector2f rectangleCenter = Forms->getPosition()/* + sf::Vector2f(Forms->getRotation() / 2, 0)*/;
    sf::Vector2f direction = sf::Vector2f(mousePosition) - rectangleCenter;
    angle = atan2(direction.y, direction.x) * 180 / 3.14159265358979323846;
    // Définir la rotation du rectangle en fonction de l'angle
    Forms->setRotation(angle);

    updateEndPosition();
}

int GameObject::checkCWB(const sf::Vector2u& windowSize) {
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = Forms->getPosition();
    sf::Vector2f radius = Forms->getScale();

    // Vérifiez la collision avec les bords de la fenêtre
    if (position.x - radius.x < 0) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        return 1;
    }

    if (position.x + radius.x > windowSize.x - 10)
    {
        return 2;
    }

    if (position.y - radius.y < 0) {
        return 3;
    }

    if (position.y + radius.y > windowSize.y + 30)
    {
        return 4;
    }
    return 0;
}

int GameObject::checkCWS(std::vector<sf::FloatRect>& rectanglesVector)
{
    std::vector<sf::FloatRect> collidedRectangles;
    for (const sf::FloatRect& rect : rectanglesVector)
    {
        if (Forms->getGlobalBounds().intersects(rect))
        {
            collidedRectangles.push_back(rect);
            return 3;
        }
    }
}

const sf::CircleShape& GameObject::getCircle() const {
    return *static_cast<sf::CircleShape*>(Forms);
}

const sf::FloatRect& GameObject::getRect() const {
    return static_cast<sf::RectangleShape*>(Forms)->getGlobalBounds();
}

float GameObject::getEndX() const
{
    return endX;
}

float GameObject::getEndY() const
{
    return endY;
}
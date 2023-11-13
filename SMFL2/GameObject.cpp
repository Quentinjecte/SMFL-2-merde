#include "GameObject.h"
#include <cmath>

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color) // rectangle
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
    Forms->setPosition(_x, _y);
    Forms->setRotation(angle);

    x = _x;
    y = _y;
    w = _w;
    h = _h;

    updateEndPosition();
}

GameObject::GameObject(int _x, int _y, float _r, sf::Vector2f _direction,float _speed, sf::Color ) //Circle
{
    Forms = new sf::CircleShape(_r);
    Forms->setPosition(_x, _y);
    direction = _direction;
    speed = _speed;

    direction = _direction;
    speed = _speed;

    x = _x;
    y = _y;
    r = _r;

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

void GameObject::update(float deltaTime)
{

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

void GameObject::setDirection(const sf::Vector2f& newDirection) {
    direction = newDirection;
}

void GameObject::initCP(sf::FloatRect _canonPos)
{


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

void GameObject::checkCWB(const sf::Vector2u& windowSize) {

    sf::Vector2f position = Forms->getPosition();
    sf::Vector2f radius = Forms->getScale();

    if ((position.x - radius.x < 0 || position.x + radius.x > windowSize.x - 100)) {
        updateDirection(1);

    }
    if (position.y - radius.y < 0 || position.y + radius.y > windowSize.y - 100) {
        updateDirection(2);
    }
}

void GameObject::checkCWS(std::vector<sf::FloatRect>& rectanglesVector)
{

    for (const sf::FloatRect& rect : rectanglesVector)
    {

        if (Forms->getGlobalBounds().intersects(rect))
        {
            updateDirection(3);

        }
    }

}

void GameObject::updatePosition()
{
    sf::Vector2f _move = direction * speed;
    Forms->move(_move);
}

void GameObject::updateDirection(int typeColision)
{

    float incidentAngle = std::atan2(direction.y, direction.x) * (180.0f / 3.14159265f);
    float reflectionAngle = 180.0f - incidentAngle;
    float newRadians = reflectionAngle * (3.14159265f / 180.0f);

    switch (typeColision)
    {
    case 1:
        direction.x = -direction.x;
        break;
    case 2:
        direction.y = -direction.y;
        break;
    case 3:
        direction.x = 7.f * (std::cos(newRadians) + 0.1f);
        direction.y = 4.f * (std::sin(newRadians) + 0.1f);
        break;
    default:
        break;
    }
    Forms->move(direction);
    
}

const sf::CircleShape& GameObject::getCircle() const {
    return *static_cast<sf::CircleShape*>(Forms);
}

//pas fonctionnel 
void GameObject::checkCircleCollisions(std::vector<sf::FloatRect>& cerles)
{
    for (const sf::FloatRect& _cercle : cerles)
    {

        if (Forms->getGlobalBounds().intersects(_cercle))
        {
            updateDirection(3);
            std::cout << "col" << std::endl;

        }
    }
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
#include "GameObject.h"
#include <cmath>

GameObject::GameObject()
{
}

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color)
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

GameObject::GameObject(int _x, int _y, float _r, sf::Vector2f _direction,float _speed, sf::Color _color)
{
    Forms = new sf::CircleShape(_r);
    Forms->setPosition(_x, _y);
    Forms->setFillColor(_color);
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
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = Forms->getPosition();
    sf::Vector2f radius = Forms->getScale();

    // Vérifiez la collision avec les bords de la fenêtre
    if ((position.x - radius.x < 0 || position.x + radius.x > windowSize.x - 10)) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        //direction.x = -direction.x;
        updateDirection(1);

    }
    if (position.y - radius.y < 0 || position.y + radius.y > windowSize.y - 10) {
        updateDirection(2);
    }
}

std::vector<sf::FloatRect> GameObject::checkCWS(std::vector<sf::FloatRect>& rectanglesVector)
{
    std::vector<sf::FloatRect> collidedRectangles;

    //std::cout << rectanglesVector.capacity() << std::endl;

    for (const sf::FloatRect& rect : rectanglesVector)
    {
        if (Forms->getGlobalBounds().intersects(rect))
        {
           // std::cout << "oui" << std::endl;
            collidedRectangles.push_back(rect);
            updateDirection(3);
        }
    }
    //std::cout << collidedRectangles.capacity() << std::endl;
    return collidedRectangles;
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
        direction.x = speed * (std::cos(newRadians));
        direction.y = speed * (std::sin(newRadians));
        break;
    default:
        break;
    }
    Forms->move(direction);
    
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
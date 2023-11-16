#include "Ball.h"

Ball::~Ball()
{
}

Ball::Ball()
{
}

Ball::Ball(int _x, int _y, int _r, sf::Vector2f _direction, float _speed, sf::Color _color) : GameObject(_x, _y, _r, _direction, _speed, _color)
{
    Forms->setPosition(_x, _y);
    Forms->setRotation(angle);
    Forms->setFillColor(_color);
    direction = _direction;
    speed = _speed;

    updateEndPosition();
}

void Ball::DrawB(sf::RenderWindow& window)
{
    window.draw(*Forms);
}

void Ball::collisionSide(sf::RenderWindow& window)
{
    int value = checkCWB(window.getSize());
    switch (value) {
    case 1:
        updateDirection(1);// Collision côté gauche
        std::cout << "Colission base" << std::endl;
        break;
    case 2:
        updateDirection(1);// Collision côté droit
        break;
    case 3:
        updateDirection(2);// Collision côté haut
        break;
    case 4:
        std::cout << "Colission base" << std::endl;// Collision côté bas
        break;
    default:
        // Aucune collision avec les côtés
        break;
    }
}

void Ball::updatePosition()
{
    sf::Vector2f _move = direction * speed;
    Forms->move(_move);
}

void Ball::updateDirection(int typeColision)
{
    //typeColision = checkCWS();
    //float incidentAngle = std::atan2(direction.y, direction.x) * (180.0f / 3.14159265f);
    //float reflectionAngle = 180.0f - incidentAngle;
    //float newRadians = reflectionAngle * (3.14159265f / 180.0f);

    //switch (typeColision)
    //{
    //case 1:
    //    direction.x = -direction.x;
    //    break;
    //case 2:
    //    direction.y = -direction.y;
    //    break;
    //case 3:
    //    direction.x = speed * (std::cos(newRadians));
    //    direction.y = speed * (std::sin(newRadians));
    //    break;
    //default:
    //    break;
    //}
    //Forms->move(direction);

}

void Ball::setDirection(const sf::Vector2f& newDirection)
{
    direction = newDirection;
}

void Ball::Teasing() {
    if (gameObject.Passage == true)
    {
        std::cout << "Fonction fille";
    }
}
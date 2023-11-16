#pragma once

#include "GameObject.h"

// Dans le fichier balle.h
class Ball : public GameObject 
{

private:
    GameObject gameObject;

    sf::Vector2f direction;

    int x, y, r;

    float speed, angle;

public:

    ~Ball();
    Ball();

    Ball(int _x, int _y, int _r, sf::Vector2f _direction, float _speed, sf::Color _color);

    void collisionSide(sf::RenderWindow& window);

    void DrawB(sf::RenderWindow& window);

    void updatePosition();

    void updateDirection(int typeColision);

    void setDirection(const sf::Vector2f& newDirection);

    void Teasing();
    // ... autres membres de la classe
};

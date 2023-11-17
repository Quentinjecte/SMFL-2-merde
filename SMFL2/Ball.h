#pragma once

#include "GameObject.h"

// Dans le fichier balle.h
class Ball : public GameObject 
{

private:
    GameObject& gameObject;

    sf::Vector2f direction;

    int x, y, r;

    float speed, angle;

    int lastCollisionType;

public:

    ~Ball();

    Ball(GameObject& obj);

    Ball(int _x, int _y, int _r, sf::Vector2f _direction, float _speed, sf::Color _color);

    void collisionSide(sf::RenderWindow& window);

    void DrawB(sf::RenderWindow& window);

    void updatePosition();

    void updateDirection(int typeColision);

    void setDirection(const sf::Vector2f& newDirection);

    void Teasing();
  
    void resetPosition();
    void setLastCollisionType(int type);
    int getLastCollisionType() const;
    sf::Vector2f getPosition() const;
    float getRadius() const;
    // ... autres membres de la classe
   

    sf::Vector2f getDirection() const;

};

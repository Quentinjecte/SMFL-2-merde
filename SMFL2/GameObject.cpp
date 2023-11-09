#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    circle.setRadius(0.0f);
    rectangle.setSize(sf::Vector2f(0.0f, 0.0f));

    circleCollider = circle.getGlobalBounds();
    rectangleCollider = rectangle.getGlobalBounds();

    rectanglesVector = rectanglesVector;
    rectanglesVector.push_back(getRectangleCollider());
}

GameObject::~GameObject() {
    // Lib�ration des ressources, si n�cessaire
}

void GameObject::drawcircle(float radius)
{
    circle.setRadius(radius);
    circleCollider = circle.getGlobalBounds();
}

void GameObject::drawrectangle()
{
    rectangle.setSize(size);
  
}

void GameObject::update(float deltaTime)
{
   
}

void GameObject::move(sf::Vector2f& velocity)
{
    circle.move(velocity);
    circleCollider = circle.getGlobalBounds();
    circleCollider.left += velocity.x;
    //circleCollider.top += velocity.y;

}

void GameObject::rotate(float angle)
{
}

void GameObject::checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity) {
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = circle.getPosition();
    float radius = circle.getRadius();
   
    // Vérifiez la collision avec les bords de la fenêtre
    //std::cout <<"avant " << velocity.x << std::endl;
    if ((position.x - radius < 0 || position.x + radius > windowSize.x-100) ) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        //printf("coucou \n");
        velocity.x = -velocity.x;
       // std::cout <<"pendant " << velocity.x << std::endl;
    }
    if (position.y - radius < 0 || position.y + radius > windowSize.y-100) {
        // Collision avec le bord supérieur ou inférieur, inversez la composante y de la vitesse
        velocity.y = -velocity.y;
    }

    // Appliquez la nouvelle position à la balle
    //std::cout << "après " << velocity.x << std::endl;
    circle.move(velocity);

}

void GameObject::checkCollisionWithRect(std::vector<sf::FloatRect>& rectanglesVector, sf::Vector2f& velocity)
{
    for (const sf::FloatRect& rect : rectanglesVector)
    {
        if (circle.getGlobalBounds().intersects(rect))
        {
            float overlapX = circle.getPosition().x - std::max(rect.left, std::min(circle.getPosition().x, rect.left + rect.width));
            float overlapY = circle.getPosition().y - std::max(rect.top, std::min(circle.getPosition().y, rect.top + rect.height));

            if (std::abs(overlapX) < std::abs(overlapY))
            {
                velocity.x = -velocity.x;

                if (overlapX > 0) {
                    circle.move(overlapX, 0);
                }
                else {
                    circle.move(-overlapX, 0);
                }
            }
            else
            {
                velocity.y = -velocity.y;

                if (overlapY > 0) {
                    circle.move(0, overlapY);
                }
                else {
                    circle.move(0, -overlapY);
                }
            }
        }
    }
}

const sf::Vector2f GameObject::getPosition() const {
    return circle.getPosition();
}

void GameObject::setPosition(float x, float y) {
    circle.setPosition(x, y);
}

void GameObject::setPositionRect(float x, float y) {
    position.x = x;
    position.y = y;
    rectangle.setPosition(position);
    rectangleCollider = rectangle.getGlobalBounds();
}

const sf::CircleShape& GameObject::getCircle() const {
    return circle;
}

const sf::RectangleShape& GameObject::getRectangle() const {
    return rectangle;
}

const sf::FloatRect& GameObject::getCircleCollider() const {
    return circleCollider;
}

const sf::FloatRect& GameObject::getRectangleCollider() const {
    return rectangleCollider;
}

const std::vector<sf::FloatRect>& GameObject::getRectangleVector() const
{
    return rectanglesVector;
}

float GameObject::getRadius() const {
    return circle.getRadius();
}

void GameObject::setCircle(const sf::CircleShape& newCircle) {
    circle = newCircle;
    circleCollider = circle.getGlobalBounds();
}

const sf::RectangleShape& GameObject::getRectangleShape() const {
    return rectangle;
}


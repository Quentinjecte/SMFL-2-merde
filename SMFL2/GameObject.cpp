#include "GameObject.h"
#include <iostream>

GameObject::GameObject() {
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    circle.setRadius(0.0f);
    circle.setOutlineThickness(10.f);
    circle.setOutlineColor(sf::Color(250, 150, 100));
    rectangle.setSize(sf::Vector2f(0.0f, 0.0f));

   // circleCollider = circle.getGlobalBounds();
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
   // circleCollider = circle.getGlobalBounds();
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
   // circleCollider = circle.getGlobalBounds();
    //circleCollider.left += velocity.x;
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

        float incidentAngle = std::atan2(velocity.y, velocity.x) * (180.0f / 3.14159265f);
        float reflectionAngle = 180.0f - incidentAngle;
        float newRadians = reflectionAngle * (3.14159265f / 180.0f);

        if (circle.getGlobalBounds().intersects(rect))
        {
            velocity.x = 7.f * (std::cos(newRadians)+0.1f);
            std::cout << "velocity " << velocity.x << " cos " << std::cos(newRadians) << std::endl;
            velocity.y = 4.f * (std::sin(newRadians)+0.1f);
            std::cout << "velocity " << velocity.y << " sin " << std::sin(newRadians) << std::endl;
            if (velocity.x < 1)
                velocity.x = 1;
            if (velocity.y < 1)
                velocity.y = 1;
            
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


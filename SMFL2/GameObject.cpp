#include "GameObject.h"

GameObject::GameObject() {
    // Initialisation de sprite, texture, velocity, acceleration, etc.
    circle.setRadius(0.0f);
    rectangle.setSize(sf::Vector2f(0.0f, 0.0f));

    circleCollider = circle.getGlobalBounds();
    rectangleCollider = rectangle.getGlobalBounds();
}

GameObject::~GameObject() {
    // Lib�ration des ressources, si n�cessaire
}

void GameObject::drawcircle(float radius)
{
    circle.setRadius(radius);
    
}

void GameObject::drawrectangle()
{
    rectangle.setSize(size);
}

void GameObject::update(float deltaTime)
{
   
}

void GameObject::move(const sf::Vector2f& velocity)
{
    circle.move(velocity);
    circleCollider.left += velocity.x;
    circleCollider.top += velocity.y;
    rectangleCollider.top += velocity.y;
    rectangleCollider.left += velocity.x;
}

void GameObject::rotate(float angle)
{
}

void GameObject::checkCollisionWithBounds(const sf::Vector2u& windowSize) {
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = circle.getPosition();
    float radius = circle.getRadius();

    // Vérifiez la collision avec les bords de la fenêtre
    if (position.x - radius < 0 || position.x + radius > windowSize.x) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        printf("coucou \n");
        velocity.x = -velocity.x;
    }
    if (position.y - radius < 0 || position.y + radius > windowSize.y) {
        // Collision avec le bord supérieur ou inférieur, inversez la composante y de la vitesse
        velocity.y = -velocity.y;
        printf("coucou1 \n");
    }

    // Appliquez la nouvelle position à la balle
    circle.move(velocity);
}

sf::Vector2f GameObject::getPosition() const {
    return circle.getPosition();
}

void GameObject::setPosition(float x, float y) {
    circle.setPosition(x, y);
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

float GameObject::getRadius() const {
    return circle.getRadius();
}

void GameObject::setCircle(const sf::CircleShape& newCircle) {
    circle = newCircle;
    circleCollider = circle.getGlobalBounds();
}


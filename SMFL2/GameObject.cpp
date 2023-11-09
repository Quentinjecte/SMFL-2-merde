#include "GameObject.h"

GameObject::GameObject() {
    // Initialisation de sprite, texture, velocity, acceleration, etc.

    window.create(sf::VideoMode(_Fw, _Fh), "Ta mere ");
    window.setFramerateLimit(60);

    circle.setRadius(0.0f);
    rectangle.setSize(sf::Vector2f(0.0f, 0.0f));

    circleCollider = circle.getGlobalBounds();
    rectangleCollider = rectangle.getGlobalBounds();
}

GameObject::~GameObject()
{
    // Lib�ration des ressources, si n�cessaire
}

const sf::RenderWindow& GameObject::getWindow() const {
    return window;
}

void GameObject::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            window.close();
    }
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

void GameObject::setVelocity() {
    sf::Vector2f velocity(2.f, 1.f);
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
    rectangle.setPosition(_Fw / 2, _Fh);
    rectangle.setOrigin(0, _w / 2);
    rectangle.setFillColor(sf::Color(125, 0, 0, 255));
    rectangle.setOutlineThickness(10);
    rectangle.setOutlineColor(sf::Color(145, 0, 0, 255));

    // Obtenir la position de la souris
    sf::Vector2i mousePosition = sf::Mouse::getPosition(getWindow());

    // Calculer l'angle entre le centre du rectangle et la position de la souris
    sf::Vector2f rectangleCenter = rectangle.getPosition() + sf::Vector2f(rectangle.getSize().x / 2, 0);
    sf::Vector2f direction = sf::Vector2f(mousePosition) - rectangleCenter;
    angle = atan2(direction.y, direction.x) * 180 / 3.14159265;

    // Définir la rotation du rectangle en fonction de l'angle
    rectangle.setRotation(angle);
}

void GameObject::checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity) {


    // Récupérez la position actuelle de la balle
    sf::Vector2f position = circle.getPosition();
    float radius = circle.getRadius();
    // Vérifiez la collision avec les bords de la fenêtre
    if (position.x - radius < 0 || position.x + radius > windowSize.x) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        //std::cout << "coucou \n";
        velocity.x = -velocity.x;
    }
    if (position.y - radius < 0 || position.y + radius > windowSize.y) {
        // Collision avec le bord supérieur ou inférieur, inversez la composante y de la vitesse
        velocity.y = -velocity.y;
        //std::cout << "coucou 2 \n";
    }
    if (timer == 100) {
        std::cout << velocity.x << " ; " << velocity.y << "\n";
        std::cout << "ICI ET LA \n";
        timer = 0;
    }
    timer += 1;

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


#include "GameObject.h"

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color)
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
    Forms->setPosition(_x, _y);
    Forms->setRotation(angle);
    //circle.setRadius(0.0f);
    //draw();
    //circleCollider = circle.getGlobalBounds();
    //rectangleCollider = rectangle.getGlobalBounds();
}

GameObject::GameObject(int _x, int _y, float _r, sf::Color)
{
    Forms = new sf::CircleShape(_r);
    Forms->setPosition(_x, _y);
    //circle.setRadius(0.0f)
    //draw();
    //circleCollider = circle.getGlobalBounds();
    //rectangleCollider = rectangle.getGlobalBounds();
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

void GameObject::setVelocity() {
    sf::Vector2f velocity(2.f, 1.f);
}


void GameObject::move(const sf::Vector2f& velocity)
{
    Forms->move(velocity);
    circleCollider.left += velocity.x;
    circleCollider.top += velocity.y;
    rectangleCollider.top += velocity.y;
    rectangleCollider.left += velocity.x;
}

void GameObject::rotate(sf::RenderWindow& window)
{
    //Get la position du cursor
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    // Calculer l'angle entre le centre du rectangle et la position de la souris
    sf::Vector2f rectangleCenter = Forms->getPosition() + sf::Vector2f(Forms->getRotation() / 2, 0);
    sf::Vector2f direction = sf::Vector2f(mousePosition) - rectangleCenter;
    angle = atan2(direction.y, direction.x) * 180 / 3.14159265;
    Forms->setOrigin(25 / 2, 0);
    // Définir la rotation du rectangle en fonction de l'angle
    Forms->setRotation(angle);

    std::cout << "Cela rentre dans rotate \n";
}

//void GameObject::handleEvents()
//{
//    sf::Event event;
//    while (window.pollEvent(event))
//    {
//        if (event.type == sf::Event::Closed)
//            window.close();
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//            window.close();
//        rotate();
//    }
//}

void GameObject::checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity) {


    // Récupérez la position actuelle de la balle
    sf::Vector2f position = Forms->getPosition();
    float radius = Forms->getScale().x;
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
    Forms->move(velocity);
}

sf::Vector2f GameObject::getPosition() const {
    return Forms->getPosition();
}

void GameObject::setPosition(float x, float y) {
    Forms->setPosition(x, y);
}

//const sf::CircleShape& GameObject::getCircle() const {
//    return circle;
//}
//
//const sf::RectangleShape& GameObject::getRectangle() const {
//    return rectangle;
//}

const sf::FloatRect& GameObject::getCircleCollider() const {
    return circleCollider;
}

const sf::FloatRect& GameObject::getRectangleCollider() const {
    return rectangleCollider;
}

//float GameObject::getRadius() const {
//    return Forms->getRadius();
//}
//
//void GameObject::setCircle(const sf::CircleShape& newCircle) {
//    Forms = newCircle;
//    circleCollider = circle.getGlobalBounds();
//}

#include "GameObject.h"

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color)
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));

    //circle.setRadius(0.0f);
    draw();
    //circleCollider = circle.getGlobalBounds();
    //rectangleCollider = rectangle.getGlobalBounds();
}

GameObject::GameObject(int _x, int _y, float _r, sf::Color)
{
    //Forms = new sf::CircleShape(sf::Vector2f(_r));

    //circle.setRadius(0.0f)
    //draw();
    //circleCollider = circle.getGlobalBounds();
    //rectangleCollider = rectangle.getGlobalBounds();
}

GameObject::~GameObject()
{
    // Lib�ration des ressources, si n�cessaire
}


void GameObject::draw()
{
    //Set le rect : pos/size/color
    Forms->setPosition(sf::Vector2f(50, 50));
    //Forms->scale(50, 50);
    //Forms->setFillColor(sf::Color(155, 55, 155, 255));

    //circle.getRadius(sf::Vector2f(_radius));
    //circle.setFillColor(sf::Color(155,50,155,255));
    //circle.setPosition(sf::Vector2f(_x, _y));
}

/*
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

void GameObject::rotate()
{
    //Get la position du cursor
    //sf::Vector2i mousePosition = sf::Mouse::getPosition(getWindow());

    // Calculer l'angle entre le centre du rectangle et la position de la souris
    sf::Vector2f rectangleCenter = rectangle.getPosition() + sf::Vector2f(rectangle.getSize().x / 2, 0);
    //sf::Vector2f direction = sf::Vector2f(mousePosition) - rectangleCenter;
    angle = atan2(direction.y, direction.x) * 180 / 3.14159265;

    // Définir la rotation du rectangle en fonction de l'angle
    rectangle.setRotation(angle);

    std::cout << "Cela rentre dans rotate \n";
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

*/
#include "GameObject.h"

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color)
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
    Forms->setPosition(_x, _y);
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

/*
void GameObject::update(float deltaTime)
{

}

void GameObject::setVelocity() {
    sf::Vector2f velocity(2.f, 1.f);
}

*/
void GameObject::move(const sf::Vector2f& velocity)
{
    Forms->move(velocity);
    //circleCollider.left += velocity.x;
    //circleCollider.top += velocity.y;
    //rectangleCollider.top += velocity.y;
    //rectangleCollider.left += velocity.x;
}
/*
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
*/
void GameObject::checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity) {
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = Forms->getPosition();
    sf::Vector2f radius = Forms->getScale();

    float incidentAngle = std::atan2(velocity.y, velocity.x) * (180.0f / 3.14159265f);
    float reflectionAngle = 180.0f - incidentAngle;
    float newRadians = reflectionAngle * (3.14159265f / 180.0f);
   
    // Vérifiez la collision avec les bords de la fenêtre
    //std::cout <<"avant " << velocity.x << std::endl;
    if ((position.x - radius.x < 0 || position.x + radius.x > windowSize.x-100) ) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        velocity.x = -velocity.x;
       // std::cout <<"pendant " << velocity.x << std::endl;
    }
    if (position.y - radius.y < 0 || position.y + radius.y > windowSize.y-100) {
        // Collision avec le bord supérieur ou inférieur, inversez la composante y de la vitesse
        velocity.y = -velocity.y;
    }
    //std::cout << "après " << velocity.x << std::endl;
    std::cout << velocity.x << ";" << velocity.y << std::endl;
    Forms->move(velocity);

}

/*void GameObject::checkCollisionWithRect(std::vector<GameObject>& rectanglesVector, sf::Vector2f& velocity)
{
    for (const sf::FloatRect& rect : rectanglesVector)
    {
        
        float incidentAngle = std::atan2(velocity.y, velocity.x) * (180.0f / 3.14159265f);
        float reflectionAngle = 180.0f - incidentAngle;
        float newRadians = reflectionAngle * (3.14159265f / 180.0f);

        if (Forms->getGlobalBounds().intersects(rect))
        {
            velocity.x = 7.f * (std::cos(newRadians) + 0.1f);
            std::cout << "velocity " << velocity.x << " cos " << std::cos(newRadians) << std::endl;
            velocity.y = 4.f * (std::sin(newRadians) + 0.1f);
            std::cout << "velocity " << velocity.y << " sin " << std::sin(newRadians) << std::endl;
            if (velocity.x < 1)
                velocity.x = 1;
            if (velocity.y < 1)
                velocity.y = 1;

        }
    }
}*/
/*
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
#include "GameObject.h"

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color)
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
    Forms->setPosition(_x, _y);
    Forms->setRotation(angle);

}

GameObject::GameObject(int _x, int _y, float _r, sf::Color)
{
    Forms = new sf::CircleShape(_r);
    Forms->setPosition(_x, _y);
    Forms->setOrigin(_r, _r); // Mettez l'origine au centre du cercle
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

void GameObject::move(sf::RenderWindow& window)
{
    // Get la position du cursor
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    // Calculer la direction entre le centre du rectangle et la position de la souris
    direction = sf::Vector2f(mousePosition) - Forms->getPosition();
    // Normaliser la direction pour avoir une longueur de 1
    direction = direction / sqrt(direction.x * direction.x + direction.y * direction.y);
    // Définir la nouvelle position du cercle en fonction de la direction
    Forms->setPosition(Forms->getPosition() + direction * speed); // 'speed' est une constante que vous pouvez ajuster
}

void GameObject::initCP(sf::RenderWindow& window)
{
    // Positionner le cercle au bout du rectangle en prenant en compte la rotation
    sf::FloatRect rectangleSize = Forms->getGlobalBounds(); // Remplacez par la méthode appropriée pour obtenir la taille du rectangle
    Forms->setOrigin(0, rectangleSize.height / 2);  // Ajustez selon l'origine de votre rectangle
    sf::Vector2f circlePosition = Forms->getPosition() + sf::Vector2f(rectangleSize.height * cos(angle * 3.14159265358979323846 / 180),
        rectangleSize.height * sin(angle * 3.14159265358979323846 / 180));
    Forms->setOrigin(0, 0);  // Rétablissez l'origine à son état initial
    Forms->setPosition(circlePosition);
}

void GameObject::rotate(sf::RenderWindow& window)
{
    //Set the origine
    Forms->setOrigin(0, 25 / 2);
    //Get la position du cursor
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    // Calculer l'angle entre le centre du rectangle et la position de la souris
    sf::Vector2f rectangleCenter = Forms->getPosition();

    direction = sf::Vector2f(mousePosition) - rectangleCenter;
    angle = atan2(direction.y, direction.x) * 180 / 3.14159265358979323846;

    std::cout << angle;
    // Définir la rotation du rectangle en fonction de l'angle
    Forms->setRotation(angle);
}

void GameObject::checkCWB(const sf::Vector2u& windowSize, sf::Vector2f& velocity) 
{
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = Forms->getPosition();
    sf::Vector2f radius = Forms->getScale();

    float incidentAngle = std::atan2(velocity.y, velocity.x) * (180.0f / 3.14159265f);
    float reflectionAngle = 180.0f - incidentAngle;
    float newRadians = reflectionAngle * (3.14159265f / 180.0f);

    // Vérifiez la collision avec les bords de la fenêtre
    if ((position.x - radius.x < 0 || position.x + radius.x > windowSize.x - 10)) {
        // Collision avec le bord gauche ou droit, inversez la composante x de la vitesse
        velocity.x = -velocity.x;
    }
    if (position.y - radius.y < 0 || position.y + radius.y > windowSize.y - 10) {
        // Collision avec le bord supérieur ou inférieur, inversez la composante y de la vitesse
        velocity.y = -velocity.y;
    }

    //std::cout << velocity.x << ";" << velocity.y << std::endl;
    Forms->move(velocity);
}

void GameObject::checkCWS(std::vector<sf::FloatRect>& rectanglesVector, sf::Vector2f& velocity)
{

    for (const sf::FloatRect& rect : rectanglesVector)
    {

        float incidentAngle = std::atan2(velocity.y, velocity.x) * (180.0f / 3.14159265f);
        float reflectionAngle = 180.0f - incidentAngle;
        float newRadians = reflectionAngle * (3.14159265f / 180.0f);

        if (Forms->getGlobalBounds().intersects(rect))
        {
            velocity.x = std::cos(newRadians) + 1.f;
            //std::cout << "velocity " << velocity.x << " cos " << std::cos(newRadians) << std::endl;
            velocity.y = std::sin(newRadians) + 1.f;
            //std::cout << "velocity " << velocity.y << " sin " << std::sin(newRadians) << std::endl;
            if (velocity.x < 1)
                velocity.x = 1;
            if (velocity.y < 1)
                velocity.y = 1;

        }
    }

}
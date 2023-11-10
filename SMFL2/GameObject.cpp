#include "GameObject.h"

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color)
{

    Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
    Forms->setPosition(_x, _y);


}

GameObject::GameObject(int _x, int _y, float _r, sf::Color)
{
    Forms = new sf::CircleShape(_r);
    Forms->setPosition(_x, _y);
}

GameObject::~GameObject()
{
    // Lib�ration des ressources, si n�cessaire
}

void GameObject::draw(sf::RenderWindow& window)
{
    window.draw(*Forms);

}

void GameObject::move(const sf::Vector2f& velocity)
{
    Forms->move(velocity);
}

void GameObject::checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity) {
    // Récupérez la position actuelle de la balle
    sf::Vector2f position = Forms->getPosition();
    sf::Vector2f radius = Forms->getScale();


   
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

void GameObject::checkCollisionWithRect(std::vector<sf::FloatRect>& rectanglesVector, sf::Vector2f& velocity)
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
    
}
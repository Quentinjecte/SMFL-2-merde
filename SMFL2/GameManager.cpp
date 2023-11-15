#include "./GameManager.h"



void GameManager::moveRL(GameObject& gameObject) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
 
        gameObject.move(sf::Vector2f(-1.0f, 0.0f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        gameObject.move(sf::Vector2f(1.0f, 0.0f));
    }
} 

bool GameManager::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

std::vector<sf::FloatRect> GameManager::balleColisionBrique(GameObject balle, std::vector<sf::FloatRect> grillesBriques) //return tableau de brique
{
    Brique brique;
    std::vector<sf::FloatRect> collidedRectangles = balle.checkCWS(grillesBriques);
    return collidedRectangles;
}
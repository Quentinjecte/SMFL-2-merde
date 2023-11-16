#include "./GameManager.h"


GameManager::~GameManager()
{
}

GameManager::GameManager()
{
}

void GameManager::moveRL(GameObject& gameObject) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
 
        gameObject.move(sf::Vector2f(-1.0f, 0.0f));
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        gameObject.move(sf::Vector2f(1.0f, 0.0f));
    }
} 

bool GameManager::isKeyPressed(sf::Keyboard::Key key) 
{
    return sf::Keyboard::isKeyPressed(key);
}

bool GameManager::isButtonPressed(sf::Mouse::Button but )
{
    return sf::Mouse::isButtonPressed(but);
    
}

void GameManager::BulletColisionBrique(Ball Bullet, std::vector<sf::FloatRect> grillesBriques)
{
    Brique brique;
    int collidedRectangles = checkCWS(grillesBriques);
}

int GameManager::checkCWS(std::vector<sf::FloatRect>& rectanglesVector)
{
    std::vector<sf::FloatRect> collidedRectangles;
    for (const sf::FloatRect& rect : rectanglesVector)
    {
        if (ball.Forms->getGlobalBounds().intersects(rect))
        {
            collidedRectangles.push_back(rect);
            return 3;
        }
    }
}

void GameManager::createGrilles(sf::RenderWindow& window)
{
    srand(time(0));

    const int NBligne = window.getSize().y / (Brique::sizeY + Brique::ecartY);
    const int NBcol = window.getSize().x / (Brique::sizeX + Brique::ecartX);

    for (int i = 0; i < NBligne; ++i)
    {
        for (int y = 0; y < NBcol; ++y)
        {
            int j = rand() % 10 + 0;
            if (j < 5)
            {
                brique.createBrique();
                //Brique brique(y * (Brique::sizeX + Brique::ecartX), i * (Brique::sizeY + Brique::ecartY), sf::Color::Red, 2);
                briques.push_back(brique);
            }
        }
    }
}

void GameManager::drawGrille(sf::RenderWindow& window)
{
    for (const auto& brique : briques)
    {
        brique.drawB(window);

    }
}


#include "./GameManager.h"


GameManager::~GameManager()
{
}

GameManager::GameManager() : Bullet(0, 0, 0, sf::Vector2f(0, 0), 0, sf::Color::Transparent)
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

bool GameManager::isButtonPressed(sf::Mouse::Button but)
{
    return sf::Mouse::isButtonPressed(but);

}

void GameManager::BulletColisionBrique(Ball Bullet, std::vector<sf::FloatRect> grillesBriques)
{
    Brique brique;
    //int collidedRectangles = checkCWS();
}

int GameManager::checkCWS(const Ball& bullet, sf::RenderWindow& window)
{
    for (const Brique& brique : briques)
    {
        if (bullet.getRect().intersects(brique.getRect()))
        {
            // G�rer la collision avec la brique
            const_cast<Brique&>(brique).handleCollision();
            Bullet.setLastCollisionType(3);
            return 3; // Collision avec une brique
        }
    }

    // V�rifier si la balle touche les bords de la fen�tre
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2f bulletPos = Bullet.getPosition();

    if (bulletPos.x < 0 || bulletPos.x > windowSize.x || bulletPos.y < 0 || bulletPos.y > windowSize.y)
    {
        Bullet.setLastCollisionType(4); // Collision avec les bords
        return 4;
    }

    // Pas de collision avec les briques ou les bords
    return 0;
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
                Brique brique(y * Brique::ecartX, i * Brique::ecartY, Brique::sizeY, Brique::sizeX, 2);
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

void GameManager::handleBriqueCollision(Ball& bullet, const std::vector<Brique>& briques)
{
    for (const Brique& brique : briques)
    {
        if (bullet.getRect().intersects(brique.getRect()))
        {
            // G�rer la collision avec la brique
            // Utilisez les m�thodes appropri�es de GameObject et Brique pour effectuer les changements n�cessaires

            // Vous pouvez �galement utiliser const_cast si n�cessaire pour enlever la constante
            const_cast<Brique&>(brique).handleCollision();
        }
    }
}

void GameManager::destroyBrique(Brique& brique, std::vector<Brique>& briques)
{
    auto it = std::find(briques.begin(), briques.end(), brique);
    if (it != briques.end())
    {
        briques.erase(it);
    }
}

//void GameManager::destroyBall(Ball& ball)
//{
//    // Vous pouvez ajouter ici un code suppl�mentaire pour g�rer la destruction de la balle
//    // Par exemple, remettre � z�ro la position ou effectuer d'autres actions n�cessaires
//    ball.resetPosition();  // Vous devez cr�er une fonction resetPosition() dans la classe Ball
//}

const std::vector<Brique>& GameManager::getBriques() const
{
    return briques;
}


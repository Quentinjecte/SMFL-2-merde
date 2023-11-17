#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Ball.h"
#include "brique.h"


class GameManager
{
private:
    Ball Bullet;
    Brique* brique;  // Utilisez un pointeur vers Brique au lieu de l'objet direct
    std::vector<Brique> briques;

public:
    ~GameManager();
    GameManager();

    void moveRL(GameObject& Canon);
    bool isKeyPressed(sf::Keyboard::Key key);
    bool isButtonPressed(sf::Mouse::Button but);
    void BulletColisionBrique(Ball Bullet, std::vector<sf::FloatRect> grillesBriques);
    void checkCWB(const sf::RenderWindow& windowSize, Ball bullet);
    int checkCWS(const Ball& bullet, sf::RenderWindow& window);
    
 
   
    void createGrilles(sf::RenderWindow& window);
    void drawGrille(sf::RenderWindow& window);
    void handleBriqueCollision(Ball& bullet, const std::vector<Brique>& briques);
    void destroyBrique(Brique& brique, std::vector<Brique>& briques);
    //void destroyBall(Ball& ball);
    const std::vector<Brique>& getBriques() const;
};

#pragma once

#include "GameObject.h"


class Brique : public GameObject {
private:



    std::vector<sf::FloatRect> rectanglesVector;

    int hp;

    std::vector<Brique> _brique;



public:
    static const int sizeX = 50;
    static const int sizeY = 20;
    static const int ecartX = 75;
    static const int ecartY = 45;

    Brique();  // Constructeur pour initialiser la grille
    Brique(int _x, int _y, int _h, int _w, int _hp);

    void createBrique(int _x, int _y, int _h, int _w);

    void drawB(sf::RenderWindow& window) const;

    //void deleteBrique(sf::RenderWindow& window, std::vector<sf::FloatRect> rectanglesInCollision, GameObject balle);

    sf::Color couleurHP(int hp);
    void setHP(int newHP);

    int getHp() const;

    void updateColor();

    void decrementHp(int amount);



    void handleCollision();

    bool operator==(const Brique& other) const;

    //void destroy(GameManager& gameManager, std::vector<Brique>& briques);

};
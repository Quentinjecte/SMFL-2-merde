#pragma once

#include "GameObject.h"
#include "GameManager.h"

class Brique : public GameObject {
public:
    Brique();  // Constructeur pour initialiser la grille
    Brique(int _x, int _y, int _h, int _w, sf::Color _color, int _hp);

    std::vector<sf::FloatRect> createBrique(sf::RenderWindow& window);

    void drawGrille(sf::RenderWindow& window); // Fonction pour dessiner la grille
   
    void deleteBrique(sf::RenderWindow& window, std::vector<sf::FloatRect> rectanglesInCollision, GameObject balle);

    sf::Color couleurHP(int hp);
    void setHP(int newHP);

    int getHp() const;

    void decrementHp(int amount);
  
private:
    GameObject balle;
    std::vector<sf::FloatRect> rectanglesVector;
    int hp;
};

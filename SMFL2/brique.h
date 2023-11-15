#pragma once

#include "GameObject.h"


class Brique : public GameObject {
public:
    Brique();  // Constructeur pour initialiser la grille

    void createBrique(sf::RenderWindow& window);

    void drawGrille(sf::RenderWindow& window); // Fonction pour dessiner la grille
   
    void deleteBrique(sf::RenderWindow& window, std::vector<sf::FloatRect> rectanglesInCollision);

    sf::Color couleurHP(int hp);
  
private:
    GameObject balle;
    std::vector<sf::FloatRect> rectanglesVector;
    std::vector<int> hp;
};

#pragma once

#include "GameObject.h"

class Brique : public GameObject {
public:
    Brique();  // Constructeur pour initialiser la grille

    std::vector<sf::FloatRect> createGrilleBrique(sf::RenderWindow& window);

    void drawGrille(sf::RenderWindow& window); // Fonction pour dessiner la grille

    void deleteBrique(std::vector<sf::FloatRect> grillesBriques, sf::RenderWindow& window);

    sf::Color couleurHP(int hp);

    void infiniteMode(sf::RenderWindow& window);
  
    std::vector<sf::FloatRect> rectanglesVector;

private:
    std::vector<int> hp;

    int sizey, sizex;
};

#include "Brique.h"
Brique::Brique()
{

}

Brique::Brique(int _x, int _y, int _h, int _w, sf::Color _color, int _hp) : GameObject(_x, _y, _h, _w, _color), hp(_hp)
{

}

std::vector<sf::FloatRect> Brique::createBrique(sf::RenderWindow& window) {
    // Initialisation de la grille
    srand(time(0));

    const int sizex = 50;
    const int sizey = 20;
    int ecartx = 75;
    int ecarty = 45;

    const int NBligne = window.getSize().y / (sizey + ecarty);
    const int NBcol = window.getSize().x / (sizex + ecartx);

    for (int i = 1; i < NBligne + 1; ++i) {
        for (int y = 1; y < NBcol + 1; ++y) {
            int j = rand() % 10 + 0;

            if (j < 5) {
                int hp = rand() % 5 + 1;
                Brique brique(ecartx * i, ecarty * y, sizey, sizex, couleurHP(hp), hp);
                sf::FloatRect _brique = brique.getRect();
                rectanglesVector.push_back(_brique);
            }
        }
    }
    return rectanglesVector;
}

void Brique::drawGrille(sf::RenderWindow& window) {
    for (const auto& rect : rectanglesVector) {
        sf::RectangleShape shape(sf::Vector2f(rect.width, rect.height));
        shape.setPosition(rect.left, rect.top);
        window.draw(shape);
    }
}

void Brique::deleteBrique(sf::RenderWindow& window, std::vector<sf::FloatRect> grillesBrique, GameObject balle) {
   
    GameManager gameManager;
    std::vector<sf::FloatRect> briqueCollide = gameManager.balleColisionBrique(balle, grillesBrique);
    
    // Identifier les rectangles en collision
    //for (const auto& rect : rectanglesVector) {
    //    for (const auto& rectC : briqueCollide) {
    //        if (rectC == rect) {
    //            rectanglesInCollision.push_back(rect);
    //            break; // Sortir de la boucle interne, le rectangle a été trouvé
    //        }
    //    }
    //}

    for (size_t i = 0; i < briqueCollide.size(); ++i) {
        sf::RectangleShape shape(sf::Vector2f(briqueCollide[i].width, briqueCollide[i].height));
        shape.setPosition(briqueCollide[i].left, briqueCollide[i].top);

        // Change la couleur en fonction des points de vie
        shape.setFillColor(couleurHP(getHp()));
        bool isInCollision = false;
        for (const auto& rectCol : briqueCollide) {
            if (rectCol == briqueCollide[i]) {
                //// Décrémente les points de vie pour toutes les briques
                //if (getHp() > 0) {
                //    
                //    shape.setFillColor(couleurHP(hp[i]));
                //}
                //// Si c'est rouge, détruis
                //if (ptsVie == 1) {
                //    isInCollision = true;
                //    shape.setFillColor(sf::Color::Red);
                //}
                //break;
            }
        }

        if (isInCollision) {
            shape.setPosition(-100, -100);
            rectanglesVector[i].left = -100;
            rectanglesVector[i].top = -100;
        }

        balle.checkCWS(rectanglesVector, balle);
        window.draw(shape);
    }
}

sf::Color Brique::couleurHP(int hp) {
	switch (hp) {
	case 1:
		return sf::Color::Red;
	case 2:
		return sf::Color(255, 165, 0); // Orange
	case 3:
		return sf::Color::Yellow;
	case 4:
		return sf::Color::Blue;
	case 5:
		return sf::Color::Green;
    case 0:
        return sf::Color::White;
	}
}

void Brique::setHP(int newHP) {
    hp = newHP;
}

int Brique::getHp() const {
    return hp;
}

void Brique::decrementHp(int amount) {
    // Vérifiez si la décrémentation ne fait pas descendre hp en dessous de zéro
    hp = std::max(0, hp - amount);
}
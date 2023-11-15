#include "Brique.h"
Brique::Brique()
{
}

std::vector<sf::FloatRect> Brique::createGrilleBrique(sf::RenderWindow& window) {
    // Initialisation de la grille
   
    const int sizex = 50;
    const int sizey = 20;
    int ecartx = 75;
    int ecarty = 35;

    const int NBligne = window.getSize().y / (sizey + ecarty);
    const int NBcol = window.getSize().x / (sizex + ecartx);

    for (int i = 1; i < NBligne + 1; ++i) {
        for (int y = 1; y < NBcol + 1; ++y) {
            int j = rand() % 10 + 0;
			
            if (j < 5) {
				int couleur = rand()%5 + 1;
				GameObject brique(ecartx * i, ecarty * y, sizey, sizex, sf::Color::Red);
				sf::FloatRect _brique = brique.getRect();
				hp.push_back(couleur);
                this->rectanglesVector.push_back(_brique);
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
        //std::cout << shape.getPosition().x << std::endl;
    }
}

void Brique::deleteBrique(std::vector<sf::FloatRect> grillesBriques, sf::RenderWindow& window) {

    std::vector<sf::FloatRect> rectanglesInCollision;
    // Identifier les rectangles en collision
    for (const auto& rect : rectanglesVector) {
        for (const auto& rectC : grillesBriques) {
            if (rect == rectC) {
                rectanglesInCollision.push_back(rect);
                
                break; // Sortir de la boucle interne, le rectangle a été trouvé
            }
        }
    }

    for (size_t i = 0; i < rectanglesVector.size(); ++i) {
        std::cout << "couleur ?" << std::endl;
        sf::RectangleShape shape(sf::Vector2f(rectanglesVector[i].width, rectanglesVector[i].height));
        shape.setPosition(rectanglesVector[i].left, rectanglesVector[i].top);
        int ptsVie = hp[i];

        // Change la couleur en fonction des points de vie
        shape.setFillColor(couleurHP(ptsVie));

        bool isInCollision = false;
        for (const auto& rectCol : rectanglesInCollision) {
            if (rectCol == rectanglesVector[i]) {
                // Décrémente les points de vie pour toutes les briques
                if (ptsVie > 0) {
                    hp[i] -= 1;
                    shape.setFillColor(couleurHP(hp[i]));
                }
                // Si c'est rouge, détruis
                if (ptsVie == 1) {
                    isInCollision = true;
                    shape.setFillColor(sf::Color::Red);
                }
                break;
            }
        }

        if (isInCollision) {
            shape.setPosition(-200, -200);
            rectanglesVector[i].left = -200;
            rectanglesVector[i].top = -200;
        }
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


//pour après
void Brique::infiniteMode(sf::RenderWindow& window)
{
    srand(time(0));

    const int sizex = 50;
    const int sizey = 20;
    int ecartx = 75;
    int ecarty = 35;

    const int NBligne = window.getSize().y / (sizey + ecarty);
    const int NBcol = window.getSize().x / (sizex + ecartx);

    // Vérifier si la ligne du bas est détruite
        bool isBottomLineDestroyed = true;
    for (int i = 0; i < NBcol; ++i) {
        if (rectanglesVector[i].width != 0 && rectanglesVector[i].height != 0) {
            isBottomLineDestroyed = false;
            break;
        }
    }

    // Si la ligne du bas est détruite, déplacer toutes les lignes d'un cran vers le bas
    if (isBottomLineDestroyed) {
        for (int i = 0; i < NBcol * (NBligne - 1); ++i) {
            rectanglesVector[i] = rectanglesVector[i + NBcol];
        }

        // Ajouter une nouvelle ligne en haut
        for (int i = NBcol * (NBligne - 1); i < NBcol * NBligne; ++i) {
            int j = rand() % 10 + 0;
            if (j < 5) {
                int couleur = rand() % 5 + 1;
                GameObject brique(ecartx * (i % NBcol), ecarty * (i / NBcol), sizey, sizex, sf::Color::Red);
                sf::FloatRect _brique = brique.getRect();
                hp.push_back(couleur);
                rectanglesVector[i] = _brique;
            }
        }
    }
}
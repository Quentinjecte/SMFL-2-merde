#include "Brique.h"


Brique::Brique()
{

}

Brique::Brique(int _x, int _y, int _h, int _w, int _hp)
	: GameObject(_x, _y, _h, _w, couleurHP(_hp)), hp(_hp)
{
}

void Brique::createBrique(int _x, int _y, int _h, int _w)
{
	hp = rand() % 6;  

	sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(Forms);

	if (rectangle)
	{
		rectangle->setSize(sf::Vector2f(_w, _h));
		rectangle->setPosition(_x, _y);

		// Utilisez couleurHP pour définir la couleur en fonction des points de vie
		rectangle->setFillColor(couleurHP(hp));
		std::cout << hp << std::endl;
	}
	else
	{
		// Gestion d'erreur si Forms n'est pas une sf::RectangleShape
		std::cerr << "Erreur : Forms n'est pas une sf::RectangleShape." << std::endl;
	}
}



void Brique::drawB(sf::RenderWindow& window) const
{
	sf::RectangleShape* rectangle = dynamic_cast<sf::RectangleShape*>(Forms);

	if (rectangle)
	{
		window.draw(*rectangle);
	}
	else
	{
		// Gestion d'erreur si Forms n'est pas une sf::RectangleShape
		std::cerr << "Erreur : Forms n'est pas une sf::RectangleShape." << std::endl;
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

void Brique::updateColor()
{
	Forms->setFillColor(couleurHP(hp));
}

void Brique::decrementHp(int amount) {
	// Vérifiez si la décrémentation ne fait pas descendre hp en dessous de zéro
	hp = std::max(0, hp - amount);
}

//void Brique::destroy(GameManager& gameManager, std::vector<Brique>& briques)
//{
//	gameManager.destroyBrique(*this, briques);
//}

bool Brique::operator==(const Brique& other) const
{
	// Comparer les attributs nécessaires pour déterminer l'égalité
	return (hp == other.hp && Forms->getPosition() == other.Forms->getPosition());
}

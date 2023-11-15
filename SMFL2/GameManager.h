#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "brique.h"

class GameManager
{
public:
	void moveRL(GameObject& Canon);
	bool isKeyPressed(sf::Keyboard::Key key);
	std::vector<sf::FloatRect> balleColisionBrique(GameObject balle, std::vector<sf::FloatRect> grillesBriques);
	//std::vector<sf::FloatRect> balleColisionBrique(GameObject balle);
};
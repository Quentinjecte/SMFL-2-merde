#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "brique.h"

class GameManager
{

public:

	void moveRL(GameObject& Canon);

	bool isKeyPressed(sf::Keyboard::Key key);

	bool isButtonPressed(sf::Mouse::Button but);

	std::vector<sf::FloatRect> balleColisionBrique(GameObject balle, std::vector<sf::FloatRect> grillesBriques);

};
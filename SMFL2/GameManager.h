#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class GameManager
{
public:
	void moveRL(GameObject& Canon);
	bool isKeyPressed(sf::Keyboard::Key key);
};
#pragma once
#include "GameObject.h"

class Canon : public GameObject
{
private:

	sf::RectangleShape canon;

	/*GameObject canon;*/

public:

	Canon();
	Canon(int _x, int _y, int _w, int _h, sf::Color _color);

	void DrawC(sf::RenderWindow& window);

};


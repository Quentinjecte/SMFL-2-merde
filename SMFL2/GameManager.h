#pragma once

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "brique.h"
#include "Ball.h"

class GameManager
{
private:

	Ball ball;

	Brique brique;

	std::vector<Brique> briques;
	/*const int sizeX = 50;
	const int sizeY = 20;
	int ecartX = 75;
	int ecartY = 45;*/

public:

	~GameManager();
	GameManager();

	void moveRL(GameObject& Canon);

	bool isKeyPressed(sf::Keyboard::Key key);

	bool isButtonPressed(sf::Mouse::Button but);

	void BulletColisionBrique(Ball Bullet, std::vector<sf::FloatRect> grillesBriques);

	int checkCWS(std::vector<sf::FloatRect>& rectanglesVector);

	//std::vector<sf::FloatRect> createGrilles(sf::RenderWindow& window);
	
	void createGrilles(sf::RenderWindow& window);

	void drawGrille(sf::RenderWindow& window);

	void DrawG(sf::RenderWindow& window);

};
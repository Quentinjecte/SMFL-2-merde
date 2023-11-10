#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
private:
	int x;
	int y;
	int h;
	int w;
	int a, r, g, b;

	sf::Shape* Forms;

	float angle;

	sf::Vector2f velocity;

public:


	GameObject(int _x, int _y, int _h, int _w, sf::Color); //rectangle
	GameObject(int _x, int _y, float _r, sf::Color); //circle
	~GameObject();

	void draw(sf::RenderWindow& window);

	void update(float deltaTime);

	void move(const sf::Vector2f& velocity);

	void rotate(sf::RenderWindow& window);

	void checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity);

	void setVelocity();

};


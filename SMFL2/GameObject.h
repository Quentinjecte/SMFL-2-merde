#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
public:

	int x;
	int y;
	int h;
	int w;
	int a, r, g, b;

	sf::Shape* Forms;

	GameObject(int _x, int _y, int _h, int _w, sf::Color); //rectangle
	GameObject(int _x, int _y, float _r, sf::Color); //circle
	~GameObject();

	void draw(sf::RenderWindow& window);

	void move(const sf::Vector2f& velocity);

	void checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity);

	void checkCollisionWithRect(std::vector<sf::FloatRect>& rectanglesVector, sf::Vector2f& velocity);

protected:

	sf::Vector2f velocity;
};


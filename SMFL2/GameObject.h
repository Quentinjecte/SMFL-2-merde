#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
private:
	int x, y, h, w;

	int a, r, g, b;

	float endX, endY, angle, speed;


	sf::Vector2f direction;

public:
	bool Passage = false;

	sf::Shape* Forms;

	GameObject();
	GameObject(int _x, int _y, int _h, int _w, sf::Color _color); //rectangle
	GameObject(int _x, int _y, float _r, sf::Vector2f _direction,float _speed, sf::Color); //circle
	~GameObject();

	void draw(sf::RenderWindow& window);

	void move(const sf::Vector2f& direction);

	void rotate(sf::RenderWindow& window);

	int checkCWB(const sf::Vector2u& windowSize);

	int checkCWS(std::vector<sf::FloatRect>& rectanglesVector);

	const sf::FloatRect& getRect() const;

	void updateEndPosition();

	const sf::CircleShape& getCircle() const;

	float getEndX() const;
	
	float getEndY() const;	
};


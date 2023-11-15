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

	sf::Shape* Forms;

	GameObject();
	GameObject(int _x, int _y, int _h, int _w, sf::Color); //rectangle
	GameObject(int _x, int _y, float _r, sf::Vector2f _direction,float _speed, sf::Color); //circle
	~GameObject();

	void draw(sf::RenderWindow& window);

	void update(float deltaTime);

	void move(const sf::Vector2f& direction);

	void rotate(sf::RenderWindow& window);

	void checkCWB(const sf::Vector2u& windowSize);

	std::vector<sf::FloatRect> checkCWS(std::vector<sf::FloatRect>& rectanglesVector);

	void updatePosition();

	//void checkCircleCollisions(std::vector<sf::FloatRect>& cerles);

	void setDirection(const sf::Vector2f& newDirection);

	const sf::FloatRect& getRect() const;

	void updateDirection(int typeColision);

	void updateEndPosition();

	const sf::CircleShape& getCircle() const;

	float getEndX() const;
	
	float getEndY() const;
	
};


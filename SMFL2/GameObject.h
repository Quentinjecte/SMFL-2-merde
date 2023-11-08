#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
public:

	int _Fw;
	int _Fh;
	int _h = 75;
	int _w = 25;

	GameObject();
	~GameObject();
	int timer = 0;
	int Mx = 2.f;
	int My = 1.f;



	void drawcircle(float radius);

	void drawrectangle();
	void update(float deltaTime);
	void move(const sf::Vector2f& velocity);
	//void move(const sf::Vector2f& velocity, sf::CircleShape circle, sf::FloatRect collider);
	void rotate(float angle);
	void checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity);


	sf::Vector2f getPosition() const;
	void setPosition(float x, float y);

	const sf::CircleShape& getCircle() const;

	const sf::RectangleShape& getRectangle() const;

	const sf::FloatRect& getCircleCollider() const;

	const sf::FloatRect& getRectangleCollider() const;

	float getRadius() const;

	void setCircle(const sf::CircleShape& newCircle);

	void setVelocity();



protected:

	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::RenderWindow window;

	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f direction;
	sf::Vector2f velocity;

	sf::FloatRect circleCollider; // Colliders pour les formes
	sf::FloatRect rectangleCollider;



};


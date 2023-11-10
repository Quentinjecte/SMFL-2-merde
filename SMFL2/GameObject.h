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

	//void draw();

	void drawcircle(float radius);

	void drawrectangle();
	void update(float deltaTime);
	void move(const sf::Vector2f& velocity);

	//void move(const sf::Vector2f& velocity, sf::CircleShape circle, sf::FloatRect collider);
	void rotate();
	void checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity);

	void checkCollisionWithRect(std::vector<GameObject>& rectanglesVector, sf::Vector2f& velocity);

	

	//void checkCollisionWithRect();
	
	const sf::Vector2f getPosition() const;
	void setPosition(float x, float y);

	const sf::CircleShape& getCircle() const;

	const sf::RectangleShape& getRectangle() const;

	const sf::FloatRect& getCircleCollider() const;

	const sf::FloatRect& getRectangleCollider() const;

	float getRadius() const;

	void setCircle(const sf::CircleShape& newCircle);

	void setVelocity();

	void handleEvents();

protected:


	int timer = 0;
	int Mx = 2.f;
	int My = 1.f;

	float angle;

	sf::Vector2f position;
	sf::Vector2f size;
	sf::Vector2f direction;
	sf::Vector2f velocity;

	sf::FloatRect circleCollider; // Colliders pour les formes
	sf::FloatRect rectangleCollider;

};


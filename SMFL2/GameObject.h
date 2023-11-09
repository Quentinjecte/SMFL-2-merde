#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();

	void drawcircle(float radius);

	void drawrectangle();
	void update(float deltaTime);
	void move( sf::Vector2f& velocity);
	//void move(const sf::Vector2f& velocity, sf::CircleShape circle, sf::FloatRect collider);
	void rotate(float angle);
	void checkCollisionWithBounds(const sf::Vector2u& windowSize, sf::Vector2f& velocity);

	void checkCollisionWithRect(std::vector<sf::FloatRect>& rectanglesVector, sf::Vector2f& velocity);

	//void checkCollisionWithRect();
	
	const sf::Vector2f getPosition() const;
	void setPosition(float x, float y);

	void setPositionRect(float x, float y);

	const sf::CircleShape& getCircle() const;

	const sf::RectangleShape& getRectangle() const;

	const sf::FloatRect& getCircleCollider() const;

	const sf::FloatRect& getRectangleCollider() const;

	float getRadius() const;

	void setCircle(const sf::CircleShape& newCircle);

	const sf::RectangleShape& getRectangleShape() const;

	

	const std::vector<sf::FloatRect>& getRectangleVector() const;

protected:

	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::Vector2f position;
	sf::Vector2f size;

	std::vector<sf::FloatRect> rectanglesVector;

	//sf::Vector2f velocity;
	sf::FloatRect circleCollider; // Colliders pour les formes
	sf::FloatRect rectangleCollider;



};


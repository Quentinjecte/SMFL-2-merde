#pragma once
#include <SFML/Graphics.hpp>

struct Forms {
	sf::RectangleShape rectangle;
	sf::CircleShape circle;
	sf::FloatRect collider;

	Forms(sf::Vector2f size, sf::Vector2f position) {
		rectangle.setSize(size);
		rectangle.setPosition(position);
		collider = rectangle.getGlobalBounds();
	}	

	Forms( float size, sf::Vector2f position) {
		circle.setRadius(size);
		circle.setPosition(position);
		collider = circle.getGlobalBounds();
	}

	void move(const sf::Vector2f& velocity) {
		rectangle.move(velocity);
		collider = rectangle.getGlobalBounds();
	}
};

class GameObject
{
public:
	GameObject();
	~GameObject();


	void update(float deltaTime);
	void move(const sf::Vector2f& velocity);
	void rotate(float angle);
	bool checkCollision(const GameObject& other);

	sf::Vector2f getPosition() const;
	void setPosition(float x, float y);



protected:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
};


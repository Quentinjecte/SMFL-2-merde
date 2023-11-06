#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject();
	~GameObject();


	void draw(sf::RenderWindow& window);
	void update(float deltaTime);
	void move(float x, float y);
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


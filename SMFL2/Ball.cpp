#include "Ball.h"

Ball::~Ball()
{
}

Ball::Ball(GameObject& obj) : GameObject(obj), gameObject(obj)
{
	// Le reste du code du constructeur
	// ...
}

Ball::Ball(int _x, int _y, int _r, sf::Vector2f _direction, float _speed, sf::Color _color)
	: GameObject(_x, _y, _r, _direction, _speed, _color), gameObject(*this)
{
	// Le reste du code du constructeur
	Forms->setPosition(_x, _y);
	Forms->setRotation(angle);
	Forms->setFillColor(_color);
	direction = _direction;
	speed = _speed;

	updateEndPosition();
}

void Ball::DrawB(sf::RenderWindow& window)
{
	window.draw(*Forms);
}

void Ball::collisionSide(sf::RenderWindow& window)
{
	int value = checkCWB(window.getSize());
	switch (value) {
	case 1:
		updateDirection(1);// Collision c�t� gauche
		break;
	case 2:
		updateDirection(1);// Collision c�t� droit
		break;
	case 3:
		updateDirection(2);// Collision c�t� haut
		break;
	case 4:
		std::cout << "Colission base" << std::endl;// Collision c�t� bas
		Fire();
		break;
	default:
		// Aucune collision avec les c�t�s
		break;
	}
}

void Ball::updatePosition()
{
	sf::Vector2f _move = getDirection() * speed;
	Forms->move(_move);
}

void Ball::updateDirection(int typeColision)
{
	// Obtenez la direction actuelle
	switch (typeColision)
	{
	case 1:
		// Collision c�t� gauche ou droit, inversez la composante x de la direction
		direction.x = -direction.x;
		break;
	case 2:
		// Collision c�t� haut, inversez la composante y de la direction
		direction.y = -direction.y;
		break;
	default:
		// Aucune collision avec les c�t�s
		break;
	}

	// Appliquer la nouvelle direction en utilisant la fonction move de GameObject
	move(direction);
}

void Ball::setDirection(const sf::Vector2f& newDirection)
{
	direction = newDirection;
}

void Ball::Fire()
{
	Bullet = false;
}

void Ball::setLastCollisionType(int type) {
	lastCollisionType = type;
}

int Ball::getLastCollisionType() const {
	return lastCollisionType;
}

sf::Vector2f Ball::getPosition() const
{
	// Utilisez la fonction getPosition de la forme (Forms) pour obtenir la position actuelle
	return Forms->getPosition();
}

sf::Vector2f Ball::getDirection() const {
	return direction;
}
#include "GameObject.h"
#include <cmath>

GameObject::GameObject()
{
}

GameObject::GameObject(int _x, int _y, int _h, int _w, sf::Color _color)
{

	Forms = new sf::RectangleShape(sf::Vector2f(_w, _h));
	Forms->setPosition(_x, _y);
	Forms->setRotation(angle);
	Forms->setFillColor(_color);

	x = _x;
	y = _y;
	w = _w;
	h = _h;

	updateEndPosition();
}

GameObject::GameObject(int _x, int _y, float _r, sf::Vector2f _direction, float _speed, sf::Color _color)
{
	Forms = new sf::CircleShape(_r);
	Forms->setPosition(_x, _y);
	Forms->setFillColor(_color);
	direction = _direction;
	speed = _speed;

	direction = _direction;
	speed = _speed;

	x = _x;
	y = _y;
	r = _r;

	updateEndPosition();


}

GameObject::~GameObject()
{
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(*Forms);
}

void GameObject::update(float deltaTime)
{

}

void GameObject::updateEndPosition()
{
	endX = x + (w + r) * cos(angle * 3.14159265358979323846 / 180);
	endY = y + (w + r) * sin(angle * 3.14159265358979323846 / 180);
}

void GameObject::move(const sf::Vector2f& direction)
{
	Forms->move(direction);
}

void GameObject::setDirection(const sf::Vector2f& newDirection) {
	direction = newDirection;
}

void GameObject::rotate(sf::RenderWindow& window)
{
	//Set the origine
	Forms->setOrigin(0, h / 2);
	//Get la position du cursor
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	// Calculer l'angle entre le centre du rectangle et la position de la souris
	sf::Vector2f rectangleCenter = Forms->getPosition()/* + sf::Vector2f(Forms->getRotation() / 2, 0)*/;
	sf::Vector2f direction = sf::Vector2f(mousePosition) - rectangleCenter;
	angle = atan2(direction.y, direction.x) * 180 / 3.14159265358979323846;
	// Définir la rotation du rectangle en fonction de l'angle
	Forms->setRotation(angle);

	updateEndPosition();
}

void GameObject::checkCWB(const sf::Vector2u& windowSize) {
	// Récupérez la position actuelle de la balle
	sf::Vector2f position = Forms->getPosition();
	sf::Vector2f radius = Forms->getScale();

	// Vérifiez la collision avec les bords de la fenêtre
	if ((position.x - radius.x < 0 || position.x + radius.x > windowSize.x - 10)) {
		updateDirection(1);

	}
	if (position.y - radius.y < 0 || position.y + radius.y > windowSize.y - 10) {
		updateDirection(0);
	}
}

std::vector<sf::FloatRect> GameObject::checkCWS(std::vector<sf::FloatRect>& rectanglesVector, GameObject balle)
{
	//float ballCenterX = balle.getCircle().getPosition().x;
	//float ballCenterY = balle.getCircle().getPosition().y;
	//float ballRadius = balle.getCircle().getRadius();
	//std::vector<sf::FloatRect> collidedRectangles;
	//for (const sf::FloatRect& rect : rectanglesVector)
	//{
	//	// Récupérez les coordonnées et dimensions du rectangle
	//	float xtopleft = rect.left;
	//	float ytopleft = rect.top;
	//	float width = rect.width;
	//	float height = rect.height;

	//	// Calculer les coordonnées des côtés du rectangle
	//	float xbottomleft = xtopleft + width;
	//	float ybottomleft = ytopleft + height;

	//	// Vérifier chaque côté du rectangle pour la collision en tenant compte du rayon de la balle
	//	if (ballCenterX + ballRadius > xtopleft && ballCenterX - ballRadius < xbottomleft &&
	//		ballCenterY + ballRadius > ytopleft && ballCenterY - ballRadius < ybottomleft) {
	//		// La balle est à l'intérieur du rectangle

	//		// Maintenant, vous pouvez vérifier chaque côté individuellement
	//		if (ballCenterX  < xtopleft) {
	//			// Collision avec le côté gauche du rectangle
	//			updateDirection(2);
	//			collidedRectangles.push_back(rect);
	//		}
	//		else if (ballCenterX > xbottomleft) {
	//			// Collision avec le côté droit du rectangle
	//			updateDirection(3);
	//			collidedRectangles.push_back(rect);
	//		}

	//		if (ballCenterY < ytopleft) {
	//			// Collision avec le côté haut du rectangle
	//			updateDirection(4);
	//			collidedRectangles.push_back(rect);
	//		}
	//		else if (ballCenterY > ybottomleft) {
	//			// Collision avec le côté bas du rectangle
	//			updateDirection(5);
	//			collidedRectangles.push_back(rect);
	//		}
	//	}

	//	/*if (balle.getRect().intersects(left))
	//	{
	//		collidedRectangles.push_back(rect);
	//		updateDirection(3);
	//	}*/
	//}
	//return collidedRectangles;

	std::vector<sf::FloatRect> collidedRectangles;

	//std::cout << rectanglesVector.capacity() << std::endl;

	for (const sf::FloatRect& rect : rectanglesVector)
	{
		if (Forms->getGlobalBounds().intersects(rect))
		{
			// std::cout << "oui" << std::endl;
			collidedRectangles.push_back(rect);
			updateDirection(3);
		}
	}
	//std::cout << collidedRectangles.capacity() << std::endl;
	return collidedRectangles;
}

void GameObject::updatePosition()
{
	sf::Vector2f _move = direction * speed;
	Forms->move(_move);
}

void GameObject::updateDirection(int typeColision)
{
	float incidentAngle = std::atan2(direction.y, direction.x) * (180.0f / 3.14159265f);
	float reflectionAngle = 180.0f - incidentAngle;
	float newRadians = reflectionAngle * (3.14159265f / 180.0f);

	switch (typeColision)
	{
	case 0:
		direction.y = -direction.y;
		break;
	case 1:
		direction.x = -direction.x;
		break;
	case 2:
		// Collision avec le côté gauche
		//direction.x = -std::abs(speed * std::cos(newRadians));
		direction.x = -direction.x;
		break;
	case 3:
		// Collision avec le côté droit
		//direction.x = std::abs(speed * std::cos(newRadians));
		//direction.x = -direction.x;
		direction.x = speed * (std::cos(newRadians));
		direction.y = speed * (std::sin(newRadians));
		break;
	case 4:
		// Collision avec le côté haut
		//direction.y = -std::abs(speed * std::sin(newRadians));
		direction.y = -direction.y;
		break;
	case 5:
		// Collision avec le côté bas
		//direction.y = std::abs(speed * std::sin(newRadians));
		direction.y = -direction.y;
		break;
	default:
		break;
	}

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0)
	{
		direction.x /= length;
		direction.y /= length;
	}

	Forms->move(direction);
}

const sf::CircleShape& GameObject::getCircle() const {
	return *static_cast<sf::CircleShape*>(Forms);
}

const sf::FloatRect& GameObject::getRect() const {
	return static_cast<sf::RectangleShape*>(Forms)->getGlobalBounds();
}

float GameObject::getEndX() const
{
	return endX;
}

float GameObject::getEndY() const
{
	return endY;
}
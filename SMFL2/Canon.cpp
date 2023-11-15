#include "Canon.h"

Canon::Canon()
{
}

Canon::Canon(int _x, int _y, int _w, int _h, sf::Color _color)
{

}

void Canon::DrawC(sf::RenderWindow& window)
{
	window.draw(canon);
}
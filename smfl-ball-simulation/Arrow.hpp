#ifndef ARROW_HPP
#define ARROW_HPP

#include <SFML/Graphics.hpp>

class Arrow {
public:
	Arrow(float length = 100.f, float thickness = 10.f);

	void setPosition(float x, float y);
	void setRotation(float angle);
	void setLength(float length);
	void draw(sf::RenderWindow& window) const;

private:
	sf::RectangleShape shaft;
	sf::ConvexShape head;
	float length;
	float thickness;

	void updateHeadPosition();
};

#endif // ARROW_HPP

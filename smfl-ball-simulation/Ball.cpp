#include "Ball.hpp"

Ball::Ball(float radius, const sf::Color& color) {
	circle.setRadius(radius);
	circle.setFillColor(color);
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(circle);
}

sf::Vector2f Ball::getPosition() {
	return circle.getPosition();
}

void Ball::setPosition(sf::Vector2f pos) {
	circle.setPosition(pos);
}

void Ball::setVelocity(sf::Vector2f velocity) {
	circle.move(velocity);
}
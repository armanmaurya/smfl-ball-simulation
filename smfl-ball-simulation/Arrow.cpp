#include "Arrow.hpp"
#include <cmath> // for cos and sin

Arrow::Arrow(float length, float thickness)
	: shaft(sf::Vector2f(length, thickness)), length(length), thickness(thickness) {
	shaft.setOrigin(0.f, thickness / 2.f);
	shaft.setFillColor(sf::Color::Red);

	head.setPointCount(3);
	head.setPoint(0, sf::Vector2f(20.f, 0.f));
	head.setPoint(1, sf::Vector2f(0.f, -10.f));
	head.setPoint(2, sf::Vector2f(0.f, 10.f));
	head.setFillColor(sf::Color::Red);
}

void Arrow::setPosition(float x, float y) {
	shaft.setPosition(x, y);
	updateHeadPosition();
}

void Arrow::setRotation(float angle) {
	shaft.setRotation(angle);
	head.setRotation(angle);
	updateHeadPosition();
}

void Arrow::setLength(float length) {
	shaft.setSize(sf::Vector2f(length, shaft.getSize().y));
	this->length = length;
	updateHeadPosition();
}

void Arrow::draw(sf::RenderWindow& window) const {
	window.draw(shaft);
	window.draw(head);
}

void Arrow::updateHeadPosition() {
	float angle = shaft.getRotation() * 3.14159f / 180.f; // Convert to radians
	float dx = length * cos(angle);
	float dy = length * sin(angle);
	head.setPosition(shaft.getPosition() + sf::Vector2f(dx, dy));
}

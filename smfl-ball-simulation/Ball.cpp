#include "Ball.hpp"

Ball::Ball(float radius, const sf::Color& color) {
	circle.setRadius(radius);
	circle.setFillColor(color);
	velocity = sf::Vector2f(0.f, 0.f);
	mass = 1.0f; 
	friction = 0.001f;
	threshold = 0.01f;
}

void Ball::draw(sf::RenderWindow& window) {
	circle.move(velocity);
	applyFriction();
	window.draw(circle);
}

sf::Vector2f Ball::getPosition() {
	return circle.getPosition();
}

void Ball::applyFriction() {
	// Calculate the friction force
	sf::Vector2f frictionForce = -friction * velocity;
	// Apply friction to the ball's velocity
	velocity += frictionForce;
	// Check if the velocity is below the threshold, if so, set it to zero
	if (std::abs(velocity.x) < threshold) {
		velocity.x = 0;
	}
	if (std::abs(velocity.y) < threshold) {
		velocity.y = 0;
	}
	std::cout << velocity.x << velocity.y << std::endl;
}

void Ball::setPosition(sf::Vector2f pos) {
	circle.setPosition(pos);
}

void Ball::AddForce(sf::Vector2f force) {
	// Calculate acceleration based on the force and mass
	sf::Vector2f acceleration = force / mass;
	// Update the velocity
	velocity += acceleration;
}

void Ball::setVelocity(sf::Vector2f velocity) {
	circle.move(velocity);
}
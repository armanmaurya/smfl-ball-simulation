#include "Ball.hpp"
#include <cmath>

Ball::Ball(float radius, const sf::Color& color) {
	circle.setRadius(radius);
	circle.setFillColor(color);
	velocity = sf::Vector2f(0.f, 0.f);
	mass = 1.0f; 
	friction = 0.01f;
	threshold = 0.01f;
}

void Ball::draw(sf::RenderWindow& window) {
	sf::Vector2f currentPos = circle.getPosition();

	if (currentPos.x < 0) {
		AddForce(sf::Vector2f(2 * std::abs(velocity.x), 0));
	}
	if (currentPos.x + 60 > window.getSize().x) {
		AddForce(sf::Vector2f(-2 * std::abs(velocity.x), 0));
	}

	if (currentPos.y < 0) {
		AddForce(sf::Vector2f(0, 2 * std::abs(velocity.y)));
	}
	if (currentPos.y + 60 > window.getSize().y) {
		AddForce(sf::Vector2f(0, -2 * std::abs(velocity.y)));
	}
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
	//std::cout << velocity.x << velocity.y << std::endl;
}

bool Ball::checkCollision(const Ball& other) {
	float distance = std::sqrt(std::pow(circle.getPosition().x - other.circle.getPosition().x, 2) +
		std::pow(circle.getPosition().y - other.circle.getPosition().y, 2));
	float combinedRadius = circle.getRadius() + other.circle.getRadius();
	return distance < combinedRadius;
}

void Ball::resolveCollision(Ball& other) {
	if (checkCollision(other)) {
		//other.velocity += velocity;
		
		// Calculate the normalized collision vector
		sf::Vector2f collisionVector = other.getPosition() - getPosition();
		const float magnitude = std::sqrt(std::pow(collisionVector.x, 2) + std::pow(collisionVector.y, 2));
		sf::Vector2f unitVector = collisionVector / magnitude;

		const float velocityMagnitude = std::sqrt(std::pow(velocity.x, 2) + std::pow(velocity.y, 2));

		other.velocity += unitVector * velocityMagnitude;

		//std::cout << unitVector.x << unitVector.y << std::endl;
	}
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
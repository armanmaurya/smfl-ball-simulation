#include "Ball.hpp"
#include <cmath>

Ball::Ball(float radius, const sf::Color& color, float mass = 1.f) {
	circle.setRadius(radius);
	circle.setFillColor(color);
	velocity = sf::Vector2f(0.f, 0.f);
	this->mass = mass; 
	friction = 0.01f;
	threshold = 0.01f;
}

void Ball::draw(sf::RenderWindow& window) {
	sf::Vector2f currentPos = circle.getPosition();
	arrow.setPosition(currentPos.x + circle.getRadius(), currentPos.y + circle.getRadius());
	const float velocityMagnitude = std::sqrt(std::pow(velocity.x, 2) + std::pow(velocity.y, 2));
	arrow.setLength(velocityMagnitude * 5);
	const float angle = std::atan2(velocity.y, velocity.x) * 180.f / 3.14159f;
	arrow.setRotation(angle);

	if (currentPos.x < 0) {
		circle.setPosition(sf::Vector2f(0, currentPos.y));
		this->velocity = sf::Vector2f(-(this->velocity.x), this->velocity.y);
	}
	if (currentPos.x + (2 * circle.getRadius()) > window.getSize().x) {
		circle.setPosition(sf::Vector2f(window.getSize().x - (2 * circle.getRadius()), currentPos.y));
		this->velocity = sf::Vector2f(-(this->velocity.x), this->velocity.y);
	}

	if (currentPos.y < 0) {
		circle.setPosition(sf::Vector2f(currentPos.x, 0));
		this->velocity = sf::Vector2f(this->velocity.x, -(this->velocity.y));
	}
	if (currentPos.y + (2 * circle.getRadius()) > window.getSize().y) {
		circle.setPosition(sf::Vector2f(currentPos.x, window.getSize().y - (2 * circle.getRadius())));
		this->velocity = sf::Vector2f(this->velocity.x, -(this->velocity.y));
	}
	circle.move(velocity);
	applyFriction();
	window.draw(circle);
	if (velocityMagnitude > 0) {
		arrow.draw(window);

	}
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
	float distance = std::sqrt(std::pow((circle.getPosition().x + circle.getRadius()) - (other.circle.getPosition().x + other.circle.getRadius()), 2) +
		std::pow((circle.getPosition().y + circle.getRadius()) - (other.circle.getPosition().y + other.circle.getRadius()), 2));
	float combinedRadius = circle.getRadius() + other.circle.getRadius();
	return distance <= combinedRadius;
}

void Ball::resolveCollision(Ball& other) {
	if (checkCollision(other)) {
		//other.velocity += velocity;
		
		// Calculate the normalized collision vector
		sf::Vector2f collisionVector = other.getPosition() - getPosition();
		const float magnitude = std::sqrt(std::pow(collisionVector.x, 2) + std::pow(collisionVector.y, 2));
		sf::Vector2f unitVector = collisionVector / magnitude;

		//const float velocityMagnitude = std::sqrt(std::pow(velocity.x, 2) + std::pow(velocity.y, 2));
		//other.velocity += unitVector * velocityMagnitude;

		sf::Vector2f ballVelocity = ((mass - other.mass) * velocity + 2 * other.mass * other.velocity)/(mass + other.mass);
		sf::Vector2f otherBallVelocity = ((other.mass - mass) * other.velocity + 2 * mass * velocity)/ (mass + other.mass);

		other.velocity = otherBallVelocity;
		velocity = ballVelocity;
		//std::cout << unitVector.x << unitVector.y << std::endl;
	}
}

void Ball::setPosition(sf::Vector2f pos) {
	circle.setPosition(pos);
}

void Ball::AddForce(sf::Vector2f force) {
	// Calculate acceleration based on the force and mass
	sf::Vector2f acceleration = force / this->mass;
	// Update the velocity
	velocity += acceleration;
}

void Ball::setVelocity(sf::Vector2f velocity) {
	circle.move(velocity);
}


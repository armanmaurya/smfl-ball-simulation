#include "SFML/Graphics.hpp"
#include <iostream>

class Ball {
public:
	Ball(float radius, const sf::Color& color);
	sf::CircleShape circle;
	sf::Vector2f velocity;
	float mass; // Ball's mass for physics calculations
	float friction;
	float threshold; 



	void draw(sf::RenderWindow& window);

	void setVelocity(sf::Vector2f velocity);
	void setPosition(sf::Vector2f pos);
	void AddForce(sf::Vector2f force);
	void applyFriction();
	bool checkCollision(const Ball& other);
	void resolveCollision(Ball& other);
	sf::Vector2f getPosition();
};
#include "SFML/Graphics.hpp"

class Ball {
public:
	Ball(float radius, const sf::Color& color);
	sf::CircleShape circle;
	sf::Vector2f velocity;


	void draw(sf::RenderWindow& window);

	void setVelocity(sf::Vector2f velocity);
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
};
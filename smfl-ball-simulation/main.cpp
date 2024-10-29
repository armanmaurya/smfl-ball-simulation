#include "SFML/Graphics.hpp"
#include "Ball.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Window");
	Ball ball(30., sf::Color::Black);
	window.setFramerateLimit(60);
	float speed = 7.;
	ball.setPosition(sf::Vector2f((window.getSize().x / 2) - 30, (window.getSize().y / 2) - 30));
	
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		sf::Vector2f currentPos = ball.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			speed = 14.;
		}
		else {
			speed = 7.;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && currentPos.y > 0) {
			ball.setVelocity(sf::Vector2f(0., -speed));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (currentPos.y + 60) < window.getSize().y) {
			ball.setVelocity(sf::Vector2f(0., speed));
		} 
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && currentPos.x > 0) {
			ball.setVelocity(sf::Vector2f(-speed, 0.));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (currentPos.x + 60) < window.getSize().x) {
			ball.setVelocity(sf::Vector2f(speed, 0.));
		}

		window.clear(sf::Color::White);
		ball.draw(window);
		window.display();

	}
	return 0;
}
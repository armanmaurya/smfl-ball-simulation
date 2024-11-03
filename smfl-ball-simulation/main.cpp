#include "SFML/Graphics.hpp"
#include "Ball.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Window");
	Ball ball(30., sf::Color::Black);
	Ball ball1(30., sf::Color::Black);
	window.setFramerateLimit(60);
	long speed = 14.f;
	ball.setPosition(sf::Vector2f((window.getSize().x / 2) - 30, (window.getSize().y / 2) - 30));
	ball1.setPosition(sf::Vector2f(300.f, 300.f));
	
	sf::Clock clock;  // Clock to measure time elapsed
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		float deltaTime = clock.restart().asSeconds();

		
		ball.resolveCollision(ball1);
		

		// Get the time elapsed since last frame and restart the clock
		//sf::Vector2f currentPos = ball.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			speed = 14.;
		}
		else {
			speed = 7.;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			ball.AddForce(sf::Vector2f(0., -speed * deltaTime));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			ball.AddForce(sf::Vector2f(0., speed * deltaTime));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			ball.AddForce(sf::Vector2f(-speed * deltaTime, 0.));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			ball.AddForce(sf::Vector2f(speed * deltaTime, 0.));
		}

		/*if (currentPos.x < 0) {
			ball.AddForce(sf::Vector2f(2 * std::abs(ball.velocity.x), 0));
		}
		if (currentPos.x + 60 > window.getSize().x) {
			ball.AddForce(sf::Vector2f(-2* std::abs(ball.velocity.x), 0));
		}

		if (currentPos.y < 0) {
			ball.AddForce(sf::Vector2f(0, 2 * std::abs(ball.velocity.y)));
		}
		if (currentPos.y + 60 > window.getSize().y) {
			ball.AddForce(sf::Vector2f(0, -2 * std::abs(ball.velocity.y)));
		}*/

		window.clear(sf::Color::White);
		ball1.draw(window);
		ball.draw(window);
		window.display();

	}
	return 0;
}
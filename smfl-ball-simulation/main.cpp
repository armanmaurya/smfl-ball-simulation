#include "SFML/Graphics.hpp"
#include "Ball.hpp"


int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Window");
	Ball ball(30., sf::Color::Black, 2.f);
	Ball ball1(30., sf::Color::Black, 2.f);
	window.setFramerateLimit(60);
	float speed;
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
		

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			speed = 14.;
		}
		else {
			speed = 20.;
		}

		//std::cout << speed << std::endl;

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

		window.clear(sf::Color::White);
		ball1.draw(window);
		ball.draw(window);
		window.display();

	}
	return 0;
}




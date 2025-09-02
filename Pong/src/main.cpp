#include "collision_handler.h"
#include "event_handler.h"

#include <iostream>

int main()
{

	const int INITIAL_WIDTH = 1280;
	const int INITIAL_HEIGHT = 720;

	sf::RenderWindow window(sf::VideoMode({ INITIAL_WIDTH, INITIAL_HEIGHT }), "Pong", sf::Style::Default, sf::State::Windowed);
	window.setFramerateLimit(60);

	const float PADDLE_WIDTH = 20.f;
	const float PADDLE_HEIGHT = 140.f;

	Paddle paddleLeft(PADDLE_WIDTH, PADDLE_HEIGHT, 40.f, INITIAL_HEIGHT / 2.5f);
	Paddle paddleRight(PADDLE_WIDTH, PADDLE_HEIGHT, INITIAL_WIDTH - 20.f - 40.f, INITIAL_HEIGHT / 2.5f);

	Ball ball(20, window.getSize().x / 2.f - 20, window.getSize().y / 2.f - 20);

	CollisionHandler collisionHandler(window, ball, paddleLeft, paddleRight);

	bool started = false;

	while (window.isOpen())
	{
		
		EventHandler::handleEvents(window, started);
		EventHandler::handlePaddleMovement(window, paddleLeft, paddleRight);

		if (started) ball.move();

		collisionHandler.handleBallBorderCollision();
		collisionHandler.handleGameEnd(started);
		collisionHandler.handleBallPaddleCollision();

		window.clear(sf::Color::Black);

		window.draw(paddleLeft.getShape());
		window.draw(paddleRight.getShape());
		window.draw(ball.getShape());

		window.display();

	}

	return 0;
}
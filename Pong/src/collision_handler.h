#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include "paddle.h"
#include "ball.h"

class CollisionHandler
{

private:
	const sf::RenderWindow& window;
	Ball& ball;
	Paddle& paddleLeft;
	Paddle& paddleRight;

private:
	const sf::CircleShape& ballShape;
	const sf::RectangleShape& paddleLeftShape;
	const sf::RectangleShape& paddleRightShape;

public:
	CollisionHandler() = delete;
	CollisionHandler(const sf::RenderWindow& window, Ball& ball, Paddle& paddleLeft, Paddle& paddleRight);

	void handleBallBorderCollision();
	void handleBallPaddleCollision();
	void handleGameEnd(bool& started);

};

#endif

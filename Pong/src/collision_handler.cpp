#include "collision_handler.h"

//
// Constructor sets all of the member variables, including the shape versions of them so that
// we can easily access the shapes rather than having to call getShape() every time the game loop runs.
//

CollisionHandler::CollisionHandler(const sf::RenderWindow& window, Ball& ball, Paddle& paddleLeft, Paddle& paddleRight)
	: window(window), ball(ball), paddleLeft(paddleLeft), paddleRight(paddleRight),
	  ballShape(ball.getShape()), paddleLeftShape(paddleLeft.getShape()), paddleRightShape(paddleRight.getShape())
{ }

//
// Checks if the ball has hit the top or bottom border of the window. If it has, it changes the ball's direction.
//

void CollisionHandler::handleBallBorderCollision()
{
	if (ballShape.getPosition().y + (2.f * ballShape.getRadius()) >= 1.f * window.getView().getSize().y ||
		ballShape.getPosition().y <= 0)
	{
		ball.changeDirY();
	}
}

//
// Checks if the ball has hit the face of each of the paddles. The first if statement checks the right paddle.
// The second if statement checks the left paddle. They are split into two if statements to improve readability.
//

void CollisionHandler::handleBallPaddleCollision()
{
	if (ballShape.getPosition().x + 2 * ballShape.getRadius() >= paddleRightShape.getPosition().x &&
		ballShape.getPosition().y + ballShape.getRadius() >= paddleRightShape.getPosition().y &&
		ballShape.getPosition().y + ballShape.getRadius() <= paddleRightShape.getPosition().y + paddleRightShape.getSize().y)
	{
		ball.changeDirX();
		ball.accelerate();
	}

	if (ballShape.getPosition().x <= paddleLeftShape.getPosition().x + paddleLeftShape.getSize().x &&
		ballShape.getPosition().y + ballShape.getRadius() >= paddleLeftShape.getPosition().y &&
		ballShape.getPosition().y + ballShape.getRadius() <= paddleLeftShape.getPosition().y + paddleLeftShape.getSize().y)
	{
		ball.changeDirX();
		ball.accelerate();
	}
}

//
// Checks if the ball has went out of bounds to either the right or left side of the screen.
//

void CollisionHandler::handleGameEnd(bool& started)
{
	if (ballShape.getPosition().x >= window.getView().getSize().x ||
		ballShape.getPosition().x <= -(2 * ballShape.getRadius()))
	{
		started = false;
		ball.resetBall();
		paddleLeft.resetPaddle();
		paddleRight.resetPaddle();
	}
}
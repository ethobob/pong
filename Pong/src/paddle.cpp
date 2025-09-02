#include "paddle.h"

const float Paddle::paddleSpeed = 4;

Paddle::Paddle(const float width, const float height, const float x, const float y)
	: initialX(x), initialY(y)
{
	paddleShape.setFillColor(sf::Color::White);
	paddleShape.setSize({ width, height });
	paddleShape.setPosition({ x, y });
}

const sf::RectangleShape& Paddle::getShape()const
{
	return paddleShape;
}

void Paddle::move(Direction dir)
{
	if (dir == UP)
		paddleShape.move({ 0, -paddleSpeed });
	if (dir == DOWN)
		paddleShape.move({ 0, paddleSpeed });
}

void Paddle::resetPaddle()
{
	paddleShape.setPosition({ initialX, initialY });
}
#include "ball.h"

#include <iostream>

const float Ball::initialSpeed = 3.f;
const float Ball::acceleration = 0.3f;

Ball::Ball(const float radius, const float x, const float y)
	: initialX(x), initialY(y), deltaX(initialSpeed), deltaY(initialSpeed)
{
	ballShape.setFillColor(sf::Color::White);
	ballShape.setRadius(radius);
	ballShape.setPosition({ x, y });
}

const sf::CircleShape& Ball::getShape()const
{
	return ballShape;
}

void Ball::move()
{
	ballShape.move({ deltaX, deltaY });
}

void Ball::resetBall()
{
	ballShape.setPosition({ initialX, initialY });
	deltaX = initialSpeed;
}

void Ball::accelerate()
{
	deltaX += deltaX < 0 ? -acceleration : acceleration;
}

void Ball::changeDirX()
{
	deltaX *= -1;
}

void Ball::changeDirY()
{
	deltaY *= -1;
}
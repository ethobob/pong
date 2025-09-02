#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{

private:
	const float initialX;
	const float initialY;
	float deltaX;
	float deltaY;
	sf::CircleShape ballShape;

private:
	static const float initialSpeed;
	static const float acceleration;

public:
	Ball() = delete;
	Ball(const float radius, const float x, const float y);

	const sf::CircleShape& getShape()const;
	void move();
	void resetBall();
	void accelerate();
	void changeDirX();
	void changeDirY();

};

#endif

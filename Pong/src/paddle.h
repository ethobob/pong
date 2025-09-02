#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle
{

private:
	const float initialX;
	const float initialY;
	sf::RectangleShape paddleShape;

private:
	static const float paddleSpeed;

public:
	static const enum Direction { UP, DOWN };

public:
	Paddle() = delete;
	Paddle(const float width, const float height, const float x, const float y);

	const sf::RectangleShape& getShape()const;
	void move(Direction dir);
	void resetPaddle();

};

#endif

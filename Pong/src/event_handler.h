#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <SFML/Graphics.hpp>

namespace EventHandler
{

	//
	// handleEvents() goes through all of the events that occured between frames and
	// checks if they need to be responded to.
	//

	void handleEvents(sf::RenderWindow& window, bool& started)
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
				{
					window.close();
				}
				if (keyPressed->scancode == sf::Keyboard::Scancode::Space)
				{
					started = true;
				}
			}

		}
	}

	//
	// handlePaddleMovement() checks if either the W, S, Up, or Down keys are being pressed
	// during a given frame. If so, it moves the paddle, but only if the paddle is in bounds.
	//

	void handlePaddleMovement(sf::RenderWindow& window, Paddle& paddleLeft, Paddle& paddleRight)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) && paddleLeft.getShape().getPosition().y > 0)
		{
			paddleLeft.move(Paddle::UP);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) &&
			paddleLeft.getShape().getPosition().y + paddleLeft.getShape().getSize().y < window.getView().getSize().y)
		{
			paddleLeft.move(Paddle::DOWN);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up) && paddleRight.getShape().getPosition().y > 0)
		{
			paddleRight.move(Paddle::UP);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down) &&
			paddleRight.getShape().getPosition().y + paddleRight.getShape().getSize().y < window.getView().getSize().y)
		{
			paddleRight.move(Paddle::DOWN);
		}
	}

}

#endif

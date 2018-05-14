#pragma once
#include <SFML/Graphics.hpp>


class Paddle
{
private:
	//define position of paddle
	sf::Vector2f position;

	//define shape
	sf::RectangleShape paddleShape;

	//speed of paddle
	float paddleSpeed = .3f;

public:
	//constructor of the paddle
	Paddle(float startX, float startY);

	//position of the rectangle
	sf::FloatRect getPosition();

	//returns the shape
	sf::RectangleShape getShape();

	//moving left
	void moveLeft();

	//moving right
	void moveRight();

	//updates frame per second
	void update();








};

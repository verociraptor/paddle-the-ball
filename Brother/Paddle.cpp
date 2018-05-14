//code paddle class
#include "stdafx.h"
#include "Paddle.h"



Paddle::Paddle(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	paddleShape.setSize(sf::Vector2f(50, 5));
	paddleShape.setPosition(position);
}

//gets position of 4 points of rectangle
sf::FloatRect Paddle::getPosition()
{
	return paddleShape.getGlobalBounds();
}

//returns shape of paddle
sf::RectangleShape Paddle::getShape()
{
	return paddleShape;
}

//paddle moves to left according to speed
void Paddle::moveLeft()
{
	position.x -= paddleSpeed;
}

//paddle moves to right according to speed
void Paddle::moveRight()
{
	position.x += paddleSpeed;
}

//updates location of paddle per frame
void Paddle::update()
{
	paddleShape.setPosition(position);
}
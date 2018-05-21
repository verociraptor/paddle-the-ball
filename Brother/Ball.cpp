#include "stdafx.h"
#include "Ball.h"
#include <stdlib.h> 
Ball::Ball(float startX, float startY, Color color)
{
	position.x = startX;
	position.y = startY;

	ballShape.setRadius(20);
	ballShape.setFillColor(color);

}

Ball::Ball()
{}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

CircleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getYVelocity()
{
	return yVelocity;
}

void Ball::update()
{
	position.y += yVelocity + .1;

	ballShape.setPosition(position);
}

void Ball::hitBottom()
{
	position.y = 1;
}


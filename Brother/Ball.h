#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball 
{
private:
	Vector2f position;

	// A RectangleShape object called ref
	CircleShape ballShape;

	
	float yVelocity = .2f;

public:
	Ball(float startX, float startY, Color color);
	Ball();

	FloatRect getPosition();

	CircleShape getShape();

	float getYVelocity();

	void update();

	void hitBottom();

	

};



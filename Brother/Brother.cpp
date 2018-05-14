#include "stdafx.h"
#include "Paddle.h"
#include "Ball.h"
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdlib.h> 
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{

	int windowWidth = 1000;
	int windowHeight = 700;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Waddup, bro");

	int score = 0;
	int lives = 3;
	int MAX_RED = 3;

	
	//int xLocationBall = rand() % (windowWidth - 10) + 10;

	std::vector<Ball> MyBalls;

	for (int i = 0; i < 5; i++)
	{
		Ball temp(rand() % (windowWidth - 10) + 10, -(rand() % 60), Color::Color(255, 215, 0));
		MyBalls.push_back(temp);
	}

	//Ball redBall(xLocationBall, 1, Color::Red);
		
	Text hud;
	Font fontHud;
	fontHud.loadFromFile("ka1.ttf");
	hud.setFont(fontHud);
	hud.setCharacterSize(50);
	hud.setFillColor(Color::White);

	Text display;
	Font fontDisplay;
	fontDisplay.loadFromFile("Beautiful and Openhearted.ttf");
	display.setFont(fontDisplay);
	display.setCharacterSize(40);
	display.setFillColor(Color::White);

	

	Paddle paddle(windowWidth / 2, windowHeight - 100);
	
	
	
	while (window.isOpen())
	{
		/***first handle player input**/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			paddle.moveLeft();
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			paddle.moveRight();
		}
		else if (Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		/**********updating frame***********/

		
		for (int i = 0; i < MyBalls.size(); i++)
		{
		
			if (MyBalls[i].getPosition().top > windowHeight)
			{
				MyBalls[i].hitBottom();
			}
			if (MyBalls[i].getPosition().intersects(paddle.getPosition())) 
			{
				MyBalls.erase(MyBalls.begin() + i);
				lives--;
				if (lives <= 0)
					lives = 3;
			}
		}
		


		for (int i = 0; i < MyBalls.size(); i++)
		{
			MyBalls[i].update();
		}


		paddle.update();

		
		
		

		std::stringstream ss;
		ss << "Score:" << score << "             Lives:" << lives;
		hud.setString(ss.str());

		/*********draw frame*********/
		window.clear();
		
		for (int i = 0; i < MyBalls.size(); i++)
		{
			

			window.draw(MyBalls[i].getShape());
		}
		window.draw(hud);
		window.draw(paddle.getShape());
		window.display();

	}






	return 0;


}
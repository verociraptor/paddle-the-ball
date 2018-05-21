#include "stdafx.h"
#include "Paddle.h"
#include "Ball.h"
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdlib.h> 
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

int main()
{

	int windowWidth = 1000;
	int windowHeight = 700;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Waddup, bro");

	int score = 0;
	int lives = 3;
	int MAX_RED = 3;

	


	std::vector<Ball> MyBalls;

	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Ball temp(rand() % (windowWidth - 40), -(rand() % 800), Color::Color(255, 215, 0));
		MyBalls.push_back(temp);
	}

	std::vector<Ball> MyRedBalls;

	for (int i = 0; i < 5; i++)
	{
		Ball temp(rand() % (windowWidth - 40), -(rand() % 1000), Color::Red);
		MyRedBalls.push_back(temp);
	}

	
		
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
	display.setCharacterSize(80);
	display.setFillColor(Color::White);
	display.setPosition(300, windowHeight / 2);
	

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

		//basically the end of the game
		if (score == 5)
		{
			window.clear();
			std::stringstream ss;
			ss << "You da coolest, WOWZA";
			display.setString(ss.str());
			window.draw(display);

			window.display();
			continue;

		}
			

		//golds balls
		for (int i = 0; i < MyBalls.size(); i++)
		{
		
			//if ball hits bottom, restart at the top
			if (MyBalls[i].getPosition().top > windowHeight)
			{
				MyBalls[i].hitBottom();
			}
			//if ball intersects with paddle, score umps up
			if (MyBalls[i].getPosition().intersects(paddle.getPosition())) 
			{
				MyBalls.erase(MyBalls.begin() + i);
				
				score++;
			}
		}

		//red balls
		for (int i = 0; i < MyRedBalls.size(); i++)
		{
			//if balls hit bottom, restart at top
			if (MyRedBalls[i].getPosition().top > windowHeight)
			{
				MyRedBalls[i].hitBottom();
			}

			//intersects paddle, loses a life
			if (MyRedBalls[i].getPosition().intersects(paddle.getPosition()))
			{
				MyRedBalls.erase(MyRedBalls.begin() + i);

				lives--;
				if (lives <= 0)
				{
					score = 0;
					lives = 3;
				}
					

			}
		}
		

		for (int i = 0; i < MyRedBalls.size(); i++)
		{
			MyRedBalls[i].update();
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

		for (int i = 0; i < MyRedBalls.size(); i++)
		{
			window.draw(MyRedBalls[i].getShape());
		}
		window.draw(hud);
		window.draw(paddle.getShape());
		window.display();

	}



	return 0;


}
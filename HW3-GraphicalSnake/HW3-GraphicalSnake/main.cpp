// HW2-GravitySnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SFML_STATIC
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <conio.h>
#include "Box2D.h"
#include "snake.h"

using namespace std;

//create physics world
b2Vec2 gravity(0.0f, 0.1f);
b2World world(gravity);

//initialize variables
b2BodyDef groundBlockDef;
b2BodyDef bodyDef;
b2Body* body;
b2PolygonShape dynamicBox;
int numTargetsHit = 0;
int numTargets;
char input;
float targetX;
float targetY;
int chck;

//b2Vec2 TargetLocations[];
b2Vec2* currentLocation;

int main()
{

	//add welcome and instructions
	cout << "Welcome to Gravity Snake!" << endl;
	cout << "How to Play:" << endl;
	cout << "WASD to move the snake, try to hit as many targets as possible. Press Esc to end the game early, q to pause, and Space to reverse gravity." << endl;
	cout << "How many targets do you want to play with?" << endl;
	cin >> numTargets;
	setupTargets(numTargets);



	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");


	sf::CircleShape snake(10.0f);
	snake.setFillColor(sf::Color::White);

	sf::RectangleShape target(sf::Vector2f(10.0f, 10.0f));
	target.setFillColor(sf::Color::Green);



	//create ground
	groundBlockDef.position.Set(0.0f, 600.0f);
	b2Body* groundBlock = world.CreateBody(&groundBlockDef);

	//affix box to ground
	b2PolygonShape groundBox;
	groundBox.SetAsBox(3000.0f, 10.0f);
	groundBlock->CreateFixture(&groundBox, 0.0f);


	//create a dynamic body
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	body = world.CreateBody(&bodyDef);

	//affix dynamic box
	dynamicBox.SetAsBox(10.0f, 10.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				window.close();
		}

		
	
	
		//update position and world tick
		update(world);
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();

		//print new position to console
		display(position, angle);
		processInput();

		if (position.y <= currentLocation->y + 7 && position.y >= currentLocation->y - 7 && position.x <= currentLocation->x + 7 && position.x >= currentLocation->x - 7) {
			selectNextTarget();
			numTargetsHit++;
		}

		snake.setPosition(position.x, position.y);
		target.setPosition(currentLocation->x, currentLocation->y);

		window.clear(sf::Color::Black);


		window.draw(snake);
		window.draw(target);

		window.display();
	}
	return 0;

	

}



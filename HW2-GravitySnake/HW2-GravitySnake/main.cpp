// HW2-GravitySnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Box2D.h"
#include <conio.h>
#include "snake.h"

using namespace std;

//create physics world
b2Vec2 gravity(0.0f, -1.0f);
b2World world(gravity);

//initialize variables
b2BodyDef groundBlockDef;
b2BodyDef bodyDef;
b2Body* body;
b2PolygonShape dynamicBox;
int numTargetsHit = 0;
char input;
float targetX;
float targetY;
int chck;

int main()
{
	//set the initial target
	targetX = 0;
	targetY = 3;
	//next target is -4,3

	//add welcome and instructions
	cout << "Welcome to Gravity Snake!" << endl;
	cout << "How to Play:" << endl;
	cout << "WASD to move the snake, try to hit as many targets as possible. Press Esc to end the game early, and q to pause" << endl;
	cout << "Press ENTER to begin" << endl;
	input = _getch();
	


	//create ground
	groundBlockDef.position.Set(0.0f, -10.0f);
	b2Body* groundBlock = world.CreateBody(&groundBlockDef);

	//affix box to ground
	b2PolygonShape groundBox;
	groundBox.SetAsBox(50.0f, 10.0f);
	groundBlock->CreateFixture(&groundBox, 0.0f);


	//create a dynamic body
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	body = world.CreateBody(&bodyDef);

	//affix dynamic box
	dynamicBox.SetAsBox(1.0f, 1.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	body->CreateFixture(&fixtureDef);

	//while the max number of targets hasn't been hit yet
	while (numTargetsHit != 10)
	{
		//update position and world tick
		update(world);
		b2Vec2 position = body->GetPosition();
		float angle = body->GetAngle();

		//print new position to console
		display(position, angle);

		//if a key was pressed
		if (_kbhit()) {

			//set the pressed key as a variable
			input = _getch();

			//if Esc was pressed, break the loop
			if (input == 27) {
				break;
			}
			//if q was pressed, pause until another key is pressed
			else if (input == 'q') {
				_getch();
			}
			//if any other key is pressed, call applyForces
			else {
				applyForces(input);
			}
		}

		//if the snake is in the right position for the target, print out the target was hit, increase the score, and move the target
		if (position.y <= targetY+0.3 && position.y >= targetY-0.3 && position.x <= targetX+0.3 && position.x >= targetX-0.3) {
			cout << "Target Hit!" << endl;
			numTargetsHit++;
			moveTarget(targetX, targetY);
			cout << targetX << endl;
			cout << targetY << endl;
		}

	}

	//inform the player that the game is done, and print out the score
	cout << "Congratulations! You completed the game with a score of " << numTargetsHit << endl;
	cin >> chck;

}



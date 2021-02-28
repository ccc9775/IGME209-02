#include <conio.h>
#include "Box2D.h"
#include "snake.h"


//set the timestep of the world and number of iterations. call the next world step
void update(b2World& world) {

	float timeStep = 1.0f / 3000.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;


	world.Step(timeStep, velocityIterations, positionIterations);

}

//print out the position and angle of the snake to the console
void display(b2Vec2& position, float& angle) {
	printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
}

//add an appropriate force to the specified direction based off of the user's button press
void applyForces(char input) {

	if (input == 119) {
		body->ApplyForceToCenter(b2Vec2(0, 3000), true);
	}
	else if (input == 97) {
		body->ApplyForceToCenter(b2Vec2(-100, 0), true);
	}
	else if (input == 115) {
		body->ApplyForceToCenter(b2Vec2(0, -300), true);
	}
	else if (input == 100) {
		body->ApplyForceToCenter(b2Vec2(100, 0), true);
	}

}

//move the target to a random location between -5 and 5 in the x and 1 and 5 in the y direction
void moveTarget(float& xPos, float& yPos) {

	xPos = (rand() % 10) -5;
	yPos = (rand() % 5) +1;

}


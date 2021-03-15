#define SFML_STATIC
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <conio.h>
#include "Box2D.h"
#include "snake.h"

using namespace std;

b2Vec2 TargetLocations[];

//set the timestep of the world and number of iterations. call the next world step
void update(b2World& world) {

	float timeStep = 1.0f / 60.0f;
	int32 velocityIterations = 6;
	int32 positionIterations = 2;


	world.Step(timeStep, velocityIterations, positionIterations);

}

//print out the position and angle of the snake to the console
void display(b2Vec2& position, float& angle) {
	
	printf("Target %4.2f %4.2f --> Snake %4.2f %4.2f %4.2f\n", currentLocation->x, currentLocation->y, position.x, position.y, angle);
}

//add an appropriate force to the specified direction based off of the user's button press
/*void applyForces(char input) {

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

}*/

void processInput() {
	Key inputBody;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		inputBody = &ApplyForceUp;
		ApplyForceUp((b2Body&)body);
		(*inputBody)((b2Body&)body);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		inputBody = &ApplyForceLeft;
		ApplyForceLeft((b2Body&)body);
		(*inputBody)((b2Body&)body);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		inputBody = &ApplyForceDown;

		(*inputBody)((b2Body&)body);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		inputBody = &ApplyForceRight;
		ApplyForceRight((b2Body&)body);
		(*inputBody)((b2Body&)body);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		inputBody = &StopMoving;
		StopMoving((b2Body&)body);
		(*inputBody)((b2Body&)body);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		ReverseGravity((b2World&)world);
	}

	

}

void ApplyForceUp(b2Body& player) {
	body->ApplyForceToCenter(b2Vec2(0, -100), true);
}
void ApplyForceDown(b2Body& player) {
	body->ApplyForceToCenter(b2Vec2(0, 100), true);
}
void ApplyForceLeft(b2Body& player) {
	body->ApplyForceToCenter(b2Vec2(-10, 0), true);
}
void ApplyForceRight(b2Body& player) {
	body->ApplyForceToCenter(b2Vec2(10, 0), true);
}
void StopMoving(b2Body& player) {
	body->SetLinearVelocity(b2Vec2(0, 0));
}
void ReverseGravity(b2World& world) {
	b2Vec2 newGrav = world.GetGravity();
	world.SetGravity(-newGrav);
}

void setupTargets(int cnt) {

	TargetLocations[cnt];
	for (int i = 0; i < cnt; i++) {
		TargetLocations[i] = b2Vec2((float)((rand() % 600) + 100), (float)((rand() % 400) + 100));
	}
	TargetLocations[cnt] = b2Vec2(-1000, -1000);
	currentLocation = &TargetLocations[0];
}

bool selectNextTarget() {
	currentLocation++;

	if (currentLocation == nullptr) {
		return false;
	}
	else {
		return true;
	}
}
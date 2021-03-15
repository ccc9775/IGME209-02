#pragma once

extern b2World world;
extern b2Body* body;
extern b2Vec2* currentLocation;
extern b2Vec2 TargetLocations[1];
typedef void (*Key)(b2Body&);
extern float targetX;
extern float targetY;


void update(b2World& world);
void display(b2Vec2& position, float& angle);
//void applyForces(char input);
//void moveTarget(float& xPos, float& yPos);

void processInput();

void ApplyForceUp(b2Body& player);
void ApplyForceDown(b2Body& player);
void ApplyForceLeft(b2Body& player);
void ApplyForceRight(b2Body& player);
void StopMoving(b2Body& player);
void ReverseGravity(b2World& world);

void setupTargets(int cnt);

bool selectNextTarget();
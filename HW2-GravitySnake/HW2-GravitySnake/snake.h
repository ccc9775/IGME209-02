#pragma once

extern b2Body* body;
extern float targetX;
extern float targetY;


void update(b2World& world);
void display(b2Vec2& position, float& angle);
void applyForces(char input);
void moveTarget(float& xPos, float& yPos);
#pragma once

void update(b2World& world);
void display(b2Vec2& position, float& angle);
void applyForces(char input, b2Body* snake);
void moveTarget(float& xPos, float& yPos);
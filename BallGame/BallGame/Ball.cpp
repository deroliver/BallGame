#include "Ball.h"



Ball::Ball(float radius, float mass, const glm::vec2& position,
		   const glm::vec2& velocity, unsigned int textureID,
		   const gengine::ColorRGBA8 color) {

	this->radius = radius;
	this->mass = mass;
	this->position = position;
	this->velocity = velocity;
	this->textureID = textureID;
	this->color = color;
}


